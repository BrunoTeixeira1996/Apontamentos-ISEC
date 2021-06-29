#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[], char *envp[]){
 int i;
 char *str;

 printf("[DEBUG] Inicio ...\n");
 for(i = 0; i<argc; i++){
   printf("ARG[%d] = '%s'\n",i, argv[i]);
 }

for(i=0;envp[i]!=NULL;i++){
 printf("VAR[%d] = '%s' \n",i, envp[i]);
}

 str = getenv("NJOGADORES");
 i = atoi(str);
 printf("vou permitir %d jogadores!\n",i);

printf("[DEBUG] Fim ...\n");

 return (0);

}

