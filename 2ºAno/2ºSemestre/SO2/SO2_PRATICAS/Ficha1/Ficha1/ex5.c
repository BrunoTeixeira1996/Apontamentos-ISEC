#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>

#define MAX 256

int _tmain(int argc, LPTSTR argv[]) {
	//UNICODE: Por defeito, a consola Windows não processa caracteres wide.
	//A maneira mais fácil para ter esta funcionalidade é chamar _setmode:
#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif
	
		/*ALINEA A)
		//Nome do próprio 
		TCHAR text[256];
		GetModuleFileName(NULL, text, 256);
		_tprintf(text);
		*/
		
		/*ALINEA B) e C
		TCHAR str[256];
		do {
			_tprintf(TEXT("\nQue programa quer executar?"));
			fflush(stdin);
			_fgetts(str, MAX, stdin);
			//retirar o \n
			str[_tcslen(str) - 1] = '\0';

			STARTUPINFO si;
			PROCESS_INFORMATION pi;

			ZeroMemory(&si, sizeof(si));//igual ao memset mas com tudo a 0
			si.cb = sizeof(STARTUPINFO);
			ZeroMemory(&pi, sizeof(pi));

			if (CreateProcess(NULL,
				str,
				NULL,
				NULL,
				FALSE,
				0,
				NULL,
				NULL,
				&si,
				&pi
			)) {
				_tprintf(TEXT("Processo foi lançado, PID: %d , %d"), pi.dwProcessId, pi.dwThreadId);
			}
			else
				_tprintf(TEXT("Houve um erro ao lancar o processo"));

		} while (_tcsicmp(TEXT("FIM"), str));
		*/

		/*ALINEA D)*/
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		TCHAR text[256];
		int vezes;

		GetModuleFileName(NULL, text, 256);

		if (argc == 1)
			vezes = 3;
		else
			vezes = _ttoi(argv[1]);

		if (vezes > 0) {
			_tprintf(TEXT("Faltam %d execucoes\n"), vezes);
			vezes--;
			_stprintf_s(text, 256, TEXT("%s %d"), text, vezes);
			ZeroMemory(&si, sizeof(STARTUPINFO));
			si.cb = sizeof(STARTUPINFO);
			if (!CreateProcess(NULL, text, NULL, NULL, FALSE, FALSE, NULL, NULL, &si, &pi))
				_tprintf(TEXT("Erro ao lancar processo."));

		}
		
		return 0;
	}