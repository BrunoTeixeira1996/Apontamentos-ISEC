//#include <stdio.h>
//#include <windows.h>
//#include <tchar.h>
//
//#define MAX 256
//
//int main(int argc, char *argv[]) {
//	char result[MAX] = "Olá! ESte programa ainda não representa UNICODE\n";
//	printf("Frase:%s Tamanho:%d\n",result, strlen(result));
//	getchar();
//	return 0;
//}

/*
* char -> 1 byte (caracteres que estão na tabela ASCII)
* wchar -> 2 bytes (armazena caracteres UNICODE)
* solução -> TCHAR ou para char ou para wchar, depende da propriedade do projeto Character Set
*/