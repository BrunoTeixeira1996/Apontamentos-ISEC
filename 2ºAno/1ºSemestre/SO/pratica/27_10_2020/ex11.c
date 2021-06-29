#include <stdio.h>
#include <stdlib.h>

#define NOME_DEFAULT "António"

int main(int argc, char *argv[], char *envp[]){

	int i;
	char *str;

	str = getenv("NOME");
	if (str == NULL){
		printf("O meu nome é %s\n",NOME_DEFAULT);
		return 0;
	}
	printf("O meu nome é %s\n", str);


	return 0;
}

/*no .bashrc está criada uma variavel de ambiente

export NOME
NOME="Bruno Teixeira"
*/