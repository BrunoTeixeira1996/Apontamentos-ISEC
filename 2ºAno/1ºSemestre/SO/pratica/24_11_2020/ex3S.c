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
	int num1,num2;
	char op; // +,-,*, / e s-> sair
	signed int res;
}PEDIDO;

int main(int argc, char const *argv[])
{
	setbuf(stdout,NULL);
	int fd,n_bytes, fdResposta;
	PEDIDO p;

	if(access(FIFO_SRV,F_OK)!= 0)// != 0 , entao ficheiro nao existe
	{
		// criar fifo do servidor
		mkfifo(FIFO_SRV,0600);
	}

	printf("Criei o fifo ...\n");

	fd = open(FIFO_SRV,O_RDONLY); // Abri para leitura e fica aqui parado até ter um cliente



	do{
		// ler pedido do fifo
		n_bytes = read(fd, &p, sizeof(PEDIDO)); // Li uma estrutura do tipo PEDIDO


		if(n_bytes == sizeof(PEDIDO)){
			printf("Recebi ... %d, %c, %d (%d bytes)\n", p.num1,p.op, p.num2, n_bytes);

		

			// calcular o resultado
			if(p.op == '+'){
				p.res = p.num1 + p.num2;
			}
			else if(p.op == '-'){
				p.res = p.num1 - p.num2;
			}
			else if(p.op == '*'){
				p.res = p.num1 * p.num2;
			}
			else if(p.op == '/'){
				p.res == p.num1 / p.num2;
			}
			else if(p.op == 's'){
				printf("Saindo ...");
				break;
			}
			
			


			// envia resposta para o cliente 
			fdResposta = open(FIFO_CLI,O_WRONLY); // Abri para escrita
			n_bytes = write(fdResposta, &p, sizeof(PEDIDO)); // Escrevi
			close(fdResposta); //Fechei
			printf("Escrevi ... %d (%d bytes)\n", p.res, n_bytes);	
		}
		else{
			printf("À espera de clientes ...\n");
		}

		sleep(5);
	}while(p.op != 's');	

	// Fechei
	close(fd); 

	// apagar fifo do servidor
	unlink(FIFO_SRV);

	exit(0);
}
