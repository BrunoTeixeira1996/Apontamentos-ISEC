#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>

void mostra(int s){
	printf("\nACORDA!!! (sinal %d)\n",s);
	alarm(10);
}

int main(int argc, char const *argv[])
{
	int i,res, nerradas = 0, ncertas = 0, tempo = 10,num1,num2;
	char str[40];

	srand((unsigned int) time(NULL));
	signal(SIGALRM, mostra);
	printf("O meu PID e %d...\n",getpid());

	do{
		num1 = rand() % 101;
		num2 = rand() % 101;
		printf("Tem %d segundos...\n",tempo);
		printf("%d + %d ?\n", num1, num2);
		fflush(stdout);
		alarm(tempo);
		scanf("%d", &res);
		alarm(0);
		
		if(res == num1+num2){
			ncertas++;
			tempo--;
		}
		else{
			nerradas++;
		}

	}while(strcmp(str,"sair")!= 0);
	
	exit(0);
}


