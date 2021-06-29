CC=gcc
CFLAGS=-std=c99 -Wpedantic -Wall -Wextra -g
LDFLAGS=-lm -lpthread -lrt

all:
	@$(CC) algoritmo.c utils.c main.c $(CFLAGS) $(LDFLAGS) -o output

clean:
	@rm -f *.o main
