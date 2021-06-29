#include "utils.h"

typedef struct {
    char letra;
    int continua;
}TDATA;

void *mostra(void *dados){
    /* tarefa #1*/
    int *res;

    TDATA *pdata;
    pdata = (TDATA *)dados; // vamos usar o pdata como argumento desta funcao

    do{
        // mostro o nr de pontos aleatoriamente de 1...5
        for(int i = 0; i < rand()%5; i++){
            printf(".");
            fflush(stdout);
            sleep(1);
        }

        // mostro a letra
        for(int i = 0; i < 3; i++){
            printf("%c", pdata->letra);
            fflush(stdout);
            sleep(1);
        }
    }while(pdata->continua);

    res = (int *) malloc(sizeof(int)); // alocamos dinamicamente para sabermos com que status acabou a thread #1
    *res = 123;
    pthread_exit(res); // termina a thread #1

}


int main(void){
    char str[40];
    int *resultado;
    TDATA tinfo[NTHREADS];
    pthread_t tarefa[NTHREADS];

    srand((unsigned int)time(NULL));


    printf("Sou o processo %d...\n",getpid());
    // guardar o identificador da thread (&tarefa), funcao associada à thread (mostra) , o que queremos passar à funcao(void*)NULL (nao queremos passar nada)


    // aqui estamos a criar 3 threads
    for(int i = 0; i < NTHREADS; i++){
        tinfo[i].letra = 'A' + i; // A , B, C
        tinfo[i].continua = 1;
        pthread_create(&tarefa[i],NULL,mostra,(void *)&tinfo[i]);

    }


    do{
        /*tarefa #0*/

        printf("COMANDO:\n");
        scanf("%s", str);
        printf("Recebi o comando '%s'...\n",str);

    }while(strcmp(str,"sair")!= 0);

    for(int i = 0; i < NTHREADS; i++){
        printf("Vou pedir a thread #%d para terminar ... ",i+1); fflush(stdout);
        tinfo[i].continua = 0;
        pthread_join(tarefa[i],(void *)&resultado); // esperar pelo fim da thread que criei
        printf("Terminou [%d]!!!\n", *resultado);

        free(resultado);

    }





    exit(0);
}
