#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int i;

		printf("O meu PID e %d.\n",getpid());
		printf("Inicio...\n");
		for(i = 0; i < 5; i++){
			printf("+");
			fflush(stdout);
			sleep(3);
		}

		printf("\nFim!!!\n");	

	exit(3);
}