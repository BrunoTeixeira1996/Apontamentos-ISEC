#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int i,fd;

	fd = open("dados.bin", O_CREAT | O_TRUNC | O_WRONLY, 0644);

	if(fd >= 0){
		printf("O meu PID e %d.\n",getpid());
		printf("Inicio...\n");
		for(i = 0; i < 10; i++){
			printf("+");
			fflush(stdout);
			sleep(2);
		}

		printf("\nFim!!!\n");


		write(fd, "Joao Pedro", 10);
		write(fd, &i, sizeof(int));
		write(fd, "Maria\n", 6);
		close(fd);
	}
	

	exit(3);
}