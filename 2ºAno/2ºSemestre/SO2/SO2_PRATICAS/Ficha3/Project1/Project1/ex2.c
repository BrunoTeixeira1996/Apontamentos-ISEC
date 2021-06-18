#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

//definimos o prototipo da funcao
typedef double(*applyFactorFunc)(double);
/*
int _tmain(int argc, TCHAR* argv[])
{

    HMODULE hLib;
    double* var;
    applyFactorFunc func;
    double a, b;

#ifdef UNICODE
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif

    hLib = LoadLibrary(TEXT("SO2_F3_DLL.dll"));

    if (hLib == NULL) {
        _tprintf(TEXT("Erro a carregar DLL"));
        return 1;
    }

    var = (double *)GetProcAddress(hLib,"factor"); //sem TEXT(...)
    func = (applyFactorFunc)GetProcAddress(hLib, "applyFactor");


    if (var == NULL || func == NULL) {
        _tprintf(TEXT("Erro a obter endereços"));
        return 1;
    }

    do {
        _tprintf(TEXT("\na > "));
        _tscanf_s(TEXT("%lf"), &a);

        *var = a;
        _tprintf(TEXT("Variável da DLL: %lf\n"), *var);

        _tprintf(TEXT("\nb > "));
        _tscanf_s(TEXT("%lf"), &b);

        _tprintf(TEXT("Função da DLL: %lf\n"), func(b));


    } while (*var != -1);

    FreeLibrary(hLib);


    return 0;
}
*/