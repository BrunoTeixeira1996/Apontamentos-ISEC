#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
 int i;

 printf("[DEBUG] Inicio ...\n");
 for(i = 0; i<argc; i++){
   printf("ARG[%d] = '%s'\n",i, argv[i]);
 }
 printf("[DEBUG] Fim !\n");

 return (0);

}

