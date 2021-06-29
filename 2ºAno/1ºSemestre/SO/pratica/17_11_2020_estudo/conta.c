#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
  int i,fd;

	/*O_CREAT -> cria o ficheiro caso nao exista
	  O_TRUNC -> limpa o ficheiro caso exista algum conteudo
	  O_WRONLY -> para escrever no ficheiro
	  0644 -> rw-r--r--

	*/

  printf("O meu PID e %d.\n",getpid());
  close(1);

  
  fd = open("dados.bin", O_CREAT | O_TRUNC | O_WRONLY, 0655);
  if(fd>= 0){

  
  printf("Inicio...\n");
  for(i = 0; i < 10; i++){
     printf("+");
     fflush(stdout);
     sleep(2);
    }
    printf("\nFim!!\n");

    write(fd,"Bruno Teixeira",14);
    write(fd, &i,sizeof(int));
    close(fd);
}
    exit(3);
}
