#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    char anser[15] =" ";
    int score = 0;
    char quit;

    srand(time(0));
    int rand_number = rand()%101;


    FILE *f;
    char instruction[256];

    f = fopen("bigSmall_inst.txt","r");

    if(f == NULL){
        printf("[Error] while opening bigSmall_inst.txt\n");
        fclose(f);
        exit(0);
    }


    while(fgets(instruction,sizeof(instruction),f)){
        fprintf(stdout, "%s\n", instruction);
    }
    fclose(f);
    


    while(strcmp(anser, "#quit") != 0){
        
        int new_number =rand()%101;

        printf("%d ------- +/-\n", rand_number);
        scanf(" %s", &anser);
        switch(anser[0]){
            case '+':   
                if(rand_number < new_number){
                    printf("Nice\n");
                    score++;
                }
                else
                    printf("Try Again\n"); 
                    rand_number = new_number;
                break;
                
            case '-':   
                if(rand_number > new_number){
                    printf("Nice\n");
                    score++;
                }
                else
                    printf("Try Again\n"); 
                    rand_number = new_number;
                break;

            default:
                if(strcmp(anser,"#quit") != 0)
                    printf("Use + and - to play, #quit to quit\n");
        }

    }

    exit(score);
}
