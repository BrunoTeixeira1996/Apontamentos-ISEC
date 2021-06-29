#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc, char const *argv[])
{
	int i,n,t = 1;
	char *str;

	printf("INICIO...\n");

	if(argc != 3){									//verifico se existem 3 argumentos
		printf("[ERRO] Nr de args inválido !\n");
		exit(3);
	}

	n = atoi(argv[1]);								//atribuo o nr de iterações ao n
	str = getenv("TEMPO");							//atribuo o valor da var de ambiente TEMPO ao str

	if(str != NULL){								//se a var TEMPO existir
		t = atoi(str);								//coloco o valor dela no t
	}												//caso não existe, por defeito t=1
	

	for(i = 0; i < n ; i++){						//faço um ciclo do 0 ao n
		printf("%s", argv[2]);						//mostro o argv[2] que é o carater
		fflush(stdout);								//fflush porque nao temos \n no printf em cima
		sleep(t);									//faço sleep consoante o t
	}


	printf("\nFIM...");



	exit(0);
}
/* o exit() diz que eu quero parar com a aplicação
estou a terminar aplicação onde quer que esteja*/

/*o sleep() permite fazer uma pausa na aplicação
durante N segundos*/

/* o fflush() permite forçar a saida do que está
pendente do que tem de sair para o ecrã */