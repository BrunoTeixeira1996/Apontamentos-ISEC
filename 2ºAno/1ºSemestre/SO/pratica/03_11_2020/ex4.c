#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	char str[40];
	int continua = 1 ,pid,res, estado;


	pid = getpid(); // mostra o PID do processo atual

	while(continua){
		printf("[%5d] COMANDO:",pid);
		fflush(stdout);
		scanf("%s", str);
		if(strcmp(str, "sair") != 0){
			res = fork(); //cria um processo filho
			if(res == 0){ // se for verdade, sabemos que isto é o filho
				pid = getpid(); // recebemos o PID do filho
				printf("[%5d] FILHO: Sou o filho ...\n",pid);
				execl(str, str, NULL); // se o execl for bem sucedido, o proximo printf não aparece
				printf("[%5d] [ERRO] FILHO: Nao consegui executar aplicação\n",pid);
				exit(7);//o exit aqui serve para se algo correr mal
			}
			printf("[%5d] PAI : Criei o filho PID=%d\n",pid,res);
			wait(&estado);	//esperar pelo fim do filho e devolve na var estado a forma como o filho acabou
			if(WIFEXITED(estado)){
				printf("[%5d] PAI : O meu filho terminou com %d\n",pid,WEXITSTATUS(estado));	
			}
			
		}
		else{
			continua = 0;
		}
	}
		
	
	exit(0);
}

/*no fork() se o resultado é 0 é filho, se o resultado for != 0 é pai*/

/*para saber que filho é que morreu usamos int n = wait(&estado)
o "n" vai retornar o pid do filho que morreu*/

/*convem usar sempre wait() para o pai esperar pelo filho*/

/* WIFEXITED -> Retorna true se o filho terminar normalmente
WEXITSTATUS -> retora o exit status do filho */

