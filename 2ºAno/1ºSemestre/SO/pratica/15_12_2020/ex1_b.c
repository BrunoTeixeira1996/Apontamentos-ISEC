#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define NTHREADS 3



typedef struct {
    char letra;
    int continua;
    pthread_mutex_t *ptrinco;
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

        //TRANCAR();
        pthread_mutex_lock(pdata->ptrinco);

        // mostro a letra
        for(int i = 0; i < 3; i++){ // queremos garantir que isto nao é interrompido
            printf("%c", pdata->letra);
            fflush(stdout);
            sleep(1);
        }

        //DESTRANCAR();
        pthread_mutex_unlock(pdata->ptrinco);

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
    pthread_mutex_t trinco;

    srand((unsigned int)time(NULL));

    //CRIAR_TRINCO();
    pthread_mutex_init(&trinco,NULL);

    printf("Sou o processo %d...\n",getpid());
    // guardar o identificador da thread (&tarefa), funcao associada à thread (mostra) , o que queremos passar à funcao(void*)NULL (nao queremos passar nada)


    // aqui estamos a criar 3 threads
    for(int i = 0; i < NTHREADS; i++){
        tinfo[i].letra = 'A' + i; // A , B, C
        tinfo[i].continua = 1;
        tinfo[i].ptrinco = &trinco;
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

    //ELIMINAR_TRINCO();
    pthread_mutex_destroy(&trinco);




    exit(0);
}
