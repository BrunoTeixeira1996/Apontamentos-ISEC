#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

#define FICH TEXT("letters.txt")


/*
int _tmain(int argc, TCHAR* argv[])
{
    HANDLE hFile, hFileMap;
    char* fileViewMap;
    char aux;

#ifdef UNICODE
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif

    //abre ficheiro
    hFile = CreateFile(FICH, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        _tprintf(TEXT("Erro no CreateFile\n"));
        return -1;
    }

    //cria-se um objeto FileMapping associado a um ficheiro
    hFileMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0, NULL);

    if (hFileMap == NULL) {
        _tprintf(TEXT("Erro no CreateFileMapping\n"));
        return -1;
    }

    //mapeia-se vista desse objeto(hFileMap) numa zona de memória
    fileViewMap = (char*)MapViewOfFile(hFileMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    if (fileViewMap == NULL) {
        _tprintf(TEXT("Erro no MapViewOfFile\n"));
        return -1;
    }

    //inverter letras
    for (int i = 0; i < 26 / 2; i++) {
        //aux aponta para o fileViewMap
        aux = fileViewMap[i];
        fileViewMap[i] = fileViewMap[26 - i - 1];
        fileViewMap[26 - i - 1] = aux;
    }

    FlushViewOfFile(fileViewMap, 0);

    //obrigatorio fazer unmap da vista
    UnmapViewOfFile(fileViewMap);

    //naõ é obrigatorio fazer close handle porque o processo ao terminar ja limpa os handles mas fica mais legivel
    CloseHandle(hFileMap);
    CloseHandle(hFile);

    _tprintf(TEXT("Ficheiro invertido\n"));

    return 0;

}
*/