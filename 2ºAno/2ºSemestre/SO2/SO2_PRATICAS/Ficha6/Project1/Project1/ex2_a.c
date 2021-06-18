#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

/*
#define NUM_CHAR 26

typedef struct {
    TCHAR* fileViewMap;
    HANDLE hEvent;
    HANDLE hMutex;
    int terminar;
}ThreadDados;

DWORD WINAPI ThreadLer(LPVOID param) {
    ThreadDados* dados = (ThreadDados*)param;

    while (1) {
        //esperar até que evento desbloqueie
        WaitForSingleObject(dados->hEvent, INFINITE);

        //verifica se é preciso terminar a thread ou nao
        if (dados->terminar)
            break;

        //faço o lock para o mutex
        WaitForSingleObject(dados->hMutex, INFINITE);
        _tprintf(TEXT("Mensagem recebida: %s\n"),dados->fileViewMap);

        //faço unlock do mutex
        ReleaseMutex(dados->hMutex);

        Sleep(1000);
    }

    return 0;
}

DWORD WINAPI ThreadEscrever(LPVOID param) {
    TCHAR msg[NUM_CHAR];
    ThreadDados* dados = (ThreadDados*)param;


    while (!(dados->terminar)) {
        _fgetts(msg, NUM_CHAR, stdin);
        msg[_tcslen(msg) - 1] = '\0'; //terminamos a string de maneira correta

        if (_tcscmp(msg, TEXT("fim")) == 0)
            dados->terminar = 1;


        //faço lock ao mutex
        WaitForSingleObject(dados->hMutex, INFINITE);

        //limpa memoria antes de fazer a copia
        ZeroMemory(dados->fileViewMap,NUM_CHAR * sizeof(TCHAR));

        //copia memoria de um sitio para outro (aqui copia a mensagem escrita no terminal para o fileViewMap)
        CopyMemory(dados->fileViewMap, msg, _tcslen(msg) * sizeof(TCHAR));

        //liberto mutex
        ReleaseMutex(dados->hMutex);

        //criamos evento
        SetEvent(dados->hEvent);
        Sleep(500);

        ResetEvent(dados->hEvent); //torna o evento novamente não assinalado
    }

    return 0;
}


int _tmain(int argc, TCHAR* argv[])
{
    HANDLE hFileMap;
    ThreadDados dados;
    HANDLE hThreads[2];

#ifdef UNICODE
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif

  

    //mapeia ficheiro num bloco de memoria
    hFileMap = CreateFileMapping(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        NUM_CHAR * sizeof(TCHAR), // alterar o tamanho do filemapping
        TEXT("SO2_MEM_PART")); //nome do file mapping, tem de ser único

    if (hFileMap == NULL) {
        _tprintf(TEXT("Erro no CreateFileMapping\n"));
        //CloseHandle(hFile); //recebe um handle e fecha esse handle , no entanto o handle é limpo sempre que o processo termina
        return 1;
    }

    //mapeia bloco de memoria para espaço de endereçamento
    dados.fileViewMap = (TCHAR *)MapViewOfFile(
        hFileMap,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        0);

    if (dados.fileViewMap == NULL) {
        _tprintf(TEXT("Erro no MapViewOfFile\n"));
        return 1;
    }

    
    dados.hEvent = CreateEvent(
        NULL,
        TRUE,
        FALSE,
        TEXT("SO2_EVENTO"));

    if (dados.hEvent == NULL) {
        _tprintf(TEXT("Erro no CreateEvent\n"));
        UnmapViewOfFile(dados.fileViewMap);
        return 1;
    }

    dados.hMutex = CreateMutex(
        NULL,
        FALSE,
        TEXT("SO2_MUTEX"));

    if (dados.hMutex == NULL) {
        _tprintf(TEXT("Erro no CreateMutex\n"));
        UnmapViewOfFile(dados.fileViewMap);
        return 1;
    }

    dados.terminar = 0;

    //cria threads
    hThreads[0] = CreateThread(NULL, 0, ThreadLer, &dados, 0, NULL);
    hThreads[1] = CreateThread(NULL, 0, ThreadEscrever, &dados, 0, NULL);
    
    if (hThreads[0] != NULL && hThreads[1] != NULL)
        WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);
    
    //essencial fazer o UnmapViewOfFile
    UnmapViewOfFile(dados.fileViewMap);

    CloseHandle(hFileMap);


    return 0;

}
*/