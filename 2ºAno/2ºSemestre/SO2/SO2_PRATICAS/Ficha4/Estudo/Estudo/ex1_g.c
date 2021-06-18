#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>

/*EXERCICIO 1 g*/

/*

//Thread dos numeros pares
DWORD WINAPI ThreadSomaPares(LPVOID param) {
	int conta = 0;
	int* somatorio = (int*)param;
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
	HANDLE hThreads[2]; // array de handles para threads
	DWORD res; //resultado do WaitForMultipleObjects

	int somaPares = 0, somaPrimos = 0, contadorThreads = 0, indice;


#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	//inicializar as duas threads
	hThreadPares = CreateThread(NULL, 0, ThreadSomaPares, &somaPares, 0, NULL);
	hThreadPrimos = CreateThread(NULL, 0, ThreadSomaPrimos, &somaPrimos, 0, NULL);
	hThreads[0] = hThreadPares;
	hThreads[1] = hThreadPrimos;

	if (hThreadPares == NULL || hThreadPrimos == NULL) {
		_tprintf(TEXT("[ERRO] na inicialização das threads\n"));
		return 1;
	}

	//enquanto existirem threads ativas
	while (contadorThreads < 2) {

		//se eu quero que a espera de uma thread seja condicionada, no ultimo parâmetro retiro o INFINITE e uso um TIMEOUT em milisegundos
		res = WaitForMultipleObjects(2 - contadorThreads, hThreads, FALSE, 1000);


		if (res == WAIT_TIMEOUT) {
			_tprintf(TEXT("Ainda à espera\n"));
		}
		else{
			// indice da thread que terminou = res - WAIT_OBJECT_0
			indice = res - WAIT_OBJECT_0;

			//se for 0 entao é a thread dos pares porque está no indice 0
			if (hThreads[indice] == hThreadPares) {
				_tprintf(TEXT("Somatorio dos pares: %d\n"), somaPares);
			}

			//se for 1 entao é a thread dos primos porque está no indice 1
			else {
				_tprintf(TEXT("Somatorio dos primos: %d\n"), somaPrimos);
			}
			*/

			/* Temos de garantir que o HANDLE pelo qual vamos esperar está no indice 0
			* se o indice que for desbloquado  for o 1 nao ha problema nenhum, no entanto
			* se o indicie que for desbloqueado for o 0 (na 1ª iteracao) tenho um problema porque na segunda iteracao nao terei
			* nenhum handle no indice 0, logo a thread que está no indice 1 nunca vai ser desbloqueada
			*/

			/*
			if (indice == 0) {
				hThreads[0] = hThreads[1];
			}

			contadorThreads++;
		}
		
	

	}


	return 0;
}

*/