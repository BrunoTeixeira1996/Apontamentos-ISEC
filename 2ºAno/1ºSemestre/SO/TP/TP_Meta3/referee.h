#ifndef REFEREE_H
#define REFEREE_H

#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include "user.h"
#include <time.h>


#define WAIT_TIME 5
#define CHAMP_DURATION 30
#define REF_FIFO "referee_fifo"
#define CLI_FIFO "client_fifo_%d"


typedef struct Games games, *games_ptr;

struct Games{
	char game_name[20];
	char desc[256];
	char path[256];
};

typedef struct Player player, *player_ptr;

struct Player{
	user client;
	games play;
	int on_game;
	pthread_mutex_t *player_trinco;
};

typedef struct Mainframe mainframe, *mainframe_ptr;

struct Mainframe{
	player_ptr array_plr;
	int wait;
	int champDur;
	int max_players;
	int* n_players;
	games_ptr array_games;
	int n_games;
	int flag;
	int game_start;
	pthread_mutex_t *ptrinco;
	char* direct;
};


#endif
