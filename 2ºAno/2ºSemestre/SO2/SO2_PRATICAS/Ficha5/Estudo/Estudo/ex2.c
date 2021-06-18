#include <windows.h>
#include <tchar.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>

/*
// funcionalidade relacionada com temporização
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
	int* contador;
} TDados;

// função da(s) thread(s)
// Thread que calcula multiplos de 3
DWORD WINAPI ThreadMultiplos(LPVOID param) {
	TDados* dados = (TDados*)param;
	unsigned int i;
	
	for (i = dados->lim_inferior; i < dados->lim_superior; i++) {
		if (i % 3 == 0)
			*(dados->contador)++;
	}

	return 0;
}


// número * máximo * de threads
// podem (e devem) ser menos
#define MAX_THREADS 20


int _tmain(int argc, TCHAR* argv[]) {

	// matriz de handles das threads
	HANDLE hThreads[MAX_THREADS];

	// Matriz de dados para as threads;
	TDados tdados[MAX_THREADS];

	// número efectivo de threads
	int numthreads;

	// limite superior
	unsigned int limsup;

	// variáveis para cronómetro
	__int64 clockticks;
	double duracao;
	unsigned int range;
	int i;
	unsigned int contador_geral = 0;

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

	//limite global que cada thread vai calcular
	range = limsup / numthreads;

	for (i = 0; i < numthreads; i++) {
		tdados[i].lim_inferior = i * range + 1;
		tdados[i].lim_superior = (i + 1) * range;

		//se tivermos na ultima thread e o nr de threads for um valor impar
		if (i == numthreads - 1 && limsup % numthreads > 0)
			tdados[i].lim_superior += limsup % numthreads;

		tdados[i].contador = &contador_geral;

		hThreads[i] = CreateThread(NULL, 0, ThreadMultiplos, &tdados[i], CREATE_SUSPENDED, NULL);

		if (hThreads[i] != NULL)
			_tprintf(TEXT("Threads criada para o intervalor [ %d; %d ]\n"), tdados[i].lim_inferior, tdados[i].lim_superior);
	}

	//inicializa todas as threads ao mesmo tempo
	for (i = 0; i < numthreads; i++)
		ResumeThread(hThreads[i]);

	//esperar que todas as threads terminem
	WaitForMultipleObjects(numthreads, hThreads,TRUE,INFINITE);


	_tprintf(TEXT("\nNúmero de múltiplos de 3 no intervalo [1;%d] : %d "), limsup, contador_geral);

	// manda as threads começar
	clockticks = startClock();
	// FAZER aguarda / controla as threads
	// manda as threads parar
	duracao = stopClock(clockticks);
	_tprintf(TEXT("\nSegundos=%f\n"), duracao);


	// FAZER apresenta resultados


	// Cód. ref. para aguardar por uma tecla – caso faça falta
	// _tprintf(TEXT("\nCarregue numa tecla"));
	// _gettch();
	return 0;
}
*/