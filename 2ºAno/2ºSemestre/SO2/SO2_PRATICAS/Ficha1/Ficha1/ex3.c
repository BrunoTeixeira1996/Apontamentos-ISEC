#include <windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>

#define MAX 256

/*LPTSTR -> TCHAR *
* LPCTSTR -> const TCHAR *
*/

/*
int _tmain(int argc, LPTSTR argv[]) {
	TCHAR str[MAX], result[MAX] = TEXT("Olá! Este programa é para aceitar UNICODE. Insira \'fim\' para sair\n");
	unsigned int i;
	//UNICODE: Por defeito, a consola Windows não processa caracteres wide.
	//A maneira mais fácil para ter esta funcionalidade é chamar _setmode:
#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif
	do {
		_tprintf(result);
		fflush(stdin);
		_fgetts(str, MAX, stdin);
		//Retirar \n
		str[_tcslen(str) - 1] = '\0';
		//Maiúsculas
		for (i = 0; i < _tcslen(str); i++)
			str[i] = _totupper(str[i]);
		_stprintf_s(result, MAX, TEXT("Frase:%s, Tamanho:%d\n"), str, _tcslen(str));
	} while (_tcsicmp(TEXT("FIM"), str));

	/*
	* Criação de um processo ->  correr um programa já compilado
	*/
/*
	//Nome do próprio programa -> argv[0] ou GetModuleFileName
	TCHAR text[256] = TEXT("notepad.exe");

	//Estruturas que retornam informação do processo criado
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si)); //igual ao memset mas com tudo a 0
	si.cb = sizeof(STARTUPINFO);
	ZeroMemory(&pi, sizeof(pi)); // resultado da funçao : pid do processo, tid da thread principal, handle (ponteiro para estrutura) do processo, handle para thread
								// pid único no sistema para cada processo, handle podem ser vários, cada uma com dada permissão


	if (CreateProcess(NULL,   // No module name (use command line)
		text,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi)           // Pointer to PROCESS_INFORMATION structure
		) {
		_tprintf(TEXT("Processo foi lançado, PID: %d , %d"), pi.dwProcessId, pi.dwThreadId);
	}
	else
		_tprintf(TEXT("Houve um erro a lançar o processo !"));

	// Esperar pelo processo terminar
	//WaitForSingleObject(pi.hProcess, INFINITE);
	return 0;
}
*/