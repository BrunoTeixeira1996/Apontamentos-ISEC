#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const *argv[])
{

	int fpid;
	int mat[2];

	if(argc < 3){
		printf("\nFaltam parâmetros\n");
		exit(1);
	}

	if(pipe(mat) == -1){
		printf("\nCriacao do pipe falhou\n");
		exit(2);
	}

	fpid = fork();
	if(fpid == -1){
		printf("\nFork falhou\n");
		exit(3);
	}

	if(fpid > 0 ){ // se for o pai, vai executar o programa que escreve
		close(STDOUT_FILENO); // fechamos o stdout
		dup(mat[1]); // duplicamos o mat[1] (write) p/lugar libertado
		close(mat[1]); // fechamos o duplicado
		close(mat[0]); // fechamos o lado de entrada
		execlp(argv[1],argv[1],NULL);

		printf("\nERRO\n");
	}

	if(fpid == 0){ // se for o filho, vai executar o programa que le
		close(STDIN_FILENO); // fecho o stdin
		dup(mat[0]); // duplico o mat[0] (read)
		close(mat[0]); // fecho o duplicado
		close(mat[1]); // fecho o lado de saida
		execlp(argv[2],argv[2],NULL);

		printf("\nERRO\n");
	}

	
	exit(0);
}