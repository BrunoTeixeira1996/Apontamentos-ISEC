#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>

#define MAX 256

//int _tmain(int argc, TCHAR *argv[]) {
//	TCHAR result[MAX] = TEXT("Olá! Este programa ainda não representa UNICODE\n");
//#ifdef UNICODE
//	_setmode(_fileno(stdin), _O_WTEXT);
//	_setmode(_fileno(stdout), _O_WTEXT);
//	_setmode(_fileno(stderr), _O_WTEXT);
//#endif
//
//	_tprintf(TEXT("Frase:%s Tamanho:%d (caracteres) %d (bytes)\n"),result, _tcslen(result), _tcslen(result) * sizeof(TCHAR));
//	_gettchar();
//	return 0;
//}

/*Manipulação de strings
* char -> 1 byte (caracteres que estão na tabela ASCII)
* wchar -> 2 bytes (armazena caracteres UNICODE)
* solução -> TCHAR ou para char ou para wchar, depende da propriedade do projeto Character Set
* _tmain -> main ou wmain
* TEXT("") ou _T("") -> é uma macro do TCHAR que no momento de compilação vai ser alterado para " " ou L" "
* _tprintf -> printf ou wprintf
*/

/*Preparar a consola para ler e mostrar caracteres wide
* _setmode(stdin,constant)
* _setmode(stdout,constant)
*/