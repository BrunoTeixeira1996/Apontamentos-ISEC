#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	int i,n, t = 1;
	char *str;

	if(argc != 3){
		printf("[ERRO] Nr de argumentos!\n");
		exit(3);
	}

	n = atoi(argv[1]); // pego no segundo argumento e converto para inteiro
	str = getenv("TEMPO"); // gravo o valor da var de ambiente no str

	if(str != NULL){ // se a var de ambiente nao estiver a NULL
		t = atoi(str); // a variavel t irá ser o valor da var de ambiente
	}

	printf("INICIO...\n");

	for(i = 0; i < n; i++){ // faço um ciclo com o nr de vezes que o argv[2] vai repetir
		printf("%s", argv[2]); // mostro o argv[2]
		fflush(stdout); // faço flush
		sleep(t); // e faço sleep consoante o valor da variavel t
	}

	printf("\nFIM...\n");
	

	exit(0);

}