#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include "user.h"



int main(){

	int fd_server_fifo,fd_client_fifo; // file descriptors para os FIFOS
	int res_size;					   // variavel auxiliar para DEBUG
	user client,response;			   // client, estrutura inicial | response, estrutura de modoJogo
	int pid;
	char cli_fifo[32]; 				   //FIFO do Cliente
	setbuf(stdout,NULL);


	if(access(REF_FIFO, F_OK) != 0){
		printf("Árbitro nao esta a executar\n");
		exit(2);
	}

	/*=======================Receção de dados do Cliente=============================*/
	pid = getpid();
	sprintf(cli_fifo,CLI_FIFO,pid);

	printf("Nome do jogador: ");
	scanf(" %s",client.name);
	client.pont = -1;
	client.user_id = pid;
	client.registered = 0;

	//printf("PID: %d\n",client.user_id);


	/*======================FIFO do Cliente (aberto para leitura e escrita)===========================*/

	// se access != 0, FIFO nao existe, entao cria-o
	if(access(cli_fifo,F_OK) != 0)
		mkfifo(cli_fifo, 0600);

	//printf("FIFO do Cliente criado... \n");

	// abro o fifo do cliente como RDWR
	fd_client_fifo = open(cli_fifo, O_RDWR);

	if(fd_client_fifo == -1){
		printf("[ERRO] Abrir o FIFO do Cliente\n");
		exit(2);
	}

	//printf("FIFO do Cliente aberto... \n");

	/*=======================FIFO do Árbitro (escrita no FIFO do sv)=============================*/


	/*abre o fifo do árbiro para escrita*/
	fd_server_fifo = open(REF_FIFO, O_WRONLY);

	if(fd_server_fifo == -1){
		printf("[ERRO] Abrir o FIFO do Árbitro\n");
		exit(2);
	}

	//printf("FIFO do Árbitro aberto...\n");

	// cliente envia informação para o fifo do árbitro
	write(fd_server_fifo, &client, sizeof(user));

	/*=======================Cliente aguarda resposta do Servidor=============================*/

	while(1){
		//cliente lê resposta vinda do árbitro
		res_size = read(fd_client_fifo, &response, sizeof(user));
		
		printf("%s\n", response.response);

		// se o response.response == USADO, já existe um cliente com o mesmo nome, entao pede outro nome
		if(strcmp(response.response, "USADO") == 0){
			printf("Outro nome: ");
			scanf("%s", client.name);

			// volta a enviar informação para o árbitro
			write(fd_server_fifo, &client, sizeof(user));
			strcpy(response.response, "");
		}

		else{

			//cliente é inscrito para o campeonato
			if(strcmp(response.response, "INSCRITO") == 0){
				client.registered = response.registered;
				strcpy(response.response, "");


			// MAXPLAYERS chegou ao limite, nao aceita mais clientes
			}else if(strcmp(response.response, "MAXPLAYERS") == 0){
				printf("Árbitro lotado, tente depois\n");
				break;

			// cliente expulso pelo árbitro	
			}else if(strcmp(response.response, "EXPULSO") == 0){
				printf("Foi removido do campeonato\n");

			}else if(strcmp(response.response, "ADEUS") == 0){
				printf("A fechar...\n");
				break;
			}


			// Aguarda comando do cliente e envia para o fifo do árbitro
			printf("-> ");
			scanf("%s", client.command);
			write(fd_server_fifo, &client, sizeof(user));
			strcpy(client.command, "");

		}
		
	}


	// fecha os fifos
	close(fd_client_fifo);
	close(fd_server_fifo);

	unlink(cli_fifo);
	
	return 0;
}
