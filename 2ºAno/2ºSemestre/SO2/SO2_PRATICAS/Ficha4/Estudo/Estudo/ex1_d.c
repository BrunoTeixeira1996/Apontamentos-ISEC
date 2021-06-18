#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>

/*EXERCICIO 1 d*/

/*
struct Valores {
	int somatorio;
	int limite_inf;
	int limite_sup;
} valores;


//Thread dos numeros pares
DWORD WINAPI ThreadSomaPares(LPVOID param) {
	int conta = 0;
	struct Valores* valores_pares = (struct Valores*)param;

	for (int i = valores_pares->limite_inf; i <= valores_pares->limite_sup; i++) {
		if (i % 2 == 0) {
			conta++;
			valores_pares->somatorio += i;
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
	struct Valores* valores_primos = (struct Valores*)param;

	for (int i = valores_primos->limite_inf; i <= valores_primos->limite_sup; i++) {
		if (VerificaNumPrimo(i)) {
			valores_primos->somatorio += i;
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

	struct Valores valores_pares;
	valores_pares.limite_inf = 1;
	valores_pares.limite_sup = 1000;
	valores_pares.somatorio = 0;

	struct Valores valores_primos;
	valores_primos.limite_inf = 1;
	valores_primos.limite_sup = 1000;
	valores_primos.somatorio = 0;

	int somaPares = 0, somaPrimos = 0, contadorThreads = 0, indice;


#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	//inicializar as duas threads
	hThreadPares = CreateThread(NULL, 0, ThreadSomaPares, &valores_pares.somatorio, 0, NULL);
	hThreadPrimos = CreateThread(NULL, 0, ThreadSomaPrimos, &valores_primos.somatorio, 0, NULL);
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
				_tprintf(TEXT("Somatorio dos pares: %d\n"), valores_pares.somatorio);
			}

			//se for 1 entao é a thread dos primos porque está no indice 1
			else {
				_tprintf(TEXT("Somatorio dos primos: %d\n"), valores_primos.somatorio);
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