#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int i;
	char str[40];

	char *cadeiap[1][5] = {
		"gato", "comida", "peixe", "cao", "animal"
	};

	char *cadeiaf[1][5] = {
		"chat", "nourriture", "poisson", "chien", "animal"
	};

	printf("[INICIO]\n");

	strcpy(str,argv[1]);

	for(i = 0; i < 5; i++){
		if(strcmp(str,cadeiap[0][i]) == 0){
			printf("%s\n", cadeiaf[0][i]);
			printf("[FIM]\n");
			exit(1);
		}
		
	}


	printf("Unkown\n");

	printf("[FIM]\n");

	exit(0);
}