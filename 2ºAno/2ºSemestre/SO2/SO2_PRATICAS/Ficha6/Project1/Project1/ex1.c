#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

#define FICHEIRO TEXT("letters.txt")
#define NUM_LETRAS 26
/*
int _tmain(int argc, TCHAR* argv[])
{
    HANDLE hFile, hFileMap;
    char* fileViewMap;
    char aux;
    int i;

#ifdef UNICODE
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif

    //abre ficheiro que já existe
    hFile = CreateFile(
        FICHEIRO,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        _tprintf(TEXT("Erro no CreateFile\n"));
        return 1;
    }

    //mapeia ficheiro num bloco de memoria
    hFileMap = CreateFileMapping(
        hFile,
        NULL,
        PAGE_READWRITE,
        0,
        0,
        NULL);

    if (hFileMap == NULL) {
        _tprintf(TEXT("Erro no CreateFileMapping\n"));
        //CloseHandle(hFile); //recebe um handle e fecha esse handle , no entanto o handle é limpo sempre que o processo termina
        return 1;
    }

    //mapeia bloco de memoria para espaço de endereçamento
    fileViewMap = (char *)MapViewOfFile(
        hFileMap,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        0);

    if (fileViewMap == NULL) {
        _tprintf(TEXT("Erro no MapViewOfFile\n"));
        return 1;
    }

    //inverte letras
    for (i = 0; i < NUM_LETRAS / 2; i++) {
        aux = fileViewMap[i];
        fileViewMap[i] = fileViewMap[NUM_LETRAS - 1 - i];
        fileViewMap[NUM_LETRAS - 1 - i] = aux;
    }

    FlushViewOfFile(fileViewMap, 0);
    
    //essencial fazer o UnmapViewOfFile
    UnmapViewOfFile(fileViewMap);

    CloseHandle(hFileMap);
    CloseHandle(hFile);

    _tprintf(TEXT("Ficheiro invertido com sucesso\n"));


    return 0;

}
*/