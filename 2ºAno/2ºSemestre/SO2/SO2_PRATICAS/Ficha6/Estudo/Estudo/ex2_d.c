#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

//
// A nossa memória partilhada terá espaço para 100 carateres
// Aqui é o sitio onde os processos vao poder escrever e ler mensagens
//

#define NUM_CHARS 100


// Tenho de partilhar o handle para o mutex e para o evento entre threads logo
// uso uma struct para todos os processos partilharem isso
typedef struct {
    TCHAR* fileViewMap; //ponteiro para a memória partilhada
    HANDLE hEvento; //handle para o evento
    HANDLE hMutex; //handle para o mutex
    HANDLE hTimer; //handle para o waitable timer
    int terminar;//flag que controla quando as threads terminam
}ThreadDados;

// Thread que vai ler da memoria partilhada
DWORD WINAPI ThreadLer(LPVOID param) {
    ThreadDados* dados = (ThreadDados*)param;
    LARGE_INTEGER tempo;

    tempo.QuadPart = 1000;

    while (1) {
        // bloqueia à espera que o evento fique assinalado
        WaitForSingleObject(dados->hEvento, INFINITE);

        //se a flag terminar estiver a 1, termina
        if (dados->terminar == 1) {
            break;
        }

        // bloqueia à espera do unlock do mutex
        WaitForSingleObject(dados->hMutex, INFINITE);

        //aqui o evento desbloqueou, posso mostrar a mensagem
        _tprintf(TEXT("Mensagem recebida : %s\n"), dados->fileViewMap);

        // faço release do mutex para mostrar que ja acabei de ler
        ReleaseMutex(dados->hMutex);

        // faço set do waitable timer para 10 segundos
        SetWaitableTimer(dados->hTimer,&tempo, 0, NULL, NULL, 0);
        //espero que o waitable timer chegue ao fim
        WaitForSingleObject(dados->hTimer,INFINITE);

    }
    
    return 0;
}

// Thread que vai escrever na memoria partilhada
DWORD WINAPI ThreadEscrever(LPVOID param) {
    ThreadDados* dados = (ThreadDados*)param;
    TCHAR msg[NUM_CHARS]; // array temporario para ler da consola

    LARGE_INTEGER tempo;

    tempo.QuadPart = 500;

    while (!(dados->terminar)) {

        // lemos do stdin e colocamos no array temporario msg
        _fgetts(msg, NUM_CHARS, stdin);
        msg[_tcslen(msg) - 1] = '\0';

        if (_tcscmp(msg, TEXT("fim")) == 0)
            dados->terminar = 1;

        //esperamos que o mutex esteja unlock
        WaitForSingleObject(dados->hMutex, INFINITE);

        //convem limparmos a memoria partilhada antes de copiarmos
        ZeroMemory(dados->fileViewMap, NUM_CHARS);

        //vamos copiar o conteudo que esta em msg para a memoria partilhada
        CopyMemory(dados->fileViewMap, msg, _tcslen(msg) * sizeof(TCHAR));

        //libertamos o mutex
        ReleaseMutex(dados->hMutex);

        //assinalamos o evento para que a outra thread ja consiga ler
        SetEvent(dados->hEvento);

        SetWaitableTimer(dados->hTimer,&tempo, 0, NULL, NULL, 0);
        WaitForSingleObject(dados->hTimer, INFINITE);
        //reset event para ele ficar nao assinalado novamente
        ResetEvent(dados->hEvento);
    }


    return 0;
}


int _tmain(int argc, TCHAR* argv[])
{
    ThreadDados dados;
    HANDLE hFileMap;
    HANDLE hSemaforo;

#ifdef UNICODE
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif

    // antes de criar a memória partilhada vamos criar o semaforo
    // o semaforo tem dois slots e os dois vão começar disponiveis
    // precisa de um nome para ser partilhado entre processos
    hSemaforo = CreateSemaphore(NULL, 2, 2, TEXT("SO2_SEMAFORO"));
    if (hSemaforo == NULL) {
        _tprintf(TEXT("Erro no CreateSemaphore\n"));
        return -1;
    }

    _tprintf(TEXT("A aguardar por um slot ... \n"));

    // bloqueamos à espera de um slot para nós
    WaitForSingleObject(hSemaforo, INFINITE);

    // quando ja tivermos espaço , iniciamos
    _tprintf(TEXT("Chat a iniciar ... \n"));

    // deixamos de ter o Createfile e delegamos isso ao sistema operativo usando INVALID_HANDLE_VALUE, no 1º argumento
    // ou seja, o filemapping vai ser criado mas vai ser criado assente nos ficheiros de paginação do sistema operativo
    // temos de colocar a quantidade de bytes que queremos que o filemapping tenha -> NUM_CHARS * sizeof(TCHAR)
    // tem de ter uma nome tambem para ser partilhado entre processos
    hFileMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, NUM_CHARS * sizeof(TCHAR), TEXT("SO2_MEMORIA_PARTILHADA"));
    if (hFileMap == NULL) {
        _tprintf(TEXT("Erro no CreateFileMapping\n"));
        return -1;
    }

    //mapeia-se vista desse objeto(hFileMap) numa zona de memória
    dados.fileViewMap = (TCHAR*)MapViewOfFile(hFileMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    if (dados.fileViewMap == NULL) {
        _tprintf(TEXT("Erro no MapViewOfFile\n"));
        return -1;
    }

    // Criação do evento reset manual e estado  inicial é nao assinalado e tem de ter
    // nome uma vez que vai ser partilhado entre processos
    dados.hEvento = CreateEvent(NULL, TRUE, FALSE, TEXT("SO2_EVENTO"));

    if (dados.hEvento == NULL) {
        _tprintf(TEXT("Erro no CreateEvent\n"));
        UnmapViewOfFile(dados.fileViewMap);
        return -1;
    }

    // criação do mutex
    dados.hMutex = CreateMutex(NULL, FALSE, TEXT("SO2_MUTEX"));
    if (dados.hMutex == NULL) {
        _tprintf(TEXT("Erro no CreateMutex\n"));
        UnmapViewOfFile(dados.fileViewMap);
        return -1;
    }

    //criacao do waitabel timer
    dados.hTimer = CreateWaitableTimer(NULL, TRUE, TEXT("SO2_TIMER"));
    if (dados.hTimer == NULL) {
        _tprintf(TEXT("Erro no CreateWaitableTimer\n"));
        UnmapViewOfFile(dados.fileViewMap);
        return -1;
    }


    dados.terminar = 0;
    HANDLE hThreads[2]; //cada processo cria a thread e leitura e de escrita
    hThreads[0] = CreateThread(NULL, 0, &ThreadLer, &dados, 0, NULL);
    hThreads[1] = CreateThread(NULL, 0, &ThreadEscrever, &dados, 0, NULL);

    if (hThreads[0] != NULL && hThreads[1] != NULL) {
        //se correu tudo bem vamos esperar que ambas as threads terminem
        WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
    }

    // quando formos terminar este processo, libertamos o Semaforo para indicar que ficou
    // um slot disponivel
    ReleaseSemaphore(hSemaforo, 1, NULL);

    //obrigatorio fazer unmap da vista
    UnmapViewOfFile(dados.fileViewMap);
    CloseHandle(hFileMap);


    return 0;

}