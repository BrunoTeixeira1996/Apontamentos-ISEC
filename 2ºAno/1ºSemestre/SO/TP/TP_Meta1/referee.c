#include "referee.h"


int main(int argc, char const *argv[])
{
	int i;
	char *gameDir, *maxPlayers;// variaveis de ambiente
	int max_players;
	int waitTime = WAIT_TIME, champDur = CHAMP_DURATION; // args


	gameDir = getenv("GAMEDIR");
	if(gameDir == NULL){
		gameDir = "";
	}


	maxPlayers = getenv("MAXPLAYERS");//var so para testar null
	if(maxPlayers == NULL){
		printf("[ERROR] environment MAXPLAYERS\n");
		exit(0);
	}
	max_players = atoi(maxPlayers); //existe var ambiente para int
	if(max_players > 30 || max_players <= 0){
		printf("[ERROR] environment MAXPLAYERS (>0 <30)\n");
		exit(0);
	}
	
	if(argc == 3){
		if(atoi(argv[1]) > 0)
			champDur = atoi(argv[1]);

		if(atoi(argv[2]) > 0)
			waitTime = atoi(argv[2]);
	}else if(argc != 1){
		printf("[ERROR] Invalid number of arguments\n");
		exit(0);
	}

	printf("Championship duration: %d\n",champDur);
	printf("Waiting time: %d\n",waitTime);
	printf("GAMEDIR: %s\n", gameDir);
	printf("MAXPLAYERS: %d\n",max_players);

	
	exit(1);
}
