#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	int i;
	char palavra[10];
	char encontrou[10];


	char *matrix[5][2] = {
		{"ola", "hello"},
		{"adeus", "bye"},
		{"sim", "yes"},
		{"nao", "no"},
		{"lol", "lol"},
	};

	strcpy(palavra,argv[1]); //recebe uma string do argv[1]


	for(i = 0; i < 5; i++){
		if(strcmp(palavra,matrix[i][0]) == 0){ //se existir na matriz, mostra a sua tradução
			strcpy(encontrou,matrix[i][1]);
			printf("%s\n",encontrou);
			exit(1);
		}
	}
	printf("unkown\n"); // caso contrário mostra unknown

	exit(0);
}