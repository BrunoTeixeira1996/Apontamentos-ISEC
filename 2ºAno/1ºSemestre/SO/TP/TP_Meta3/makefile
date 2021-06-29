all: client referee game

client: client.c user.h
	gcc -o client client.c

referee: referee.c referee.h user.h
	gcc -lpthread -o referee referee.c

game: g_BigSmall.c
	gcc -o g_BigSmall g_BigSmall.c

clean: 
	rm client referee g_BigSmall
