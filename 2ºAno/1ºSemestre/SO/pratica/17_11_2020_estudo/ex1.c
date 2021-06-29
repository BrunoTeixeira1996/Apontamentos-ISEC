#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void mostra(int s){
	printf("\nACORDA!!! (sinal %d)\n",s);
}

int main(int argc, char const *argv[])
{
	int i;
	char str[40];

	signal(SIGALRM,mostra); // trata o sinal
	printf("O meu PID e %d...\n",getpid());

	do{
		printf("Nome: ");
		fflush(stdout);
		alarm(10);
		scanf("%s", str);
		alarm(0);
		printf("Ola");

		for(i = 0 ; i < 5 ; i++){
			printf("a");
			fflush(stdout);
			sleep(1);
		}

		printf(" %s!!!\n",str);

	}while(strcmp(str,"sair")!= 0);
	
	exit(0);
}