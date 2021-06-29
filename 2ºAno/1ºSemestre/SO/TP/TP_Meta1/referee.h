#ifndef REFEREE_H
#define REFEREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"

#define WAIT_TIME 15
#define CHAMP_DURATION 30

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
};

#endif
