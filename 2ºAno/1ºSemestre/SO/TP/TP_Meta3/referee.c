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

//avisar todos os clientes do comeco do campeonato
void start_notice(int n_players, player_ptr array_plr){
	for(int i = 0 ; i < n_players; i++){
		int cli_pid = array_plr[i].client.user_id;
		strcpy(array_plr[i].client.response,"START");

		char cli_fifo[32];
		sprintf(cli_fifo,CLI_FIFO,cli_pid);

		int fd_client_fifo = open(cli_fifo,O_WRONLY);
		write(fd_client_fifo, &array_plr[i].client , sizeof(user));
		array_plr[i].on_game = 1;
	}
	
}

//avisar todos os clientes do fim do campeonato
void end_notice(int n_players, player_ptr array_plr){
	for(int i = 0 ; i < n_players; i++){
		if(array_plr[i].on_game == 1){
			int cli_pid = array_plr[i].client.user_id;
			strcpy(array_plr[i].client.response,"END");

			char cli_fifo[32];
			sprintf(cli_fifo,CLI_FIFO,cli_pid);

			int fd_client_fifo = open(cli_fifo,O_WRONLY);
			write(fd_client_fifo, &array_plr[i].client , sizeof(user));
			array_plr[i].on_game = -1; 
		}
	}
	
}

//avisar todos os clientes da saida do arbitro
void exit_notice(int n_players, player_ptr array_plr){
	for(int i = 0 ; i < n_players; i++){
		int cli_pid = array_plr[i].client.user_id;
		strcpy(array_plr[i].client.response,"FECHO");

		char cli_fifo[32];
		sprintf(cli_fifo,CLI_FIFO,cli_pid);

		int fd_client_fifo = open(cli_fifo,O_WRONLY);


		write(fd_client_fifo, &array_plr[i].client , sizeof(user));
		array_plr[i].on_game = -1;
	}
	
}

// avisa todos os clientes do maior score do campeonato atual
void send_score(int n_players, player_ptr array_plr){
	int best = 0;
	int pos = 0;

	// guarda maior score do campeonato
	for(int i = 0; i < n_players; i++){
		if(best < array_plr[i].client.pont){
			best = array_plr[i].client.pont;
			pos = i;
		}
	}



	for(int i = 0; i < n_players; i++){

		int cli_pid = array_plr[i].client.user_id;
		char cli_fifo[32];
		sprintf(cli_fifo,CLI_FIFO,cli_pid);
		int fd_client_fifo = open(cli_fifo,O_WRONLY);

		char message[128];

		sprintf(message,"O teu Resultado: [%d] -- Melhor Resultado: [%d] de [%s]", array_plr[i].client.pont, best, array_plr[pos].client.name);

		strcpy(array_plr[i].client.response, message);

		write(fd_client_fifo, &array_plr[i].client , sizeof(user));

		array_plr[i].client.pont = -1;
	}
}

// retorna um ponteiro para um array de estruturas do tipo user_ptr , serve para adicionar um novo jogador
player_ptr add_player(int* n_players, player_ptr array_plr, user_ptr new_user){
	if(*n_players == 0){
		array_plr = malloc(sizeof(player));
		if(array_plr == NULL){
    		printf("Erro na alocacao de memoria\n");
	    	free(array_plr);
	    	return NULL;
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
            return NULL;
        }

        array_plr = aux;

	}

	//Copia a informacao
	strcpy(array_plr[*n_players].client.name, new_user->name); //copia o nome para a struct player struct
	array_plr[(*n_players)].client.user_id = new_user->user_id; //copia o id
	array_plr[(*n_players)].client.registered = 1;				// faz set do registro para 1
	array_plr[(*n_players)].client.pont = new_user->pont;

	array_plr[(*n_players)].on_game = -1;

	(*n_players)++;
	return array_plr;
}

//remove jogador do array dinâmico (pega no ultimo e coloca na posicao do jogador a remover e depois faz realloc de -1 apagando assim a ultima posicao)
player_ptr remove_player(int* n_players, player_ptr array_plr, user_ptr old_user, int pos){
	char name[4];
	char a[6] ="a_";
	sprintf(name, "%d", array_plr[pos].client.user_id);
	strcat(a,name);

	if(*n_players > 1){

		//apaga o fifo a_
		unlink(a);

		if(pos != *n_players-1)
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

	}else if(*n_players == 1){

		//apaga o fifo a_
		unlink(a);

		free(array_plr);
		*n_players = 0;
		return NULL;
	}

}

//lista todos os jogadores no jogo
void names(player_ptr array_plr, int n_players){
	printf("%d\n", n_players );
	for(int i = 0 ; i< n_players; i++)
		printf("Nome [%s] - ID [%d] - Comando[%s] \n", array_plr[i].client.name, array_plr[i].client.user_id, array_plr[i].client.command);
}

//listar todos jogos disponiveis
void list_games(games_ptr array_games, int n_games){
	for(int i = 0; i < n_games; i++){
		printf("Jogo[%d] - %s\n",i+1, array_games[i].game_name);
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

//comandos do arbitro
int commands(char* c, player_ptr array_plr, int n_players, games_ptr array_games, int n_games, int* pos){
	char nome[26];

	// se o arbitro escrever "players"
	if(strcmp(c, "players") == 0){
		names(array_plr, n_players);
		return 0;

	// se o arbitro escrever "games"
	}else if(strcmp(c, "games") == 0){
		//  listar jogos na directoria
		list_games(array_games,n_games);
		return 0;

	// se o arbitro usar o comando k
	}else if('k' == c[0]){
		//envia mensagem para o jogador deixar de jogar
		strcpy(nome,c);
		for(int i = 0 ; i < strlen(nome); i++)
			nome[i] = c[i+1];

		// verifica a existencia do jogador
		if((*pos = name_exist(nome, array_plr, &n_players)) == -1){
			printf("Jogador nao existente\n");
			return -1;
		}else{
			if(array_plr[*pos].on_game == 1){
				array_plr[*pos].on_game = -1;
				printf("Retirado o jogador -> [%s]\n", nome);

			}else{
				printf("Nao esta em jogo\n");
				return -1;
			}
		}
		return 1; //se correr tudo bem manda mensagem ao client

	// se o arbitro usar o comando s
	}else if('s' == c[0]){
		//bloquear comunicacao jogador jogo
		strcpy(nome,c);

		for(int i = 0 ; i < strlen(nome); i++)
			nome[i] = c[i+1];

		// verifica a existencia do jogador
		if((*pos = name_exist(nome, array_plr, &n_players)) == -1){
			printf("Jogador nao existente\n");
			return -1;
		}

		return 2;

	// se o arbitro usar o comando r
	}else if('r' == c[0]){
		//permitir novamente comunicacao jogador jogo
		strcpy(nome,c);
		for(int i = 0 ; i < strlen(nome); i++)
			nome[i] = c[i+1];

		// verifica a existencia do jogador
		if((*pos = name_exist(nome, array_plr, &n_players)) == -1){
			printf("Jogador nao existente\n");
			return -1;
		}
		return 3;
	}

	return -1;
}

//comandos do jogador
int exCommand(player_ptr array_plr,  user_ptr client_info, int pos, int* n_players){

	// se o cliente escrever #mygame,  verifica se esta em jogo e envia a descricao do jogo
	if(strcmp(array_plr[pos].client.command, "#mygame") == 0){
		if(array_plr[pos].on_game == 1)
			strcpy(array_plr[pos].client.response, array_plr[pos].play.desc);
		else
			strcpy(array_plr[pos].client.response, "Nao esta em jogo\n");

		return 0;


	// se cliente escrever #quit envia um END e retira o cliente do campeonato
	}else if((strcmp(array_plr[pos].client.command, "#quit")) == 0){
		strcpy(array_plr[pos].client.response, "END");
		array_plr[pos].on_game = -1;
		return 0;

	}else if((strcmp(array_plr[pos].client.command, "#sair")) == 0){

		//se for para sair, removemos o cliente
		if(array_plr[pos].on_game == 1){
			strcpy(array_plr[pos].client.response, "Em jogo\n");
		}

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


//limpar a estrutura do jogo
void clean(player_ptr array_plr, int n_players){

	for(int i = 0 ; i < n_players; i++){
		for(int j = 0; j < sizeof(array_plr[i].play.game_name); j++)
    		array_plr[i].play.game_name[j] = '\0';

    	for(int j = 0; j < sizeof(array_plr[i].play.desc); j++)
    		array_plr[i].play.desc[j] = '\0';

    	for(int j = 0; j < sizeof(array_plr[i].play.path); j++)
    		array_plr[i].play.path[j] = '\0';

	}
}




//thread responsavel por fazer o redirecionamento entre clientes e jogos
void* fork_game(void *t){
    player_ptr jogador;
    jogador = (player_ptr)t;
    int res, pid, state, channel_out[2], channel_in[2];
    int *res_game = (int *)malloc(sizeof(int));
    
    *res_game = 0;



    // fazer os forks dos jogos e o redirecionamento entre FIFOs e unnamed pipes
    pipe(channel_in);
    pipe(channel_out);
    res = fork(); // cria o processo filho

    // se for o filho
    if(res == 0){
        // unnamed out (channel_out = STDOUT do jogo)
        close(STDOUT_FILENO);
        dup(channel_out[1]);
        close(channel_out[1]);
        close(channel_out[0]);

        // unnamed in (channel_in = STDIN do jogo)
        close(STDIN_FILENO);        
        dup(channel_in[0]);
        close(channel_in[0]);
        close(channel_in[1]);

        // exec
        execl(jogador->play.path, jogador->play.game_name, NULL);// chama o jogo
        
        printf("Erro , nao consegui executar o jogo ...%d\n",pid);
        exit(7);
    }else{

    	// unnamed out
	    close(channel_out[1]);

	    // unnamed in
	    close(channel_in[0]);
		
	    // criacao do fifo do jogo
		char name[4];
		char a[6] ="a_";
		sprintf(name, "%d", jogador->client.user_id);
		strcat(a,name);
		int game_fd = open(a, O_RDWR);


        user player_info;
        char new_jog_fifo[32];

        int jogador_pid = jogador->client.user_id;

		sprintf(new_jog_fifo,CLI_FIFO,jogador_pid);

		int fifo_jogador = open(new_jog_fifo,O_WRONLY);

		int nbytes;	

		int response_select;
		fd_set fi_descript; // vai guardar os file descriptors existentes
		struct timeval time_out; // var para o time_out
		int maxSelect = 0;
		int flagDescGame = 0;

        while(1){

        	// se o jogador nao estiver no jogo, fazemos break do while para terminar esta thread
        	pthread_mutex_lock(jogador->player_trinco);
        	if(jogador->on_game == -1){
        		pthread_mutex_unlock(jogador->player_trinco);
        		break;
        	}
        	pthread_mutex_unlock(jogador->player_trinco);


        	FD_ZERO(&fi_descript); // limpar os file descriptors do select
			FD_SET(channel_out[0], &fi_descript); // olhar para o channel out
			FD_SET(game_fd, &fi_descript); // olhar para o game_fd
			time_out.tv_sec = 10; // TIMEOUT
			time_out.tv_usec = 0;

			// vemos qual é o fd maior para usarmos o select
			if(game_fd > channel_out[0]){
				maxSelect = game_fd;
			}
			else
				maxSelect = channel_out[0];

			response_select = select(maxSelect+1,&fi_descript,NULL,NULL,&time_out);
        	
			// se for do channel_out[0](resposta do jogo)
        	if(response_select > 0 && FD_ISSET(channel_out[0],&fi_descript)){

        		// ler do jogo
        		if((nbytes = read(channel_out[0], &(jogador->client.response), sizeof(jogador->client.response)-1)) == -1){
        			printf("ERRO\n");
        			exit(-1);
        		}

        		//flag para guardar a descricao do jogo
        		if(!flagDescGame){
        			strcpy(jogador->play.desc,jogador->client.response);
        			flagDescGame = 1;
        		}

        		// terminamos de maneira correta a resposta
        		jogador->client.response[nbytes]='\0';
        	

	        	//escreve no pipe do cliente
	        	write(fifo_jogador, &(jogador->client), sizeof(user));

	        	// limpa a resposta vinda do jogo
	        	for(int i = 0; i < sizeof(jogador->client.response); i++)
	        		jogador->client.response[i] = '\0';
        	}
        	
        	// se for do game_fd(resposta do cliente)
        	if(response_select > 0 && FD_ISSET(game_fd,&fi_descript)){

				//lê do pipe do cliente
				read(game_fd, &player_info, sizeof(user));

				// termina corretamente a informacao vinda do cliente
				player_info.command[strlen(player_info.command)+1]='\0';
				player_info.command[strlen(player_info.command)]='\n';


				// escreve resposta do cliente no jogo
				write(channel_in[1], &(player_info.command),strlen(player_info.command));

				// limpa a informacao vinda do cliente
				for(int i = 0; i < sizeof(player_info.command); i++)
	        		player_info.command[i] = '\0';


			}
    	}

    	//manda um sinal ao jogo
    	kill(res, SIGUSR1);

    	//WEXITSTATUS -> dá o score do jogo
    	wait(&state);
	    if(WIFEXITED(state) || WIFSIGNALED(state)){
	        printf("\nO Jogo [%d] terminou com Score = [%d]\n",res,WEXITSTATUS(state));
	        *res_game = WEXITSTATUS(state);
	 	}

	    //fecha o fifo a_
    	close(game_fd);

	}
	//termina a thread
    pthread_exit(res_game);

}

//thread responsavel por fazer a temporizacao do campeonato
void* thread_timer(void* t){
	mainframe_ptr data;
	data = (mainframe_ptr)t;
    pthread_t fork_games[*data->n_players];

    srand(time(0));
    int rand_number;

   	struct timespec time;
   	
   	time.tv_nsec=0;

	while(data->flag){
		time.tv_sec = data->wait;
		nanosleep(&time, NULL);
		//sleep(data->wait);

		//começa o campeonato
		pthread_mutex_lock(data->ptrinco);//mutex
		data->game_start = 1;
		pthread_mutex_unlock(data->ptrinco);//fim 

		
		printf("\nO campeonato comecou....\n");

		//se existem pelo menos 2 jogadores 
		if(*data->n_players >= 2 && data->flag){

			pthread_mutex_lock(data->ptrinco);//mutex
			start_notice(*data->n_players, data->array_plr);
			pthread_mutex_unlock(data->ptrinco);//fim 
        	
        
        	//criar a thread dos jogos (fork_game)
        	for(int i = 0; i < *data->n_players; i++){
        		rand_number= rand()%data->n_games;
        		int n_size = strlen(data->array_games[rand_number].game_name) + strlen(data->direct);

        		char game_path[n_size];

        		int flag = 1;
        		int j = 0;

        		// guarda o game_path
        		if(data->direct[0] != '.'){
        			for(int i = 0; i < n_size ; i++){
        				if(data->direct[i] == '\0' || data->direct[i] == EOF){
        					break;
        				}

    					game_path[i] = data->direct[i];
    					j = i;
        			}

        			game_path[j+ 1] = '/';
        			for(int i = 0 ; i < n_size; i++){
	        			if(data->array_games[rand_number].game_name[j] == ' ' || data->array_games[rand_number].game_name[j] == EOF)
	        				break;
	        			
	        			game_path[j+i+2] = data->array_games[rand_number].game_name[i];
        			
        			}


    			}else{
    				// escolhe um jogo aleatorio
    				for(int i = 0 ; i < n_size; i++){
        				if(data->array_games[rand_number].game_name[j] == ' ' || data->array_games[rand_number].game_name[j] == EOF)
        				break;
        			
        				game_path[i] = data->array_games[rand_number].game_name[i];
        			
        			}
    			}

        		
        		
    			// copia o game_path para o play.path e o game_name para o game_name da estrutura
	       		strcpy(data->array_plr[i].play.path, game_path);
        		strcpy(data->array_plr[i].play.game_name, data->array_games[rand_number].game_name);

        		// cria as threads fork_game
            	pthread_create(&fork_games[i],NULL,fork_game,(void *)&data->array_plr[i]);
        	}

        	
        	// conta o tempo do campeonato
        	time.tv_sec = data->champDur;
        	nanosleep(&time, NULL);
			
        	// esta flag serve para saber se o arbitro fez ou nao "exit"
        	if(!data->flag){
        		break;
        	}

        	// avisa os clientes do fim do campeonato
			pthread_mutex_lock(data->ptrinco);//mutex
			end_notice(*data->n_players, data->array_plr);
			pthread_mutex_unlock(data->ptrinco);//fim 


			// espera pelo fim da thread fork_game
			int *response_game;
			for(int i = 0; i < *data->n_players; i++){
				pthread_join(fork_games[i], (void*)&response_game);

				//guarda a pontuação no campo do cliente
				data->array_plr[i].client.pont = *response_game;			

				free(response_game);
			}

			// envia score para os jogadores 
			pthread_mutex_lock(data->ptrinco);//mutex
			send_score(*data->n_players, data->array_plr);			

			//limpa o game depois do campeonato acabar
			clean(data->array_plr, *data->n_players);

			data->game_start = 0;
			pthread_mutex_unlock(data->ptrinco);//fim 




		}else{
			printf("Só existe um jogador ... aguardando a entrada de outros\n");
			break;
		}

	}

	int* res_timer;
	res_timer = (int*) malloc(sizeof(int));
	*res_timer = 0;
	pthread_exit(res_timer);
}

//thread responsavel por registar os clientes no campeonato
void* thread_register(void* t){
	pthread_t thread_time;
	mainframe_ptr data = (mainframe_ptr)t;

	int* res_register;
	res_register = (int*) malloc(sizeof(int));
	*res_register = 0;

	int res_size,client_pid;
	int fd_server_fifo,fd_cli_fifo;

	player_ptr aux = data->array_plr;
	user client_info;

	char new_cli_fifo[32]; //string usada para altera o nome do FIFO do cliente


	mkfifo(REF_FIFO, 0600);

	// abri o fifo
	fd_server_fifo = open(REF_FIFO,O_RDWR);

	if((fd_server_fifo) == -1){
		printf("Erro na Abertura\n");
		exit(2);
	}

	// enquanto o arbitro nao fizer "exit"
	while(data->flag){

		res_size = read(fd_server_fifo, &client_info, sizeof(client_info));

		if(!data->flag)
			break;

		pthread_mutex_lock(data->ptrinco);

		if(res_size <= sizeof(client_info)){

			// se o cliente nao esta registado
			if(client_info.registered == 0){

				if(data->game_start){
					//caso esteja a decorrer um campeonato
					strcpy(client_info.response, "CAMP");
					client_pid = client_info.user_id;
					sprintf(new_cli_fifo,CLI_FIFO,client_pid);

					fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
					write(fd_cli_fifo, &client_info, sizeof(user));
				}
				
				//verifica se o MAXPLAYERS nao foi atingido
				else if((*data->n_players) < data->max_players){

					//tenta adicionar o cliente ao array dinamico de jogadores
					if((aux = add_player(data->n_players,data->array_plr, &client_info)) != NULL  ){
						data->array_plr = aux;
						(*res_register)++;

						printf("Jogador [%s] adicionado\n",client_info.name);

						//sse existirem pelo menos 2 jogadores, cria a thread to tempo do campeonato
						if((*data->n_players) == 2){
							pthread_create(&thread_time, NULL, thread_timer, (void*)data);
						}

						//criacao do fifo de comunicacao
						char name[4];
						char a[6] ="a_";
						sprintf(name, "%d", client_info.user_id);
						strcat(a,name);
						mkfifo(a, 0600);

						//inicializa o mutex do ultimo jogador criado
						data->array_plr[(*data->n_players)-1].player_trinco = data->ptrinco; 

						//cliente inscrito e notificado
						client_pid = client_info.user_id;
						strcpy(data->array_plr[(*data->n_players)-1].client.response,"INSCRITO");

						sprintf(new_cli_fifo,CLI_FIFO,client_pid);

						fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
						write(fd_cli_fifo, &data->array_plr[(*data->n_players)-1].client , sizeof(user));
					}else{
						// o nome que o cliente escolheu ja esta usado
						client_pid = client_info.user_id;
						strcpy(client_info.response,"USADO");

						sprintf(new_cli_fifo,CLI_FIFO,client_pid);

						fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
						write(fd_cli_fifo, &client_info, sizeof(user));
					}
				}
				//atingido o maxplayers ,notifica o cliente
				else{

					strcpy(client_info.response, "MAXPLAYERS");
					client_pid = client_info.user_id;
					sprintf(new_cli_fifo,CLI_FIFO,client_pid);

					fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
					write(fd_cli_fifo, &client_info, sizeof(user));
				}

			}else{//ler comandos do cliente
				if(client_info.command[0] == '#'){

					//atualiza o commando no array de clientes
					int pos = name_exist(client_info.name, data->array_plr, data->n_players);
					if(pos > -1){
						strcpy(data->array_plr[pos].client.command , client_info.command);

						//executa commando do cliente e responde com o mesmo

						int ex = exCommand(data->array_plr, &client_info, pos, data->n_players);

						client_pid = client_info.user_id;

						sprintf(new_cli_fifo,CLI_FIFO,client_pid);
						fd_cli_fifo = open(new_cli_fifo,O_WRONLY);

						//para sair usamos o #sair recebido no read
						if(ex == 1){
							write(fd_cli_fifo, &client_info, sizeof(user));
						//usamos o array quando é um comando normal
						}else
							write(fd_cli_fifo, &(data->array_plr[pos].client), sizeof(user));
					}
				}
			}

		}

		//unlock
		pthread_mutex_unlock(data->ptrinco);
	}

	//espera pela thread time
	int *response_register;
	pthread_join(thread_time, (void*)&response_register);
	free(response_register);
	close(fd_server_fifo);
	pthread_exit(res_register);
}


int main(int argc, char const *argv[])
{
	char *gameDir, *maxPlayers;// variaveis de ambiente
	int max_players; // armazena var de ambiente
	int waitTime = WAIT_TIME, champDur = CHAMP_DURATION; // args

	int n_players = 0, n_games = 0, client_pid; //num de jogadores e jogos

	player_ptr array_plr = NULL; // ponteiro para array din de players
	user client_info; // estrutura de leitura vinda do cliente para o servidor

	games_ptr array_games = NULL; // ponteiro para array de jogos disponiveis

	int fd_cli_fifo;
	char new_cli_fifo[32];

	char referee_cmd[20]; // comandos do árbitro

	mainframe thread_struct;
	pthread_t thread_registe;

	pthread_mutex_t trinco;

	//inicializa a estrutura mainframe
	thread_struct.n_players = &n_players;
	thread_struct.array_plr = array_plr;
	thread_struct.flag = 1;
	thread_struct.game_start = 0;

	//inicializa o mutex
	pthread_mutex_init(&trinco, NULL);
	thread_struct.ptrinco = &trinco;


	

	setbuf(stdout,NULL);



	/*=======================1ª meta=============================*/

	// vai buscar a diretoria atual
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

	// trata da variavel de ambiente MAXPLAYERS
	maxPlayers = getenv("MAXPLAYERS");
	if(maxPlayers == NULL){
		printf("[Erro] MAXPLAYERS nao existe\n");
		exit(1);
	}
	max_players = atoi(maxPlayers);
	if(max_players > 30 || max_players <= 1){
		printf("[ERRO] MAXPLAYERS tem de ser (>1 <30)\n");
		exit(1);
	}
	
	// se forem passados argumentos no inicio usa-se esses argumentos
	if(argc == 3){
		if(atoi(argv[1]) > 0)
			champDur = atoi(argv[1]);

		if(atoi(argv[2]) > 0)
			waitTime = atoi(argv[2]);
	}else if(argc != 1){
		printf("[ERROR] Numero invalido de argumentos\n");
		exit(1);
	}

	//preenche mais alguns campos da estrutura mainframe
	thread_struct.wait = waitTime;
	thread_struct.champDur = champDur;
	thread_struct.max_players = max_players;
	thread_struct.direct = gameDir;

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
		int flag = 1;
		if (namelist[n]->d_name[0] == 'g' && namelist[n]->d_name[1] == '_')
		{
			
			for(int i = 0; i < strlen(namelist[n]->d_name); i++){
				if(namelist[n]->d_name[i] == '.')
					flag = 0;
			}

			if(flag){
				array_games = add_game(&n_games, array_games, namelist[n]->d_name);
			}
			
			
		}
		free (namelist[n]);
	}
	free(namelist);

	if(n_games == 0){
		printf("Nao existem jogos na diretoria\n");
		exit(3);
	}

	//preenche mais alguns campos da estrutura mainframe
	thread_struct.n_games = n_games;
	thread_struct.array_games = array_games;


	//verifica se ja existe algum árbitro a executar
	if(access(REF_FIFO, F_OK) == 0){
		printf("Árbitro ja a executar\n");
		exit(2);
	}

	

	//cria a thread do registo do campeonato
	pthread_create(&thread_registe, NULL, thread_register, (void*)&thread_struct);


	while(1){

		int command_response, pos;
		scanf("%s", referee_cmd);


		// se o arbitro escreve "exit"
		if(strcmp(referee_cmd,"exit") == 0){
			pthread_mutex_lock(thread_struct.ptrinco);
			thread_struct.flag = 0;
			pthread_mutex_unlock(thread_struct.ptrinco);

			exit_notice(*(thread_struct.n_players), thread_struct.array_plr);

			//enviamos mensagem ao proprio pipe para fechar thread
			break;
		}

		// se o arbitro escreve "end"
		else if(strcmp(referee_cmd,"end") == 0){
			end_notice(*(thread_struct.n_players), thread_struct.array_plr);
		}

		//comandos do árbitro
		command_response = commands(referee_cmd, thread_struct.array_plr, n_players, array_games, n_games, &pos);
		switch(command_response){
			case 0: break;

			case 1:
				client_pid = thread_struct.array_plr[pos].client.user_id;
				strcpy(thread_struct.array_plr[pos].client.response,"EXPULSO");

				sprintf(new_cli_fifo,CLI_FIFO,client_pid);

				fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
				write(fd_cli_fifo, &thread_struct.array_plr[pos].client , sizeof(user));
				break;

			case 2:
				client_pid = thread_struct.array_plr[pos].client.user_id;
				strcpy(thread_struct.array_plr[pos].client.response,"BLOCK");

				sprintf(new_cli_fifo,CLI_FIFO,client_pid);

				fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
				write(fd_cli_fifo, &thread_struct.array_plr[pos].client , sizeof(user));
				break;

			case 3:
				client_pid = thread_struct.array_plr[pos].client.user_id;
				strcpy(thread_struct.array_plr[pos].client.response,"UNBLOCK");

				sprintf(new_cli_fifo,CLI_FIFO,client_pid);

				fd_cli_fifo = open(new_cli_fifo,O_WRONLY);
				write(fd_cli_fifo, &thread_struct.array_plr[pos].client , sizeof(user));
				break;

			default:
				//printf("Nada aconteceu\n");
				break;
		}
			
	}



	// caso o arbitro escreva exit, temos de enviar uma mensagem para o seu fifo para nao ficar preso no read
	int fd_server_fifo = open(REF_FIFO,O_RDWR);

	if((fd_server_fifo) == -1){
		printf("Erro na Abertura\n");
		exit(2);
	}
	char sendExit = 'R';
	write(fd_server_fifo,&(sendExit),sizeof(char));



	int *res;
	pthread_join(thread_registe, (void*)&res);
	free(res);

	

	//ao sair o arbitro retirar todos os clients ligados
	for(int i = 0; i < n_players ; i++){
		user old_user;
		strcpy(old_user.name, thread_struct.array_plr[i].client.name);
		strcpy(old_user.command, thread_struct.array_plr[i].client.command);
		strcpy(old_user.response, thread_struct.array_plr[i].client.response);
		old_user.pont = thread_struct.array_plr[i].client.pont;
		old_user.user_id = thread_struct.array_plr[i].client.user_id;
		old_user.registered = thread_struct.array_plr[i].client.registered;

		remove_player(thread_struct.n_players, thread_struct.array_plr, &old_user, i);

		if(thread_struct.array_plr == NULL)
			break;
	}




	printf("\n\nDuracao do Campeonato: %d\n",champDur);
	printf("Tempo de Espera: %d\n",waitTime);
	printf("GAMEDIR: %s\n", gameDir);
	printf("MAXPLAYERS: %d\n",max_players);
	
	unlink(REF_FIFO);

	pthread_mutex_destroy(&trinco);
	exit(1);
}


