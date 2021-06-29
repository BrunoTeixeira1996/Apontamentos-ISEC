#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>

int erradas = 0;
int n_introduziu = 0;

/*funcao do alarme*/
void timeout(int s){
	printf("Timeout , demorou demasiado tempo!!!\n");
	erradas++;
	n_introduziu++;
	fflush(stdout);
	resultado();

}

/*funcao que cria 2 numeros random e retorna a soma de ambos*/
int resultado(){
	int num_a, num_b,soma;

	srand(time(NULL));
    num_a = rand() % 101; //gero 1 numero aleatorio de 0 a 100
    num_b = rand() % 101; // gero 1 numero aleatorio de 0 a 100
    printf("%d + %d\n", num_a,num_b);

    soma = num_a+num_b;

    return soma;
}

int main(int argc, char const *argv[])
{

	int soma,res,certas, valor_alarme,flag = 0;

	signal(SIGALRM, timeout); 
	valor_alarme = 5;

	do{
		
		soma = resultado();

		alarm(valor_alarme); // inicio o alarm
		printf("Tem %d segundos para indicar o valor das somas: ",valor_alarme);
		fflush(stdout);

		scanf("%d",&res);
		alarm(0); // se a pessoa responder, desligo o alarme

		if(res == soma){ // se acertar na soma
			printf("Acertou\n");
			fflush(stdout);
			certas++; // conto esse ponto

		}
		else{
			if(erradas == 2 || n_introduziu == 2){
				printf("Errou 2\n");
				break;
			}

			printf("Falhou\n");
			fflush(stdout);
		}

		alarm(--valor_alarme); // reduz o tempo de resposta

	}while(valor_alarme > 0);
	

	printf("Pontuação final -> Certas : %d , Erradas : %d\n", certas,erradas);

	exit(0);
}