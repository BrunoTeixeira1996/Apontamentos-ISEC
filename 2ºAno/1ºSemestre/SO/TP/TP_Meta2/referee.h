#ifndef REFEREE_H
#define REFEREE_H

#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h> 
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include "user.h"


#define WAIT_TIME 15
#define CHAMP_DURATION 30
#define REF_FIFO "referee_fifo"
#define CLI_FIFO "client_fifo_%d"


typedef struct Referee referee, *referee_ptr;

struct Referee{
	int n_games;
	int n_players;
	int wait_time;
	int play_time;
};


typedef struct Games games, *games_ptr;

struct Games{
	int id;
	char game_name[20];
	char desc[256];
	char question[20];
};

typedef struct Player player, *player_ptr;

struct Player{
	user client;
	games play;
	int on_game;

};


#endif
