#ifndef USER_H
#define USER_H

#define REF_FIFO "referee_fifo"
#define CLI_FIFO "client_fifo_%d"

typedef struct User user, *user_ptr;

struct User{
	char name[26];
	char command[30];
	char response[256];
	int pont; 
	int user_id;
	int registered;
};

#endif