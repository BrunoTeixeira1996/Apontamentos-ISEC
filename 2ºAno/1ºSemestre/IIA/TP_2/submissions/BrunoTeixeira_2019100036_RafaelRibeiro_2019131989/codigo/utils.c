
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmo.h"
#include "utils.h"


int **leDados(char * nome_fich, int *m, int *g){

    FILE *f;
    int  **mat = NULL;
    char c;


    f = fopen(nome_fich, "r");
    if(!f){
        printf("Erro ao abrir o ficheiro\n");
        exit(1);
   }

    //ler o M e o G
    fscanf(f, "%d %d", m,g);


    while((c = fgetc(f))!= EOF)
        if(c == '\n')
            break;

    //cria matriz com m linhas e m colunas
    mat = (int**)malloc(*m * sizeof(int*));

    for(int i = 0; i < *m; i++){
        mat[i] = (int*)malloc(*m *sizeof(int));
    }


    if(!mat){
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }


    int li,col,val;

    //prenche matriz
    while(fscanf(f,"%d %d %d", &li,&col,&val) != EOF){
        mat[li][col] = val;
        mat[col][li] = val;
    }
    for(int i = 0; i < *m; i++){
        mat[i][i] = 0;
}

    fclose(f);

    return mat;
}

void mostraMatriz(int **mat, int m){

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


int verificaAux(int *aux, int g,int n){

    for(int i= 0; i < g; i++){
        if(aux[i] != n)
            return 0;
    }

    return 1;
}



void geraSolInicial(int *solucao, int m, int g){

    int n = m / g;

    //valor inteiro max, sendo o 0 o valor inteiro minimo
    int sub_conj = g - 1;

    //array auxiliar
    int aux[g];

    //numero aleatorio
    int n_aleatorio;

    // limpo o array auxiliar
    for(int i = 0; i < g; i++)
        aux[i] = 0;

    //limpo o array da solucao inicial
    for(int i = 0; i < m ; i++)
        solucao[i] = 0;

    int i = 0;

    while(!verificaAux(aux,g,n)){

        // gero um numero aleatorio [0 e sub_conj]
        n_aleatorio = random_l_h(0,sub_conj);

        if(aux[n_aleatorio] < n){
            aux[n_aleatorio] += 1;

            // inserir no array solucao o nr aleatorio
            solucao[i] = n_aleatorio;
            i++;
        }
    }

}


void mostraSol(int *solucao, int m){
    printf("[");
    for(int i = 0; i < m; i++){
        printf("%d", solucao[i]);
    }
    printf("]\n");

}


int calculaFit(int *solucao, int m, int g, int **matriz, int n){
    int aux[n];
    int conta = g-1, soma = 0;


    // enquanto conta >= 0
    while(conta >= 0){
        for(int i = 0, j = 0; i < m; i++){
            if(solucao[i] == conta){
                aux[j] = i;
                j++;
            }
        }


        for(int i = 0; i < n ; i++){
            for(int j = i+1; j < n; j++){
                soma += matriz[aux[i]][aux[j]];
            }

        }

        for(int i = 0; i < n; i++)
            aux[i] = 0;

        conta--;
    }

    return soma;
}

void substituiSol(int *a, int *b, int m){
    for(int i = 0; i < m; i++)
        a[i] = b[i];
}


struct info leEA(char *nome_fich ){
    struct info temp;

    FILE *f;

    f = fopen(nome_fich, "r");
    if(!f){
        printf("Erro ao abrir o ficheiro\n");
        exit(1);
    }

    //ler o M e o G
    fscanf(f, "%d %d", &temp.capacidade, &temp.numSub);

    fclose(f);
    temp.pm = 0.0;
    temp.pr = 0.3;
    temp.tsize = 2;

    temp.popsize = 100;
    temp.numGeracoes = 2500;

    // printf("\nTamanho da populacao: ");scanf("%d",&temp.popsize);
    // printf("Tamanho do torneio: ");scanf("%d", &temp.tsize);
    //printf("Numero de geracoes: ");scanf("%d", &temp.numGeracoes);
    printf("\n");
    return temp;
}


pchrom initPop(struct info *d){
    pchrom indiv;
    int n = d->capacidade / d->numSub;
    int sub_conj = d->numSub - 1;
    int aux[d->numSub];
    int n_aleatorio;

    for(int i = 0; i < d->numSub; i++)
        aux[i] = 0;

    indiv = malloc(sizeof(chrom)*(d->popsize));
    if(indiv == NULL){
        printf("Erro na alocacao de memoria\n");
        exit(1);
    }
    int j,x;
    for(x = 0; x < d->popsize; x++){
            for(j = 0; j < d->capacidade; j++){
                while(!verificaAux(aux,d->numSub,n)){

                    n_aleatorio = random_l_h(0,sub_conj);
                    if(aux[n_aleatorio] < n){
                        aux[n_aleatorio] += 1;
                        indiv[x].p[j] = n_aleatorio;
                        break;
                    }
                }
        }

        //limpamos o array contador
        for(int i = 0; i < d->numSub; i++)
            aux[i] = 0;
    }

    return indiv;
}


void mostraPop(chrom x, struct info *d){

    printf("\n[");
    for(int j = 0; j < d->capacidade; j++){
        printf("%d", x.p[j]);
     }
    printf("]\n");
    printf("Fitness:%d\n",x.fitness);
}


void mostraTudo(pchrom x, struct info *d){
    for(int i = 0; i < d->popsize; i++){
        for(int j = 0; j < d->capacidade; j++){
            printf("%d", x[i].p[j]);
       }
        printf(" Fitness : %d", x[i].fitness);
        printf("\n");
    }
    printf("\n");
}


int verificaValida(int *solucao, struct info *d){

    int n = d->capacidade / d->numSub;
    int contador = 0, aux;

    for(int i = 0; i < d->capacidade; i++){
        aux = solucao[i];
        for(int j = 0; j < d->capacidade; j++){
            if(solucao[j] == aux)
                contador++;
        }
        if(contador == n)
            contador = 0;
        else
            return 0; // a solucao e invalida
    }

    return 1;

}


int contaNumsArray(int *solucao,int num,struct info *d){
    int contador = 0;

    for(int i = 0;i < d->capacidade; i++)
        if(solucao[i] == num)
            contador++;

  return contador;
}

int verificaValidaPen(int *solucao, struct info *d){
    int n = d->capacidade / d->numSub;
    int contador = 0, aux = 0, penalidade = 0;

    for(int i = 0; i < d->capacidade; i++){
        aux = solucao[i];
        for(int j = 0; j < d->capacidade; j++){
            if(solucao[j] == aux)
                contador++;
        }
        if(contador == n)
            contador = 0;
        else{
            penalidade += contador;
            contador = 0;
            }
    }

    return penalidade;

}


void reparacao(int *solucao, struct info *d){
    int n = d->capacidade / d->numSub;
    int aux[d->capacidade];
    int nErrados = 0, nCertos = 0;
    int contador = 0, i = 0, recebe = 0;
    int k = 0, flag = 0, temp = 0;


    int auxiliarDist[d->numSub];
    int auxiliarCerto[d->capacidade];
    int auxiliarErrado[d->capacidade];

    for(int p = 0; p < d->numSub ; p++){
        auxiliarDist[p] = -1;
    }

    for(int k = 0; k < d->capacidade; k++){
        auxiliarErrado[k] = -1;
        auxiliarCerto[k] = -1;
    }



    do{
        recebe = contaNumsArray(solucao,solucao[i],d);
        if(recebe == n){
            flag = 0;
            for(int h = 0; h < d->numSub; h++){
                if(auxiliarDist[h] == solucao[i]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                auxiliarDist[k] = solucao[i];
                k++;
                for(int j = 0; j < n; j++){
                    auxiliarCerto[nCertos] = solucao[i];
                    nCertos++;
                }
            }
        }
        else{
            flag = 0;
            for(int h = 0; h < d->numSub; h++){
                if(auxiliarDist[h] == solucao[i]){
                    flag = 1;
                     break;
                }
            }
            if(flag == 0){
                auxiliarDist[k] = solucao[i];
                k++;
                for(int j = 0; j < n; j++){
                    auxiliarErrado[nErrados] = solucao[i];
                    nErrados++;
                }
            }
        }

        i++;
        if(flag == 0)
            contador++;
    }while(contador < d->numSub);



    int aleatorio = 0, al_certo = 0, al_errado = 0, x = 0, res = 0;
    int flag_certo = 0, flag_errado = 0;


    do{
        aleatorio = random_l_h(0,1);

        if(aleatorio == 0 && flag_certo == 0){ // vai ao array dos certos
            res = contaMenosUns(auxiliarCerto,d->capacidade);
            if(res == 1){
            
            do{
                al_certo = random_l_h(0,d->capacidade-1);
            }while(auxiliarCerto[al_certo] == -1);

            aux[x] = auxiliarCerto[al_certo];
            x++;
            auxiliarCerto[al_certo] = -1;
            temp++;
           }
           else{
                flag_certo = 1;
               }

        }else{
            res = contaMenosUns(auxiliarErrado,d->capacidade);
            if(res == 1 && flag_errado == 0){
                do{
                    al_errado = random_l_h(0,d->capacidade-1);
                }while(auxiliarErrado[al_errado] == -1);

                aux[x] = auxiliarErrado[al_errado];
                x++;
                auxiliarErrado[al_errado] = -1;
                temp++;
                }
            else{
                flag_errado = 1;
            }
        }

    }while(temp < d->capacidade || (flag_errado + flag_certo) != 2);
    

    substituiSol(solucao,aux,d->capacidade);
}


int avaliaIndividual_1(int *solucao, struct info *d, int **mat, int *valido){
    int n = d->capacidade / d->numSub;
    int aux[n];
    int conta = d->numSub-1;
    int soma = 0;

    // verifica sem penalizacao
    if(!verificaValida(solucao,d)){
            *valido = 0;
            return -1;
        }
        else{
            *valido = 1;
    }

    for(int i = 0; i < n; i++)
        aux[i] = 0;

    // enquanto conta >= 0
    while(conta >= 0){
        for(int i = 0, j = 0; i < d->capacidade; i++){
            if(solucao[i] == conta){
                aux[j] = i;
                j++;
            }
        }

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                soma +=  mat[aux[i]][aux[j]];
            }
        }

        for(int i = 0; i < n; i++)
            aux[i] = 0;

        conta--;
    }

    return soma;
}

int avaliaIndividual_2(int *solucao, struct info *d, int **mat, int *valido){
    int n = d->capacidade / d->numSub;
    int aux[n];
    int conta = d->numSub-1;
    int soma = 0, pen = 0;


    pen = verificaValidaPen(solucao,d);
    if(pen > 0){
        reparacao(solucao,d);
     }
    *valido = 1;

    for(int i = 0; i < n; i++)
        aux[i] = 0;

    // enquanto conta >= 0
    while(conta >= 0){
        for(int i = 0, j = 0; i < d->capacidade; i++){
            if(solucao[i] == conta){
                aux[j] = i;
                j++;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                soma +=  mat[aux[i]][aux[j]];
            }
        }

        for(int i = 0; i < n; i++)
            aux[i] = 0;

        conta--;
    }

    return soma - pen;
}



chrom getMelhor(pchrom pop, struct info *d, chrom best){
    for(int i = 0; i < d->popsize; i++){
        if(best.fitness < pop[i].fitness) // maximizacao
            best = pop[i];
    }

    return best;
}

// penalizacao cega e avaliacao
void verificaGeral_1(pchrom pop, struct info *d, int **mat){

    for(int i = 0; i < d->popsize; i++){
        pop[i].fitness = avaliaIndividual_1(pop[i].p,d,mat,&pop[i].valido);

    }
}



// penalizacao nao cega, reparacao e avaliacao
void verificaGeral_2(pchrom pop, struct info *d, int **mat){

    for(int i = 0; i < d->popsize; i++){
        pop[i].fitness = avaliaIndividual_2(pop[i].p,d,mat,&pop[i].valido);
    }
}


int  contaInvals(struct info *d,pchrom pop){
    int invalida = 0;

    for(int i = 0; i < d->popsize; i++)
        if(pop[i].valido == 0){
            invalida++;
        }
    return invalida;
}

int contaMenosUns(int *aux, int tam){
    for(int i = 0; i < tam; i++){
        if(aux[i] != -1)
            return 1; // significa que o array contem numeros para alem de -1
   }
   return 0;
}


void init_rand(){
    srand((unsigned)time(NULL));
}

int random_l_h(int min,int max){
    return min + rand() % (max-min+1);
}

float rand_01(){
	return ((float)rand())/RAND_MAX;
}
