#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player player, *player_ptr;

struct Player{
	char name[26];
	int pont;
	int player_id;
	int game_id;
};

#endif