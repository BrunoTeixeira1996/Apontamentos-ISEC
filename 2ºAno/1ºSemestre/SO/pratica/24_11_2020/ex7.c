#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>



int main(int argc, char const *argv[])
{
	char str[40];
	int continua = 1, pid, res, estado,n;
	int canal[2]; // vai ser o descritor

	pid = getpid();
	while(continua){

		printf("[%5d]COMANDO: ", pid);
		fflush(stdout);
		scanf("%s",str);

		if(strcmp(str,"sair")!= 0){

			pipe(canal); // crio o pipe


			res = fork(); // cria um filho
			if(res == 0){
				pid = getpid();
				printf("[%5d]FILHO: Sou o filho...\n: ", pid);

				close(canal[0]); // fecho o canal de leitura do filho porque so quero escrever
				close(1);        // fecho o stdin
				dup(canal[1]);   // duplico o canal[1] e vai para a antiga posicao do stdin
				close(canal[1]); // fecho o origin porque ja tenho o meu canal[1] na posicao correta

				execl(str,str,NULL); // executa comando
				printf("[%5d] FILHO: Erro a executar cmd!\n",pid);
				exit(7);
			}
			printf("[%5d] PAI : Criei o filho PID=%d...\n",pid,res);

			close(canal[1]); // fecho a extremidade de escrita do pipe no pai porque nao preciso de escrever
			while((n = read(canal[0],str,39)) != 0){ // == 0 ---> EFO
				str[n] = '\0';
				printf("[%5d] PAI : Recebi ... '%s'\n",pid,str);
			}

			close(canal[0]); // fecho o canal 0 e fica assim fechado o pipe

			wait(&estado); // espera pelo fim do filho
			if(WIFEXITED(estado)){
				printf("[%5d] PAI: O meu filho terminou com %d!\n",pid, WEXITSTATUS(estado));
			}
		}
		else{
			continua = 0;
		}
	}



	exit(0);
}