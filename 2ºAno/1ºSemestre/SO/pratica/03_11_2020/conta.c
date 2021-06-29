#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	int i;

	printf("INICIO...\n");

	for(i = 0; i < 20; i++){ // faço um ciclo com o nr de vezes que o argv[2] vai repetir
		printf("i"); // mostro o argv[2]
		fflush(stdout); // faço flush
		sleep(1); // e faço sleep consoante o valor da variavel t
	}

	printf("\nFIM...\n");
	

	exit(3);

}