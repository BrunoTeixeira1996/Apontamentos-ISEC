#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>




int score = 0;
void signalFunc(int s){
	exit(score);
}

int main()
{
    int new_number;
    char anser[15] ="empty";
    char quit;
    struct sigaction act;
    act.sa_handler = signalFunc;
    act.sa_flags = 0;

    setbuf(stdout, NULL);

    srand(time(0));
    int rand_number = rand()%101;


    FILE *f;
    char instruction[256];

    f = fopen("bigSmall_inst.txt","r");

    if(f == NULL){
        printf("[Erro] Nao consegui abrir o ficheiro\n");
        fclose(f);
        exit(0);
    }


    while(fgets(instruction,sizeof(instruction),f)); 	
   

    fclose(f);

    
    // mostra a instrucao do jogo
    printf("%s", instruction);

    //prepara a possivel rececao de um sinal
    sigaction(SIGUSR1, &act, NULL);

    //execucao do jogo
    while(strcmp(anser, "#quit") != 0){

        new_number = rand()%101;

        printf("\n%d (+/-)", rand_number);
        scanf(" %s", anser);
        switch(anser[0]){
            case '+':   
                if(rand_number < new_number){
                    printf("\nParabens!!!\n");
                    score++;
                }      
                break;
                

            case '-':   
                if(rand_number > new_number){
                    printf("\nParabens!!!\n");
                    score++;
                }
                break;
                

            default:
                printf("Use + e - para jogar, #quit para sair\n");
            	break;
        }
        rand_number = new_number;

        char c ;
        while((c= getchar()) != '\n' && c != EOF);

    }
}
