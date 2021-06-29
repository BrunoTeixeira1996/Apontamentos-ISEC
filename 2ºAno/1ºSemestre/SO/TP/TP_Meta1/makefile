all: client referee game

client: client.c
	gcc -o client client.c

referee: referee.c referee.h player.h
	gcc -o referee referee.c

game: g_BigSmall.c
	gcc -o g_BigSmall g_BigSmall.c

clean: 
	rm client referee g_BigSmall
