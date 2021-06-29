#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>


void mostra(int s){
	printf("\nAcorda!!! (sinal %d)",s);
	fflush(stdout);
}

int main(int argc, char const *argv[])
{
	char str[40];

	signal(SIGALRM, mostra); // Neste caso o quando for chamado o alarme, a funcao "mostra" vai executar
	printf("O meu PID e %d ...\n",getpid());

	do{
		alarm(10); // alarme de 10 segundos
		printf("Nome: ");
		fflush(stdout);
		scanf("%s", str);
		alarm(0); // quando o utilizador responder desligamos o alarme
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

/*com o alarm(10), estou a dizer ao sistema operativo assim
"daqui a 10 segundos da-me um toque" sendo este toque o
SIGALRM

Por omissão o SIGALRM depois de ser chamado vai terminar
*/
