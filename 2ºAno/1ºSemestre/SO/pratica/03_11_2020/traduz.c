#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int continua = 1,res,estado;
	char letra;
	char palavra[10];


	do{
		printf("Letra: "); //pede uma letra
		fflush(stdout);
		scanf(" %c", &letra);
		if(letra == 'i'){    //se for i, vai ao "ding" 
			printf("Palavra: ");
			fflush(stdout);
			scanf("%s", palavra); // recebe a palavra que ira ser passada como argumento para o "ding"
			res = fork(); //cria o filho
			if(res == 0){  
				execl("ding","ding",palavra,NULL); // se o execl correr bem, executa o ding
				printf("erro\n"); // se correr mal, dá um erro e faz-se exit
				exit(7);
			}
			wait(&estado);   // o pai espera pelo filho
			if(WIFEXITED(estado)){ //e vê como é que ele terminou
				printf("O filho terminou com %d\n",WEXITSTATUS(estado));
				fflush(stdout);
			}
		}
		else if(letra == 'c'){ // se a letra for a c, vai ao "dfran"
			printf("Palavra: ");
			fflush(stdout);
			scanf("%s", palavra);
			res = fork(); //cria o filho
			if(res == 0){
				execl("dfran","dfran",palavra,NULL); // se o execl correr bem, executa o dfran
				printf("Erro no fork()\n"); // se nao, aparece um erro
				exit(7); // e fazemos exit(7)
			}
			wait(&estado); // o pai espera pelo filho
			if(WIFEXITED(estado)){ // e vê como é que ele temrinou
				printf("O filho terminou com %d\n",WEXITSTATUS(estado));
				fflush(stdout);
			}
		}

	}while(letra != 'x');

	printf("FIM...\n");


	return 0;
}