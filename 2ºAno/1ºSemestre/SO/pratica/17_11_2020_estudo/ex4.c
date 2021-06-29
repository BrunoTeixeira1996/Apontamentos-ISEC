#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>


int nerradas = 0, ncertas = 0, tempo = 10;

void mostra(int s){
	printf("\nACORDA!!! (sinal %d)\n",s);
	nerradas++;
}


void nova(int s, siginfo_t *info,void *context){
	printf("\nACORDA!!! (Sinal = %d, PID = %d, Valor = %d)\n",s, info->si_pid,info->si_value);

	if(info->si_pid == 0) /* se alguem fora da minha aplicação enviar-me sinais, eu nao
							 quero contar erradas*/
		nerradas++;
}

int main(int argc, char const *argv[])
{
	int i,res, nerradas = 0, ncertas = 0, tempo = 10,num1,num2;
	char str[40];

	struct sigaction act;
	act.sa_sigaction = nova; // funcao a executar
	act.sa_flags = SA_SIGINFO; // queremos receber informacao adicional 

	sigaction(SIGALRM,&act,NULL);

	srand((unsigned int) time(NULL));
	printf("O meu PID e %d...\n",getpid());

	do{
		num1 = rand() % 101;
		num2 = rand() % 101;
		printf("Tem %d segundos...\n",tempo);
		printf("%d + %d ?\n", num1, num2);
		fflush(stdout);
		alarm(tempo);
		scanf("%d", &res);
		alarm(0); // Quando chegar aqui, volta ao inicio do ciclo
		
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


