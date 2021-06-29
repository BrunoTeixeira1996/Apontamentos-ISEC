#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

/*não podemos alterar os parametros desta função*/
void mostra (int s){
	printf("\nACORDA!!! (sinal %d)",s);
	fflush(stdout);
	exit(33);
}


int main(int argc, char *argv[]){
	int i;
	char str[40];

	signal(SIGINT,SIG_IGN);
	//signal(SIGINT, mostra);           /*tratar o sinal*/
	signal(SIGUSR1, mostra);           /*tratar o sinal*/
	//signal(SIGALRM,mostra);
	printf("O meu PID e %d...\n",getpid());


	do{
		//alarm(10);
		printf("Nome? ");
		fflush(stdout);
		scanf("%s",str);
		alarm(0); //aqui a pessoa já respondeu com o scanf
		printf("Ola");
		for(i = 0; i < 5;i++){
			printf("a");
			fflush(stdout);
			sleep(1);
		}
		printf(" %s!!!\n",str);

	}while(strcmp(str,"sair")!=0);

/*
	printf("Vou dormir...\n");
	do{
		pause();
	}while(1);

*/

	exit(0);
}