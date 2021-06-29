#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
	int pid,sinal;

	if(argc != 3){
		fprintf(stderr,"[ERRO] Nr de argumentos!\n    ./envia SINAL PID");
		exit(1);
	}

	sinal = atoi(argv[1]);
	pid = atoi(argv[2]);

	printf("Vou enviar o sinal %d ao processo %d...\n",sinal,pid);

	union sigval value;
	value.sival_int = 666;
	sigqueue(pid,sinal,value); // envia sinal ao processo com um valor

	exit(0);
}


