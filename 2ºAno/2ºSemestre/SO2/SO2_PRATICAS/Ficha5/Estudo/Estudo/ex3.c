#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

/*
// funcionalidade relacionada com temporização
static double PerfCounterFreq; // n ticks por seg.
void initClock() {
    LARGE_INTEGER aux;
    if (!QueryPerformanceFrequency(&aux))
        _tprintf(TEXT("\nSorry - No can do em QueryPerfFreq\n"));
    PerfCounterFreq = (double)(aux.QuadPart); // / 1000.0;
    _tprintf(TEXT("\nTicks por sec.%f\n"), PerfCounterFreq);
}
__int64 startClock() {
    LARGE_INTEGER aux;
    QueryPerformanceCounter(&aux);
    return aux.QuadPart;
}
double stopClock(__int64 from) {
    LARGE_INTEGER aux;
    QueryPerformanceCounter(&aux);
    return (double)(aux.QuadPart - from) / PerfCounterFreq;
}
// estrutura de dados para controlar as threads
typedef struct {
    unsigned int lim_inferior;
    unsigned int lim_superior;
    unsigned int* contador;
    HANDLE hMutex;
} TDados;
// função da(s) thread(s)
// ...
DWORD WINAPI ThreadMultiplos(LPVOID param) {
    TDados* dados = (TDados*)param;
    unsigned int i;
    for (i = dados->lim_inferior; i <= dados->lim_superior; i++) {
        if (i % 3 == 0) {
            //bloqueia enquanto o Mutex nao esta livre
            WaitForSingleObject(dados->hMutex, INFINITE);

            (*dados->contador)++;
            //liberta mutex
            ReleaseMutex(dados->hMutex);
        }
    }
    return 0;
}
// número * máximo * de threads
// podem (e devem) ser menos
#define MAX_THREADS 20
int _tmain(int argc, TCHAR* argv[])
{
    // matriz de handles das threads
    HANDLE hThreads[MAX_THREADS];
    // Matriz de dados para as threads;
    TDados tdados[MAX_THREADS];
    // número efectivo de threads
    unsigned int numthreads;
    // limite superior
    unsigned int limsup;
    // variáveis para cronómetro
    __int64 clockticks;
    double duracao;
    unsigned int range;
    unsigned int i;
    unsigned int contador_geral = 0;
    HANDLE hMutexGlobal;
#ifdef UNICODE
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif
    initClock();
    _tprintf(TEXT("\nLimite sup. -> "));
    _tscanf_s(TEXT("%u"), &limsup); // 6000
    _tprintf(TEXT("\nNum threads -> "));
    _tscanf_s(TEXT("%u"), &numthreads); // 3
    if (numthreads > MAX_THREADS)
        numthreads = MAX_THREADS;
    // FAZER prepara e cria threads
    //       manda as threads começar
    range = limsup / numthreads; //2000
    hMutexGlobal = CreateMutex(NULL, FALSE, NULL);
    if (hMutexGlobal == NULL) {
        _tprintf(TEXT("Erro a criar mutex.\n"));
        return 1;
    }
    for (i = 0; i < numthreads; i++) {
        tdados[i].lim_inferior = i * range + 1; //1,2001,4001
        tdados[i].lim_superior = (i + 1) * range; //2000,4000,6000
        if (i == numthreads - 1 && limsup % numthreads > 0) // caso estivessemos a calcular um intervalo ímpar
            tdados[i].lim_superior += limsup % numthreads; // damos à thread final os valores que faltam calcular

        tdados[i].contador = &contador_geral;
        tdados[i].hMutex = hMutexGlobal;
        //criar a thread suspendida (CREATE_SUSPENSED) e guardar o handle no array de handles
        hThreads[i] = CreateThread(NULL, 0, ThreadMultiplos, &tdados[i], CREATE_SUSPENDED, NULL);
        if (hThreads[i] != NULL)
            _tprintf(TEXT("Thread criada para o intervalo [%d;%d]\n"), tdados[i].lim_inferior, tdados[i].lim_superior);
    }
    for (i = 0; i < numthreads; i++)
        ResumeThread(hThreads[i]);
    clockticks = startClock();
    // FAZER aguarda / controla as threads
    //       manda as threads parar
    WaitForMultipleObjects(numthreads, hThreads, TRUE, INFINITE);

    duracao = stopClock(clockticks);
    _tprintf(TEXT("\nSegundos=%f\n"), duracao);
    // FAZER apresenta resultados
    _tprintf(TEXT("\nNúmero de múltiplos de 3 no intervalo [1;%d]: %d"), limsup,contador_geral);
    // Cód. ref. para aguardar por uma tecla – caso faça falta
    // _tprintf(TEXT("\nCarregue numa tecla"));
    // _gettch();
    return 0;
}

*/