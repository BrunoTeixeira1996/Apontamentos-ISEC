#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

// nao se deve fazer texto dentro desta funcao
// porque é a funcao de tratamento de sinal e tem de ser rapida
void mostra(int s){
	printf("\nOla!!! (recebi o sinal %d)\n",s);
}

int main(int argc, char const *argv[])
{
	char str[40];

	//signal(SINGINT, SIG_IGN) // ignora o sinal SIGINT
	signal(SIGINT, mostra); // associa o sinal a uma função
	printf("O meu PID e %d ...\n",getpid());

	do{

		printf("Nome: ");
		fflush(stdout);
		scanf("%s", str);
		printf("Ola");
		for(int i = 0; i < 2 ; i++){
			printf("a");
			fflush(stdout);
			sleep(1);
		}
		printf(" %s!!!\n",str);
	}while(strcmp(str, "sair") != 0);

	exit(0);
}