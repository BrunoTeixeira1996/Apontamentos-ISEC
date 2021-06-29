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

	int fd_server_fifo,fd_client_fifo, fd_game_fifo; // file descriptors para os FIFOS
	int res_size;					   // variavel auxiliar para DEBUG
	user client,response;			   // client, estrutura inicial | response, estrutura de modoJogo
	int pid;
	char cli_fifo[32]; 				   //FIFO do Cliente
	setbuf(stdout,NULL);
	int start = 0, block = 0;
			
	int response_select;
	fd_set fi_descript; // vai guardar os file descriptors existentes
	struct timeval time_out; // var para o time_out

	setbuf(stdout, NULL);

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


	/*======================FIFO do Cliente (aberto para leitura e escrita)===========================*/

	// se access != 0, FIFO nao existe, entao cria-o
	if(access(cli_fifo,F_OK) != 0)
		mkfifo(cli_fifo, 0600);

	// abro o fifo do cliente como RDWR
	fd_client_fifo = open(cli_fifo, O_RDWR);

	if(fd_client_fifo == -1){
		printf("[ERRO] Abrir o FIFO do Cliente\n");
		exit(2);
	}


	/*=======================FIFO do Árbitro (escrita no FIFO do sv)=============================*/


	/*abre o fifo do árbiro para escrita*/
	fd_server_fifo = open(REF_FIFO, O_WRONLY);

	if(fd_server_fifo == -1){
		printf("[ERRO] Abrir o FIFO do Árbitro\n");
		exit(2);
	}


	// cliente envia informação para o fifo do árbitro
	write(fd_server_fifo, &client, sizeof(user));

	/*=======================Cliente aguarda resposta do Servidor=============================*/

	while(1){
		

		//select
		FD_ZERO(&fi_descript); // limpar os file descriptors do select
		FD_SET(0,&fi_descript); // atribui ao STDIN
		FD_SET(fd_client_fifo, &fi_descript); // olhar para o FIFO
		time_out.tv_sec = 10; // TIMEOUT
		time_out.tv_usec = 0;

		response_select = select(fd_client_fifo+1,&fi_descript,NULL,NULL,&time_out);


		if(response_select > 0 && FD_ISSET(fd_client_fifo,&fi_descript)){

			//cliente lê resposta vinda do árbitro
			res_size = read(fd_client_fifo, &response, sizeof(user));

			

			// se o arbritro responder com a string USADO temos de usar outro nome
			if(strcmp(response.response, "USADO") == 0){
			printf("Outro nome: ");
			scanf(" %s", client.name);

			// volta a enviar informação para o árbitro com informacao do novo nome
			write(fd_server_fifo, &client, sizeof(user));

			}

			// se o arbitro responder com a string INSCRITO significa que correu tudo bem
			else if(strcmp(response.response, "INSCRITO") == 0){
				client.registered = response.registered;
				strcpy(response.response, "");
				char name[4];
				char a[6] ="a_";
				sprintf(name, "%d", client.user_id);
				strcat(a,name);

				// abrimos o fifo para a comunicacao com o jogo
				fd_game_fifo = open(a, O_RDWR);


			// MAXPLAYERS chegou ao limite, nao aceita mais clientes
			}else if(strcmp(response.response, "MAXPLAYERS") == 0){
				printf("\nÁrbitro lotado, tente depois\n");
				break;

			// cliente expulso pelo árbitro
			}else if(strcmp(response.response, "EXPULSO") == 0){
				start = 0;
				block= 0;
				printf("\nFoi removido do campeonato\n");

			// cliente desistiu do campeonato e fez #sair
			}else if(strcmp(response.response, "ADEUS") == 0){
				printf("\nA fechar...\n");
				break;

			// o arbitro avisa que o campeonato vai comecar
			}else if(strcmp(response.response, "START") == 0){
				start = 1;
				printf("\nCampeonato comecou\n");

			// o arbitro bloqueia a comunicacao entre cliente e jogo
			}else if(strcmp(response.response, "BLOCK") == 0){
				printf("\nComunicacao bloqueada\n");
				block = 1;

			// o arbitro desbloqueia a comunicacao entre cliente e jogo
			}else if(strcmp(response.response, "UNBLOCK") == 0){
				printf("\nComunicacao desbloqueada\n");
				block = 0;

			// o arbitro avisa que o campeonato acabou
			}else if(strcmp(response.response, "END") == 0){
				printf("Fim do campeonato\n");
				start = 0;
				block = 0;

			// o arbitro avisa que terminou
			}else if(strcmp(response.response, "FECHO") == 0){
				printf("\nO arbitro fechou\n");
				break;

			// o arbitro avisa que esta um Campeonato em curso
			}else if(strcmp(response.response, "CAMP") == 0){
				printf("\nEsta a decorrer um campeonato -Tente mais tarde\n");
				break;
			}else{
				printf("%s\n", response.response);
			}
			
			for(int i = 0; i < sizeof(response.response); i++)
        		response.response[i] = '\0';


        // atende caso o cliente escreva no STDIN os seus comandos
		}else if(response_select > 0 && FD_ISSET(0,&fi_descript)){

			// se a comunicacao entre jogo e cliente nao estiver bloqueada
			if(block != 1){
				scanf(" %s", client.command);
				
				//limpa buffer
				char c ;
				while((c= getchar()) != '\n' && c != EOF);

				// se o utilizar escrever #sair bloqueamos até o campeonato terminar
				if (strcmp(client.command,"#sair") == 0 && start == 1){
					printf("\nEm campeonato\n");
				}

				else if(client.command[0] == '#' || start == 0){
					write(fd_server_fifo, &client, sizeof(user));
				}

				// se estiver a decorrer um campeonato e a comunicacao nao estiver bloqueada
				else if(start == 1 && block == 0){
					write(fd_game_fifo, &client, sizeof(user));
				}
				else 
					continue;
			}
			// limpamos o command enviado
			for(int i = 0; i < sizeof(client.command); i++)
        		client.command[i] = '\0';
		}
	}

	// fecha os fifos
	close(fd_client_fifo);
	close(fd_server_fifo);
	close(fd_game_fifo);

	// apaga o FIFO
	unlink(cli_fifo);
	return 0;
}
