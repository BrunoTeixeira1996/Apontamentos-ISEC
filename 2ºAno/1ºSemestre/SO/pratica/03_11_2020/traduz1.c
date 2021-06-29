#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{

	char letter;
	char palavra[10];
	int res, estado;
	

	do{
		printf("Letra: ");
		fflush(stdout);
		scanf(" %c", &letter);

		if(letter == 'i'){ // se a tradução for para inglẽs
			printf("Palavra: "); // pede uma palavra
			fflush(stdout);    // limpamos o stdout
			scanf("%s", palavra); 
			res = fork(); // criamos o filho
			if(res == 0){ // o filho executa o ding1
				execl("ding1","ding1",palavra,NULL);
				printf("Erro\n");
				exit(1);
			}
			wait(&estado);
			if(WIFEXITED(estado)){
				printf("Terminou com [%d]\n", WEXITSTATUS(estado));
			}
			
		}
		else if(letter == 'f'){
			printf("Palavra: ");
			fflush(stdout);
			scanf("%s", palavra);
			res = fork();
			if(res == 0){
				execl("dfran1","dfran1",palavra,NULL);
				printf("Erro\n");
				exit(1);
			}
			wait(&estado);
			if(WIFEXITED(estado)){
				printf("Terminou com : [%d]\n",WEXITSTATUS(estado));
			}
		}

	}while(letter != 'x');

	exit(0);
}