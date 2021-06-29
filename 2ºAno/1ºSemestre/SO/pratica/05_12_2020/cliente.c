#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_SRV "tubo"
#define FIFO_CLI "cli%d"

typedef struct{
	int num1,num2;
	char op; // +,-,*, / e s-> sair
	int res;
	int pid; // remetente
}PEDIDO;

int main(int argc, char const *argv[])
{
	char str[40],fifo[40];
	setbuf(stdout,NULL);
	int fd,n_bytes, fdResposta;
	PEDIDO p;


	//verificar se existe
	if(access(FIFO_SRV,F_OK)!= 0)// != 0 , entao ficheiro nao existe
	{
		fprintf(stderr, "[ERRO] O servidor nao esta a funcionar...\n");
		exit(1);
	}

	p.pid = getpid();
	sprintf(fifo,FIFO_CLI,p.pid);

	mkfifo(fifo,0600);

	printf("Criei o meu fifo - '%s'...\n",fifo);

	fd = open(FIFO_SRV,O_WRONLY); // Abri para escrita

	printf("Abri o fifo do servidor - '%s'...\n",FIFO_SRV);



	do{

		// solicitar dados ao utilizador

		printf("Num 1: "); fflush(stdout); scanf("%d", &p.num1);
		printf("Num 2: "); fflush(stdout); scanf("%d", &p.num2);
		printf("OP: "); fflush(stdout); scanf("%s",str); p.op = str[0];

		// enviar pedido ao servidor
		n_bytes = write(fd, &p, sizeof(PEDIDO));
		printf("Enviei ... %d, %c, %d (%d bytes)\n", p.num1,p.op, p.num2, n_bytes);


		// recebe resposta do servidor
		fdResposta = open(fifo,O_RDONLY); // Abri para leitura
		n_bytes = read(fdResposta, &p, sizeof(PEDIDO)); // Escrevi
		close(fdResposta); //Fechei
		printf("Recebi ... %d (%d bytes)\n", p.res, n_bytes);
		

	}while(p.op != 'c');

	// Fechei
	close(fd); 

	// apagar fifo do servidor
	unlink(fifo);

	exit(0);
}

