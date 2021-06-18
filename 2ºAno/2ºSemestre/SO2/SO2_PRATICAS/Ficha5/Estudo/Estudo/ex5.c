#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>


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
    CRITICAL_SECTION* cs;
    HANDLE hEvent;
} TDados;

// função da(s) thread(s)
DWORD WINAPI ThreadMultiplos(LPVOID param) {
    TDados* dados = (TDados*)param;
    unsigned int i;

    //vou dizer que as threads vao todas bloquear com o Evento ,até que o evento seja assinalado e elas possam desbloquear
    WaitForSingleObject(dados->hEvent,INFINITE);


    for (i = dados->lim_inferior; i <= dados->lim_superior; i++) {
        if (i % 3 == 0) {
            //bloqueia a Critical Section
            EnterCriticalSection(dados->cs);
            (*dados->contador)++;

            //liberta a Critical Section
            LeaveCriticalSection(dados->cs);
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

    CRITICAL_SECTION csGlobal;
    HANDLE hEventGlobal;

#ifdef UNICODE
    _setmode(_fileno(stdin), _O_WTEXT);
    _setmode(_fileno(stdout), _O_WTEXT);
#endif
    initClock();
    _tprintf(TEXT("\nLimite sup. -> "));
    _tscanf_s(TEXT("%u"), &limsup);
    _tprintf(TEXT("\nNum threads -> "));
    _tscanf_s(TEXT("%u"), &numthreads);
    if (numthreads > MAX_THREADS)
        numthreads = MAX_THREADS;
    // FAZER prepara e cria threads
    //       manda as threads começar
    range = limsup / numthreads;

    //criamos o evento, atencao que esta a ser criado com reset automatico, logo vai passar a ter
    // o estado nao assinalado assim que uma thread o desbloqueie
    //logo é preciso assinalar novamente, para isso temos forçosamente de ter um
    //evento de reset manual
    //hEventGlobal = CreateEvent(NULL, FALSE, FALSE, NULL);
    hEventGlobal = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (hEventGlobal == NULL) {
        _tprintf(TEXT("Erro a criar o evento\n"));
        return -1;
    }

    //inicializamos a critical section. o valor do spin count convem ser baixo
    InitializeCriticalSectionAndSpinCount(&csGlobal, 500);


    for (i = 0; i < numthreads; i++) {
        tdados[i].lim_inferior = i * range + 1;
        tdados[i].lim_superior = (i + 1) * range;
        if (i == numthreads - 1 && limsup % numthreads > 0) // caso estivessemos a calcular um intervalo ímpar
            tdados[i].lim_superior += limsup % numthreads; // damos à thread final os valores que faltam calcular

        tdados[i].contador = &contador_geral;
        tdados[i].cs = &csGlobal; // é passado o mesmo valor para todas as threads
        tdados[i].hEvent = hEventGlobal; // é passado o handle do evento para as threads

        //retiramos o CREATE_SUSPENDED porque agora vamos usar o Evento
        hThreads[i] = CreateThread(NULL, 0, ThreadMultiplos, &tdados[i], 0, NULL);
        if (hThreads[i] != NULL)
            _tprintf(TEXT("Thread criada para o intervalo [%d;%d]\n"), tdados[i].lim_inferior, tdados[i].lim_superior);
    }

    //assinalamos aqui o Evento
    SetEvent(hEventGlobal);

    clockticks = startClock();


    // FAZER aguarda / controla as threads
    //       manda as threads parar
    WaitForMultipleObjects(numthreads, hThreads, TRUE, INFINITE);

    duracao = stopClock(clockticks);
    _tprintf(TEXT("\nSegundos=%f\n"), duracao);



    // FAZER apresenta resultados
    _tprintf(TEXT("\nNúmero de múltiplos de 3 no intervalo [1;%d]: %d"), limsup, contador_geral);


    return 0;
}

/*
* EVENTO ...
* Neste caso vamos inicializar as threads todas de uma vez , retirando o CREATE_SUSPENDED do CreateThread
* logo elas vao começar logo a executar mas vamos garantir que elas começam todas ao mesmo tempo
* através de um Evento.
* 
* As threads vao ficar todas bloqueadas num evento, a main ,depois de criar as threads todas, vai assinalar o evento(vai notificar as threads),
* e elas vão todas desbloquear ao mesmo tempo
*/