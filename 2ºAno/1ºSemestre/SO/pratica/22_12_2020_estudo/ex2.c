#include "util.h"

typedef struct {
    char fifo[20];
    int continua;
    pthread_mutex_t *ptrinco;
}TDATA;

void acorda(int s){}

void *mostra(void *dados){
    int *res,fd, n;
    struct sigaction act;
    PEDIDO p;

    TDATA *pdata;
    pdata = (TDATA *)dados; // vamos usar o pdata como argumento desta funcao
    res = (int *) malloc(sizeof(int)); // nr de pedidos chegados do cliente
    *res = 0;

    /*TRATAR O SINAL SIGUSR1 - sigaction*/
    act.sa_handler = acorda;
    act.sa_flags = 0;

    sigaction(SIGUSR1,&act,NULL);

    /*CRIAR FIFO - mkfifo();*/
    mkfifo(pdata->fifo,0600);

    /*ABRIR FIFO (O_RDWR) - open()*/
    fd = open(pdata->fifo,O_RDWR);

    do{
        /*RECEBER INFORMACAO DO CLIENTE - read();*/
        n = read(fd,&p, sizeof(p));
        if(n == sizeof(PEDIDO)){
            /*FAZEMOS LOCK NO MUTEX*/
            pthread_mutex_lock(pdata->ptrinco);

            /*ENVIAR INFORMACAO PARA O MONITOR - printf();*/
            printf("%s - %s %d\n",pdata->fifo,p.nome,p.num);

            /*FAZEMOS UNLOCK COM O MUTEX*/
            pthread_mutex_unlock(pdata->ptrinco);

            (*res)++;
        }
    }while(pdata->continua);

    /*AVISAR O CLIENTE PARA SAIR - kill()*/
    kill(p.pid,SIGUSR1);

    /*FECHAR FIFO - close()*/
    close(fd);

    /*ELIMINAR FIFO - unlink()*/
    unlink(pdata->fifo);

    pthread_exit(res);
}

int main(void){
    char str[40];
    int *resultado;
    TDATA tinfo[2];
    pthread_t tarefa[2];
    pthread_mutex_t trinco;

    /*INICIALIZA O MUTEX*/
    pthread_mutex_init(&trinco,NULL);

    printf("Sou o processo %d...\n",getpid());


    /*ENVIAR UMA STRING A THREAD - "ESQ" ou "DIR"*/
    strcpy(tinfo[0].fifo,"ESQ");
    tinfo[0].continua = 1;
    tinfo[0].ptrinco = &trinco;
    pthread_create(&tarefa[0],NULL,mostra,(void *)&tinfo[0]);

    /*ENVIAR UMA STRING A THREAD - "ESQ" ou "DIR"*/
    strcpy(tinfo[1].fifo,"DIR");
    tinfo[1].continua = 1;
    tinfo[1].ptrinco = &trinco;
    pthread_create(&tarefa[1],NULL,mostra,(void *)&tinfo[1]);


    do{
        /*tarefa #0*/
        printf("COMANDO:\n");
        scanf("%s", str);
        printf("Recebi o comando '%s'...\n",str);

    }while(strcmp(str,"sair")!= 0);


    /*AQUI ESTOU A TERMINAR AS DUAS THREADS*/
    for(int i = 0; i < 2; i++){
        tinfo[i].continua = 0;

        /*ENVIAR SINAL SIGUSR1 A THREAD PARA DESBLOQUEAR O READ - pthread_kill()*/
        pthread_kill(tarefa[i],SIGUSR1);

        pthread_join(tarefa[i],(void *)&resultado); // esperar pelo fim da thread que criei
        printf("Thread %d terminou [%d]!!!\n", i,*resultado);

        free(resultado);

    }

    /*APAGAR O MUTEX*/
    pthread_mutex_destroy(&trinco);

    exit(0);
}
