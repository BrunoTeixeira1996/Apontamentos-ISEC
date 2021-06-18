#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>
#include "SO2_F3_DLL.h"


int _tmain(int argc, TCHAR* argv[])
{

    double a, b;

#ifdef UNICODE
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif
   

    do {
        _tprintf(TEXT("\na > "));
        _tscanf_s(TEXT("%lf"), &a);

        factor = a;
        _tprintf(TEXT("Variável da DLL: %lf\n"), factor);

        _tprintf(TEXT("\nb > "));
        _tscanf_s(TEXT("%lf"), &b);

        _tprintf(TEXT("Função da DLL: %lf\n"), applyFactor(b));


    } while (factor != -1);


    return 0;
}