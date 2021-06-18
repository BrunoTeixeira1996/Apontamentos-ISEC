#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>


DWORD WINAPI ThreadSomaPares(LPVOID param) {
	int i, conta = 0;
	int *soma = (int *)param; //aqui recebemos um valor vindo da main

	for (i = 1; i <= 1000; i++) {
		if (i % 2 == 0) {
			*soma += i;
			conta++;

			if (conta == 200) {
				Sleep(1000);
				conta = 0;
			}
		}
	}
	return 0;
}

//Devolve 1 se for primo, 0 se caso contrario
int VerificaNumPrimo(int num) {
	int i;
	if (num <= 1)
		return 0;

	for (i = 2; i < num; i++) {
		if (num % i == 0) //se ele for divisivel por 1 ele não é primo
			return 0;
	}

}

DWORD WINAPI ThreadSomaPrimos(LPVOID param) {
	int i, conta = 0;
	int* soma = (int*)param; //aqui recebemos um valor vindo da main

	for (i = 1; i <= 1000; i++) {
		if (VerificaNumPrimo(i)) { // se for numero primo
			*soma += i;
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

	HANDLE hThreadPares; // handle para a thread dos pares
	HANDLE hThreadPrimos;
	HANDLE hThreads[2]; // array de Handles
	int somaPares = 0, somaPrimos = 0, contadorThreads = 0 , indice;
	DWORD res;

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	hThreadPares = CreateThread(NULL, 0, ThreadSomaPares, &somaPares, 0, NULL);
	hThreadPrimos = CreateThread(NULL, 0, ThreadSomaPrimos, &somaPrimos, 0, NULL);
	hThreads[0] = hThreadPares;
	hThreads[1] = hThreadPrimos;



	if (hThreadPares == NULL || hThreadPrimos == NULL) {
		_tprintf(TEXT("Erro a criar threads\n"));
		return 1;
	}

	/*
	* Aqui o WaitForSingleObject vai esperar pelas duas threads acabarem
	//Antes de apresentar os valores, tenho de garantir que elas terminam, ou seja, tenho de esperar 
	WaitForSingleObject(hThreadPares, INFINITE);
	WaitForSingleObject(hThreadPrimos, INFINITE);
	*/

	while (contadorThreads < 2) {
		//Aqui esperamos até que uma das threads termine
		//O retorno desta funcao, permite saber por exemplo que thread terminou primeiro  -> indice = (valor de retorno - WAIT_OBJECT_0 )
		// a WaitForMultipleObjects espera sempre pelo handle que está no indice 0 -> IMPORTANTE
		// se no ultimo parametro nao usar INFINITE eu defino quando é que a thread desbloqueia
		res = WaitForMultipleObjects(2 - contadorThreads, hThreads, FALSE, 1000);

		//passaram os 1000 milisegundos e ouve um timeout, logo nenhuma thread terminou ainda
		if (res == WAIT_TIMEOUT) {
			_tprintf(TEXT("Ainda à espera\n"));
		}
		// aqui ja sei que uma das threads terminou
		else {
			indice = res - WAIT_OBJECT_0;

			if (hThreads[indice] == hThreadPares)
				_tprintf(TEXT("Soma dos números pares: %d\n"), somaPares);
			else
				_tprintf(TEXT("Soma dos números primos: %d\n"), somaPrimos);

			//1a iteracao -> 2 handles [0, 1]
			//2a iteracao -> 1 handle [0]
			//Logo temos de puxar o handle que esta no indice 1 para o indice 0
			if (indice == 0)
				hThreads[0] = hThreads[1];

			contadorThreads++;
		}
	}
		
	return 0;
}

/*Na alinea d) temos de passar uma estrutura com o limite superior, inferior e um valor para as threads
* Na alinea e) o objetivo é dividir as threads. Por exemplo, uma thread que esteja a calcular uma thread de 0 a 500 e outra de 500 a 1000
* Usar 10000 threads para pequenos calculos nao compensa uma vez que a criacao de threads requer uma dependnecia fisica do CPU
* Na alinea h) temos de deixar que o utilizador escreva na consola (uma nova thread). Podemos ter uma variavel de controlo que é partilhada
* por todas as threads, por exemplo 0 ou 1, se for 0 elas param, se for 1 continuam -> IMPORTANTE FAZER ESTA ALINEA
*/
