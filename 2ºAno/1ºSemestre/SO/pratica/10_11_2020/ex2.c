#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>


void mostra (int s){
	printf("\nACORDA!!! (sinal %d)",s);
	fflush(stdout);
	exit(0);
}


int main(int argc, char const *argv[])
{
	int num_a,num_b,soma,res;

	srand(time(NULL));
    num_a = rand() % 101;
    num_b = rand() % 101;
    printf("%d + %d\n", num_a,num_b); 

    soma = num_a + num_b;

    printf("Resultado: ");
    fflush(stdout);
    scanf("%d",&res);


    if(res == soma){
    	printf("Acertou\n");
    }
    else{
    	printf("Errou\n");
    }
	
	
	exit(0);
}