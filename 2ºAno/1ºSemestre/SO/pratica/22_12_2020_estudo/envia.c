#include "util.h"

int continua = 1;

/*funcao de tratamento de sinal*/
void termina(int s){
    continua = 0;
}


int main(int argc, char const *argv[]){
    PEDIDO p;
    int fd_serv;
    setbuf(stdout,NULL);

    struct sigaction act;
    act.sa_handler = termina;
    act.sa_flags = 0;

    /*VERIFICA SE TEM ARGUMENTOS DA LINHA DE COMANDOS*/
    if(argc != 2)
        exit(1);


    /*ABRE FIFO DO ARGV[1] PARA ESCRITA*/
    fd_serv = open(argv[1],O_WRONLY);

    if(fd_serv == -1)
        exit(1);

    /*PEDE NOME*/
    printf("Nome: ");scanf("%s", p.nome);
    /*GUARDA PID*/
    p.pid = getpid();
    /*TRATA DO SINAL*/
    sigaction(SIGUSR1,&act,NULL);

    do{
        /*PEDE NUMERO*/
        printf("Numero: ");scanf("%d", &p.num);

        /*ESCREVE NO FIFO*/
        write(fd_serv,&p, sizeof(PEDIDO));

    }while(continua);
    /*FECHA O FIFO*/
    close(fd_serv);
    exit(0);
}
