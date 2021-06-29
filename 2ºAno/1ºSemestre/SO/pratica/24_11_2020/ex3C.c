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

	int fd,n_bytes, fdResposta;
	PEDIDO p;

	setbuf(stdout,NULL);


	printf("Num1: ");scanf("%d", &p.num1);

	printf("Operacao: ");scanf(" %c", &p.op);

	printf("Num2: ");scanf("%d", &p.num2);


	fd = open(FIFO_SRV,O_WRONLY); // Abri o fifo do servidor para escrita
	n_bytes = write(fd, &p, sizeof(PEDIDO));// enviar os nrs para o fifo do servidor
	close(fd); // fecho

	printf("Enviei informacao para o fifo do servidor ...\n");


	if(access(FIFO_CLI,F_OK)!= 0)// != 0 , entao ficheiro nao existe
	{
		// criar fifo do cliente
		mkfifo(FIFO_CLI,0600);
	}

	printf("Criei o fifo do cliente ...\n");

	fdResposta = open(FIFO_CLI,O_RDONLY); // Abri para leitura e fica à espera

	n_bytes = read(fdResposta, &p, sizeof(PEDIDO)); // ler resposta do servidor
	close(fdResposta);

	printf("Resultado: %d\n" ,p.res);


	unlink(FIFO_CLI);
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