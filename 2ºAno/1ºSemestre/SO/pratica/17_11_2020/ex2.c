#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>


int nerradas = 0, ncertas = 0, tempo = 10;

void mostra(int s){
	printf("ACORDA!!! (sinal %d)\n",s);
	nerradas++;
	if(nerradas==3){
		printf("FIM\n");
		exit(0);
	}

	//gera novos numeros
	alarm(tempo);
}

void nova(int s, siginfo_t *info, void *context){
	printf("TIMEOUT!!! (sinal = %d, PID = %d, Valor = %d)\n", s, info->si_pid, info->si_value);
	if(info->si_pid == 0) // so conto se for enviado por mim (0)
		nerradas++;
}


int main(int argc, char const *argv[])
{


	int i,res, num1,num2;
	char str[40];
	

#if 1

	struct sigaction act;
	/*sempre que  passarem os 10 segundos, nao fica parado no scanf
	ou seja, salta fora o scanf e volta ao inicio do codigo
	isto é feito com a sa_flags a 0 porque por defeito o alarm
	usa a flag SA_RESTART
	*/
	act.sa_handler = mostra;
	act.sa_flags = 0; //SA_RESTART;
	sigaction(SIGALRM, &act, NULL);
#else
	struct sigaction act;
	
	act.sa_handler = nova;
	act.sa_flags = SA_SIGINFO; // SA_SIGINFO indica que deve usar sa_sigaction e nao a sa_handler
	sigaction(SIGALRM, &act, NULL);
#endif

	srand((unsigned int) time(NULL));
	printf("O meu PID e %d...\n",getpid());
	do{
		num1 = rand()%101;
		num2 = rand()%101;
		printf("Tem %d segundos ...\n",tempo);
		printf("%d + %d ?\n", num1,num2);
		alarm(tempo);
		scanf("%d", &res);
		alarm(0);
		if(res == num1+num2){
			ncertas++;
			tempo--;
			printf("Acertou\n");
		}

		else{
			nerradas++;
			printf("Errou\n");
		}
	}while(nerradas < 3);
	


	exit(0);
}
