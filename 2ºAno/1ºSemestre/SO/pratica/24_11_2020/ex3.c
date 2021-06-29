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
	int res;
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

	fd = open(FIFO_SRV,O_RDONLY); // Abri para leitura

/*
	do{
*/
		// ler pedido do fifo
		n_bytes = read(fd, &p, sizeof(PEDIDO)); // Li uma estrutura do tipo PEDIDO
		printf("Recebi ... %d, %c, %c (%d bytes)\n", p.num1,p.op, p.num2, n_bytes);

		if(n_bytes == sizeof(PEDIDO)){
			// calcular o resultado
			p.res = p.num1 + p.num2; // faz sempre uma soma

			// envia resposta para o cliente 
			fdResposta = open(FIFO_CLI,O_WRONLY); // Abri para escrita
			n_bytes = write(fdResposta, &p, sizeof(PEDIDO)); // Escrevi
			close(fdResposta); //Fechei
			printf("Escrevi ... %d (%d bytes)\n", p.res, n_bytes);
		}
		
/*		

	}while(p.op != 's');
*/
	// Fechei
	close(fd); 

	// apagar fifo do servidor
	unlink(FIFO_SRV);

	exit(0);
}

/*
O servidor cria o seu FIFO ("tubo")
Abre esse FIFO
Lê o pedido (read)
Fecha
Faz as contas
Abre o FIFO do cliente(FIFO criado pelo cliente)
Escreve a resposta no FIFO do cliente(write)
Fecha o FIFO do cliente
No final apaga o seu FIFO
=====================================================
O cliente abre o FIFO do servidor(FIFO criado pelo servidor)
Escreve nesse fifo
Cria o seu FIFO
Abre esse FIFO
Lê a resposta do servidor através do seu FIFO
=====================================================

O access permite verificar se tenho acesso a um ficheiro
O unlink apaga o fifo
*/