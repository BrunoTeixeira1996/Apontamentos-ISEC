#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
	int pid,sinal;

	if(argc != 3){
		fprintf(stderr, "[ERRO] Nr de argumentos !\n          ./envia SINAL PID\n");
		exit(1);
	}

	sinal = atoi(argv[1]);
	pid = atoi(argv[2]);

	printf("Vou enviar o sinal %d ao processo %d...\n", sinal,pid);
	kill(pid,sinal); // envia um sinal ao processo
	
	exit(0);
}