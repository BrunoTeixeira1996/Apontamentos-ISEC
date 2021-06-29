#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_SRV "tubo"
#define FIFO_CLI "cli"

typedef struct{
	int num1, num2;
	char op; // +, -, *, /, s-> sair
	float res;
}PEDIDO;


int main(int argc, char const *argv[])
{
	int fd,n, fdR;
	PEDIDO p;

//	access(FIFO_SRV, F_OK); // se devolver 0 -> ficheiro existe

	/*criar fifo do servidor*/
	if(access(FIFO_SRV, F_OK) != 0){
		mkfifo(FIFO_SRV,0600);
	}

	printf("Criei o FIFO...\n");
	// abri o fifo
	fd = open(FIFO_SRV,O_RDONLY);

	do{
		/*le pedido do fifo ...*/
		n = read(fd, &p, sizeof(PEDIDO));
		printf("Recebi... %d %c %d (%d bytes)\n", p.num1, p.op, p.num2,n);

		if(n == sizeof(PEDIDO)){
			/*calcula resultado ...*/
			p.res = p.num1 + p.num2; // faz sempre uma soma

			/*envia resposta para o cliente ...*/
			fdR = open(FIFO_CLI, O_WRONLY);
			n = write(fdR, &p, sizeof(PEDIDO));
			close(fdR);

			printf("Escrevi... %d %c %d (%d bytes)\n", p.num1, p.op, p.num2,n);
			
		}
		

	}while(p.op!='s');

	// fecho o fifo
	close(fd);


	/*apagar fifo do servidor*/
	unlink(FIFO_SRV);



	exit(0);
}