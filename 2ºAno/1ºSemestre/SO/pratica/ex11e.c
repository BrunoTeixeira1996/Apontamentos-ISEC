#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[], char *envp[])
{

	int i;
	char *str;

	for(i = 0; envp[i] != NULL; i++){
		printf("%s\n", envp[i]);
	}
	
	return 0;
}
