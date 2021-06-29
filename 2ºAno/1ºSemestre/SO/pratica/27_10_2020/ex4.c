#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char str[40];

	do{
		printf("COMANDO:");
		fflush(stdout);
		scanf("%s", str);
		execl(str, str, NULL);
		printf("[ERRO] Nao consegui executar aplicação\n");

	}while(strcmp(str,"sair") != 0);
	


	exit(0);
}

/*Depois do primeiro parametro no execl 
damos todos os argumentos que queremos,
terminados em NULL*/

/*se o execl for bem sucedido, este código
irá desaparecer e mesmo com o do while
a shell nao volta a pedir o COMANDO*/

/*se o execl falha, ocorre o [ERRO]*/

