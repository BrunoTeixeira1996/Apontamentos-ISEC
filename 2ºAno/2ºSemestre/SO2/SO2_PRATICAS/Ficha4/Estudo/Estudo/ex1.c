#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>

/*EXERCICIO 1 , a e b */
/*
//Thread dos numeros pares
DWORD WINAPI ThreadSomaPares(LPVOID param) {
	int conta = 0;
	int *somatorio = (int*)param;
	for (int i = 1; i <= 1000; i++) {
		if (i % 2 == 0) {
			conta++;
			*somatorio += i;
		}
		if (conta == 200) {
			Sleep(1000);
			conta = 0;
		}
	}
	return 0;
}


//funcao auxiliar dos numeros primos -> 0 se nao for primo, 1 se for primo
int VerificaNumPrimo(int num) {
	if (num <= 1)
		return 0;

	for (int i = 2; i < num; i++) {
		if (num % i == 0) // se for divisivel por i nao é primo
			return 0;
	}
	return 1;
}

//Thread dos numeros primos
DWORD WINAPI ThreadSomaPrimos(LPVOID param) {
	int conta = 0;
	int* somatorio = (int*)param;
	
	for (int i = 1; i <= 1000; i++) {
		if (VerificaNumPrimo(i)) {
			*somatorio += i;
			conta++;
			if (conta == 15) {
				Sleep(1000);
				conta = 0;
			}
		}
	}
	return 0;

}



int _tmain(int argc, LPTSTR argv[]) {
	HANDLE hThreadPares;
	HANDLE hThreadPrimos;

	int somaPares = 0, somaPrimos = 0;


#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	//inicializar as duas threads
	hThreadPares = CreateThread(NULL,0,ThreadSomaPares,&somaPares,0,NULL);
	hThreadPrimos = CreateThread(NULL,0,ThreadSomaPrimos,&somaPrimos,0,NULL);

	if (hThreadPares == NULL || hThreadPrimos == NULL) {
		_tprintf(TEXT("[ERRO] na inicialização das threads\n"));
		return 1;
	}

	//Antes de apresentar os valores, tenho de garantir que elas terminam, ou seja, tenho de esperar 
	WaitForSingleObject(hThreadPares, INFINITE);
	WaitForSingleObject(hThreadPrimos, INFINITE);

	_tprintf(TEXT("Somatorio dos pares: %d\n"), somaPares);
	_tprintf(TEXT("Somatorio dos primos: %d\n"), somaPrimos);

	return 0;
}

*/