#include "referee.h"


// retorna -1 se nao existirem nomes iguais senao retorna a posicao
int name_exist(char* name, player_ptr array_plr, int* n_players){
	for(int i = 0; i < *n_players; i++){
		if(strcmp(array_plr[i].client.name, name) == 0){
			return i;
		}
	}
	return -1;
}


// retorna um ponteiro para um array de estruturas do tipo user_ptr
player_ptr add_player(int* n_players, player_ptr array_plr, user_ptr new_user){
	if(*n_players == 0){
		array_plr = malloc(sizeof(player));
		if(array_plr == NULL){
    		printf("Erro na alocacao de memoria\n");
	    	free(array_plr);
	    	return(NULL);
		}
	}else{

		if(name_exist(new_user->name, array_plr, n_players) > -1){
			return NULL;
		}

		player_ptr aux;
		aux = realloc(array_plr, sizeof(player)*(*n_players +1));
        if(aux == NULL){
            printf("Erro na realocacao de memoria2\n");
            free(aux);
            return(NULL);
        }
        
        array_plr = aux;

	}

	//Copia a informacao
	strcpy(array_plr[*n_players].client.name, new_user->name); //copia o nome para a struct player struct
	array_plr[(*n_players)].client.user_id = new_user->user_id; //copia o id
	array_plr[(*n_players)].client.registered = 1;				// faz set do registro para 1
	array_plr[(*n_players)].client.pont = new_user->pont;		

	array_plr[(*n_players)].on_game = -1;
	array_plr[(*n_players)].play.id = -1;

	(*n_players)++;
	return array_plr;
}

//remover jogador do array dinâmico
player_ptr remove_player(int* n_players, player_ptr array_plr, user_ptr old_user, int pos){
	if(*n_players > 1){
		array_plr[pos] = array_plr[*n_players-1];

		player_ptr aux;
		aux = realloc(array_plr, sizeof(player)*(*n_players -1));
	    if(aux == NULL){
	        printf("[ERRO] na realocacao de memoria\n");
	        free(aux);
	        return NULL;
	    }
	    
	    array_plr = aux;
		(*n_players)--;

		return array_plr;
	}else{
		free(array_plr);
		*n_players = 0;
		return NULL;
	}

}

//lista todos os players no jogo
void names(player_ptr array_plr, int n_players){
	printf("%d\n", n_players );
	for(int i = 0 ; i< n_players; i++)
		printf("Nome %s-- ID %d -- Comando  %s\n", array_plr[i].client.name, array_plr[i].client.user_id, array_plr[i].client.command);
}

//listar jogos disponiveis
void list_games(games_ptr array_games, int n_games){
	for(int i = 0; i < n_games; i++){
		printf("%s\n", array_games[i].game_name);
	}
}

//adiciona jogos ao array dinamico
games_ptr add_game(int* n_games, games_ptr array_games, char* game_name){
	if(*n_games == 0){
		array_games = malloc(sizeof(games));
		if(array_games == NULL){
    		printf("Erro na alocacao de memoria\n");
	    	free(array_games);
	    	return(NULL);
		}
	}else{

		games_ptr aux;
		aux = realloc(array_games, sizeof(games)*(*n_games +1));
        if(aux == NULL){
            printf("Erro na realocacao de memoria2\n");
            free(aux);
            return(NULL);
        }
        
        array_games = aux;
	}

	strcpy(array_games[*n_games].game_name, game_name);
	(*n_games)++;
	return array_games;
}

//Comandos do arbitro
int commands(char* c, player_ptr array_plr, int n_players, games_ptr array_games, int n_games, int* pos){
	if(strcmp(c, "players") == 0){
		names(array_plr, n_players);
		return 0;

	}else if(strcmp(c, "games") == 0){
		//  listar jogos na directoria
		list_games(array_games,n_games);
		return 0;

	}else if('k' == c[0]){
		//envia mensagem para o jogador deixar de jogar
		char nome[strlen(c)-1];
		for(int i = 0 ; i < strlen(nome); i++)
			nome[i] = c[i+1];

		if((*pos = name_exist(nome, array_plr, &n_players)) == -1){
			printf("Jogador nao existente\n");
			return -1;
		}else{
			if(array_plr[*pos].on_game == 1){
				array_plr[*pos].on_game = -1;
				printf("Retirado jogador -> %s\n", nome);

			}else{
				printf("Nao esta em jogo\n");
				return -1;
			}
		}
		return 1; //se correr tudo bem manda mensagem ao client

	}else if('s' == c[0]){
		//bloquear comunicacao jogador jogo
		return 2;

	}else if('r' == c[0]){
		//permitir novamente comunicacao jogador jogo
		return 3;
	}

	return -1;
}

//comandos do jogador
int exCommand(player_ptr array_plr,  user_ptr client_info, int pos, int* n_players){
	if(strcmp(array_plr[pos].client.command, "#mygame") == 0){
		strcpy(array_plr[pos].client.response, "O teu jogo");
		return 0;

	}else if((strcmp(array_plr[pos].client.command, "#quit")) == 0){
		strcpy(array_plr[pos].client.response, "saiu do jogo");
		array_plr[pos].on_game = -1;
		return 0;

	}else if((strcmp(array_plr[pos].client.command, "#sair")) == 0){

		//se for para sair, removemos o cliente
		player_ptr aux = remove_player(n_players, array_plr, client_info, pos);
		if(aux != NULL && n_players > 0) //se a alocacao falhar
			array_plr = aux;

		else if(aux == NULL && n_players == 0 ) //se nao tiver clientes
			array_plr = aux;

		strcpy(client_info->response, "ADEUS");
		return 1;
	}else
		strcpy(array_plr[pos].client.response, "Comando nao existe");

	return 0;
}





int main(int argc, char const *argv[])
{
	char *gameDir, *maxPlayers;// variaveis de ambiente
	int max_players; // armazena var de ambiente
	int waitTime = WAIT_TIME, champDur = CHAMP_DURATION; // args

	int n_players = 0, n_games = 0; //num de jogadores e jogos
	int res_size,client_pid;
	int fd_server_fifo,fd_cli_fifo;
	int response_select;

	player_ptr array_plr = NULL; // ponteiro para array din de players
	user client_info; // estrutura de leitura vinda do cliente para o servidor
	
	games_ptr array_games = NULL; // ponteiro para array de jogos disponiveis

	char new_cli_fifo[32]; //string usada para altera o nome do FIFO do cliente
	char referee_cmd[20]; // comandos do árbitro

	fd_set fi_descript; // vai guardar os file descriptors existentes
	struct timeval time_out; // var para o TIMEOUT

	setbuf(stdout,NULL);



	/*=======================1ª meta=============================*/

	gameDir = getenv("GAMEDIR");
	if(gameDir == NULL){
		gameDir = "."; // diretoria atual
	}
	else{

		DIR* dir = opendir(gameDir);
		// se o GAMEDIR existir
		if (dir) {
			closedir(dir);
		} 
		else if (ENOENT == errno){
			printf("GAMEDIR Nao existe...\n");
			exit(3); 
		}
	}


	maxPlayers = getenv("MAXPLAYERS");
	if(maxPlayers == NULL){
		printf("[ERROR] environment MAXPLAYERS\n");
		exit(1);
	}
	max_players = atoi(maxPlayers); //existe var ambiente para int
	if(max_players > 30 || max_players <= 0){
		printf("[ERROR] environment MAXPLAYERS (>0 <30)\n");
		exit(1);
	}
	
	if(argc == 3){
		if(atoi(argv[1]) > 0)
			champDur = atoi(argv[1]);

		if(atoi(argv[2]) > 0)
			waitTime = atoi(argv[2]);
	}else if(argc != 1){
		printf("[ERROR] Invalid number of arguments\n");
		exit(1);
	}


	/*=======================2ª Meta=============================*/

	struct dirent **namelist;
	int n;
	n = scandir(gameDir,&namelist, NULL, alphasort);
	if(n==-1){ 
		printf("[ERRO]: scandir"); 
		exit(3);
	}

	// verifica que jogos estao disponiveis
	while(n--){
		if (namelist[n]->d_name[0] == 'g' && namelist[n]->d_name[1] == '_')
		{
			if(namelist[n]->d_name[strlen(namelist[n]->d_name)-2] != '.')
				array_games = add_game(&n_games, array_games, namelist[n]->d_name);
		}
		
		free (namelist[n]);
	}
	free(namelist);
	if(n_games == 0){
		printf("Nao existem jogos na diretoria\n");
		exit(3);
	}


	//verifica se ja existe algum árbitro a executar
	if(access(REF_FIFO, F_OK) == 0){
		printf("Árbitro ja a executar\n");
		exit(2);
	}
	
	mkfifo(REF_FIFO, 0600);
	printf("Criei o FIFO do Árbitro...\n");

	// abri o fifo
	fd_server_fifo = open(REF_FIFO,O_RDWR);

	
	if((fd_server_fifo) == -1){
		printf("Erro na Abertura\n");
		exit(2);
	}




	while(1){

		// iniciar o tratamento do select

		FD_ZERO(&fi_descript); // limpar os file descriptors do select
		FD_SET(0,&fi_descript); // atribui ao STDIN
		FD_SET(fd_server_fifo, &fi_descript); // olhar para o FIFO
		time_out.tv_sec = 10; // TIMEOUT
		time_out.tv_usec = 0;



		response_select = select(fd_server_fifo+1,&fi_descript,NULL,NULL,&time_out);

		if(response_select == 0){

			printf("Aguardando dados ->\n");
		}

		//stdin
		else if(response_select > 0 && FD_ISSET(0,&fi_descript)){
			int command_response, pos;
			scanf("%s", referee_cmd);

			if(strcmp(referee_cmd,"exit") == 0)
				//enviar mensagem aos clientes que o servidor fechou
				break;

			//comandos do árbitro
			command_response = commands(referee_cmd, array_plr, n_players, array_games, n_games, &pos);
			
			switch(command_response){
				case 0: break;

				case 1:
					client_pid = array_plr[pos].client.user_id;
					strcpy(array_plr[pos].client.response,"EXPULSO");

					sprintf(new_cli_fifo,CLI_FIFO,client_pid);

					fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
					write(fd_cli_fifo, &array_plr[pos].client , sizeof(user));
					break;

				case 2:
					//nao funcional
					break;

				case 3:
					//nao funcional
					break;

				default:
					printf("Nada aconteceu\n");
					break;
			}
			
		}

		//fifos do árbitro
		else if(response_select > 0 && FD_ISSET(fd_server_fifo,&fi_descript)){

			player_ptr aux = array_plr;

			//lemos a instrução vinda do Cliente
			res_size = read(fd_server_fifo, &client_info, sizeof(client_info));



			if(res_size <= sizeof(client_info)){
				
				// se o cliente nao esta registado		
				if(client_info.registered == 0){

					//verifica se o MAXPLAYERS nao foi atingido
					if(n_players < max_players){

						//tenta adicionar o cliente ao array dinamico de jogador
						if((aux = add_player(&n_players,aux, &client_info)) != NULL  ){

							//sendo assim nao existe nomes iguais
							array_plr = aux;

							//cliente inscrito e notificado
							client_pid = client_info.user_id; 
							strcpy(array_plr[n_players-1].client.response,"INSCRITO");

							sprintf(new_cli_fifo,CLI_FIFO,client_pid);

							fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
							write(fd_cli_fifo, &array_plr[n_players-1].client , sizeof(user));
						}


						// o nome do cliente já existe
						else{
								// abertura do FIFO do cliente correto e notificação
								client_pid = client_info.user_id;
								strcpy(client_info.response,"USADO");

								sprintf(new_cli_fifo,CLI_FIFO,client_pid);

								fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
								write(fd_cli_fifo, &client_info, sizeof(user));
						}

					//atingido o maxplayers ,notifica o client		
					}else{
						
						strcpy(client_info.response, "MAXPLAYERS");
						client_pid = client_info.user_id;
						sprintf(new_cli_fifo,CLI_FIFO,client_pid);

						fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
						write(fd_cli_fifo, &client_info, sizeof(user));
				}


			//cliente já esta registado
			}else{

				//atualiza o commando no array de clientes
				int pos = name_exist(client_info.name, array_plr, &n_players);
				if(pos > -1){
					strcpy(array_plr[pos].client.command , client_info.command);

					//executa commando do cliente e responde com o mesmo
					if(array_plr[pos].client.command[0] == '#'){
						int ex = exCommand(array_plr, &client_info, pos, &n_players);

						client_pid = client_info.user_id;
						

						sprintf(new_cli_fifo,CLI_FIFO,client_pid);

						fd_cli_fifo = open(new_cli_fifo,O_WRONLY);

						//para sair usamos o #sair recebido no read 
						if(ex == 1){
							write(fd_cli_fifo, &client_info, sizeof(user));
							
						//usamos o array quando é um comando normal
						}else
							write(fd_cli_fifo, &array_plr[pos].client, sizeof(user));


					}else{
						//mandar para o jogo
						//por agora responde o que lhe mandou
						strcpy(array_plr[pos].client.response, array_plr[pos].client.command);

						client_pid = array_plr[pos].client.user_id;
						sprintf(new_cli_fifo,CLI_FIFO,client_pid);

						fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
						write(fd_cli_fifo, &array_plr[pos].client, sizeof(user));

					}
				}
			}
		}

	}


}
	

	printf("\n\nChampionship duration: %d\n",champDur);
	printf("Waiting time: %d\n",waitTime);
	printf("GAMEDIR: %s\n", gameDir);
	printf("MAXPLAYERS: %d\n",max_players);
	close(fd_server_fifo);
	unlink(REF_FIFO);

	
	exit(1);
}


