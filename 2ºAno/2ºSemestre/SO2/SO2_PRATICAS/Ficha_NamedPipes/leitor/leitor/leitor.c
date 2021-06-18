#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

// ...
#define PIPE_NAME TEXT("\\\\.\\pipe\\teste")

int _tmain(int argc, LPTSTR argv[]) {
	TCHAR buf[256];
	HANDLE hPipe;
	int i = 0;
	BOOL ret;
	DWORD n;

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	_tprintf(TEXT("[LEITOR] Esperar pelo pipe '%s' (WaitNamedPipe)\n"),PIPE_NAME);

	//espera que exista um named pipe para ler do mesmo
	//bloqueia aqui
	if (!WaitNamedPipe(PIPE_NAME, NMPWAIT_WAIT_FOREVER)) {
		_tprintf(TEXT("[ERRO] Ligar ao pipe '%s'! (WaitNamedPipe)\n"), PIPE_NAME);
		exit(-1);
	}

	_tprintf(TEXT("[LEITOR] Ligação ao pipe do escritor... (CreateFile)\n"));

	//ligamo-nos ao named pipe que ja existe nesta altura
	//1º nome do named pipe, 2ºpermissoes (têm de ser iguais ao CreateNamedPipe do servidor), 3ºshared mode 0 aqui,
	//4º security atributes, 5ºflags de criação OPEN_EXISTING, 6º o default é FILE_ATTRIBUTE_NORMAL e o 7º é o template é NULL
	hPipe = CreateFile(PIPE_NAME, GENERIC_READ, 0, NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, NULL);

	if (hPipe == NULL) {
		_tprintf(TEXT("[ERRO] Ligar ao pipe '%s'! (CreateFile)\n"), PIPE_NAME);
		exit(-1);
	}

	_tprintf(TEXT("[LEITOR] Liguei-me...\n"));

	while (1) {
		//le as mensagens enviadas pelo servidor
		ret = ReadFile(hPipe, buf, sizeof(buf), &n, NULL);

		//termina corretamente a string
		buf[n / sizeof(TCHAR)] = '\0';

		if (!ret || !n) {
			_tprintf(TEXT("[LEITOR] %d %d... (ReadFile)\n"), ret, n);
			break;
		}

		_tprintf(TEXT("[LEITOR] Recebi %d bytes: '%s'... (ReadFile)\n"), n, buf);
	}

	CloseHandle(hPipe);
	Sleep(200);

	return 0;
}