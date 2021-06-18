#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

#define PIPE_NAME TEXT("\\\\.\\pipe\\teste")
#define N 10

// estrutura do named pipe
typedef struct {
	HANDLE hPipe; // handle do pipe
	OVERLAPPED overlap;
	BOOL activo; //representa se a instancia do named pipe esta ou nao ativa, se ja tem um cliente ou nao

} PipeDados;

typedef struct {
	PipeDados hPipes[N];
	HANDLE hEvents[N];
	HANDLE hMutex;
	int terminar;
}ThreadDados;

//envia mensagem para todos os leitores que estão disponiveis
DWORD WINAPI ThreadMensagens(LPVOID param) {
	ThreadDados* dados = (ThreadDados*)param;
	TCHAR buf[256];
	DWORD n;
	int i;

	do {
		_tprintf(TEXT("[ESCRITOR] Frase: "));
		_fgetts(buf, 256, stdin);
		buf[_tcslen(buf) - 1] = '\0';


		//escreve no named pipe
		for (i = 0; i < N; i++) {

			//bloqueamos aqui porque é uma regiao critica
			WaitForSingleObject(dados->hMutex, INFINITE);

			// este named pipe está ativo? se sim vou escrever nele
			if (dados->hPipes[i].activo) {
				if (!WriteFile(dados->hPipes[i].hPipe, buf, _tcslen(buf) * sizeof(TCHAR), &n, NULL))
					_tprintf(TEXT("[ERRO] Escrever no pipe! (WriteFile)\n"));
				else
					_tprintf(TEXT("[ESCRITOR] Enviei %d bytes ao leitor [%d]... (WriteFile)\n"), n, i);
			}
			//libertamos o mutex
			ReleaseMutex(dados->hMutex);
		}

	} while (_tcscmp(buf, TEXT("fim")));
	dados->terminar = 1;

	//vou assinalar todos os eventos para que nao fique bloqueado na main
	for (i = 0; i < N; i++)
		SetEvent(dados->hEvents[i]);

	return 0;
}

int _tmain(int argc, LPTSTR argv[]) {

	HANDLE hPipe, hThread, hEventTemp;
	ThreadDados dados;
	int i,numClientes = 0;
	DWORD offset, nBytes;

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	dados.terminar = 0;
	dados.hMutex = CreateMutex(NULL, FALSE, NULL); //Criação do mutex

	if (dados.hMutex == NULL) {
		_tprintf(TEXT("[Erro] ao criar mutex!\n"));
		return -1;
	}


	for (i = 0; i < N; i++) {

		// aqui passamos a constante FILE_FLAG_OVERLAPPED para o named pipe aceitar comunicações assincronas
		hPipe = CreateNamedPipe(PIPE_NAME, PIPE_ACCESS_OUTBOUND | FILE_FLAG_OVERLAPPED,
			PIPE_WAIT | PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE,
			N,
			256 * sizeof(TCHAR),
			256 * sizeof(TCHAR),
			1000,
			NULL);

		if (hPipe == INVALID_HANDLE_VALUE) {
			_tprintf(TEXT("[ERRO] Criar Named Pipe! (CreateNamedPipe)"));
			exit(-1);
		}

		// criar evento que vai ser associado à esturtura overlaped
		// os eventos aqui tem de ter sempre reset manual e nao automático porque temos de delegar essas responsabilidades ao sistema operativo
		hEventTemp = CreateEvent(NULL, TRUE, FALSE, NULL);

		if (hEventTemp == NULL) {
			_tprintf(TEXT("[ERRO] ao criar evento\n"));
			return -1;
		}

		dados.hPipes[i].hPipe = hPipe;
		dados.hPipes[i].activo = FALSE;
		//temos de garantir que a estrutura overlap está limpa
		ZeroMemory(&dados.hPipes[i].overlap,sizeof(dados.hPipes[i].overlap));
		//preenchemos agora o evento
		dados.hPipes[i].overlap.hEvent = hEventTemp;
		dados.hEvents[i] = hEventTemp;

		_tprintf(TEXT("[ESCRITOR] Esperar ligação de um leitor... (ConnectNamedPipe)\n"));

		// aqui passamos um ponteiro para a estrutura overlap
		ConnectNamedPipe(hPipe, &dados.hPipes[i].overlap);
	}

	//criacao da thread
	hThread = CreateThread(NULL, 0, ThreadMensagens, &dados, 0, NULL);
	if (hThread == NULL) {
		_tprintf(TEXT("[Erro] ao criar thread!\n"));
		return -1;
	}

	while (!dados.terminar && numClientes < N) {
		//permite estar bloqueado , à espera que 1 evento do array de enventos seja assinalado
		offset = WaitForMultipleObjects(N, dados.hEvents, FALSE, INFINITE);
		i = offset - WAIT_OBJECT_0; // devolve o indice da instancia do named pipe que está ativa, aqui sabemos em que indice o cliente se ligou

		// se é um indice válido ...
		if (i >= 0 && i < N) {

			_tprintf(TEXT("[ESCRITOR] Leitor %d chegou\n"), i);
			if (GetOverlappedResult(dados.hPipes[i].hPipe, &dados.hPipes[i].overlap, &nBytes, FALSE)) {
				// se entrarmos aqui significa que a funcao correu tudo bem
				// fazemos reset do evento porque queremos que o WaitForMultipleObject desbloqueio com base noutro evento e nao neste
				ResetEvent(dados.hEvents[i]);

				//vamos esperar que o mutex esteja livre
				WaitForSingleObject(dados.hMutex, INFINITE);
				dados.hPipes[i].activo = TRUE; // dizemos que esta instancia do named pipe está ativa
				ReleaseMutex(dados.hMutex);

				numClientes++;
			}
		}
	}


	//esperar que a thread termine
	WaitForSingleObject(hThread, INFINITE);

	//desligamos todos os clientes que se ligaram
	for (int i = 0; i < N; i++) {
		_tprintf(TEXT("[ESCRITOR] Desligar o pipe (DisconnectNamedPipe)\n"));

		//desliga todas as instancias de named pipes
		if (!DisconnectNamedPipe(dados.hPipes[i].hPipe)) {
			_tprintf(TEXT("[ERRO] Desligar o pipe! (DisconnectNamedPipe)"));
			exit(-1);
		}
	}


	exit(0);
}