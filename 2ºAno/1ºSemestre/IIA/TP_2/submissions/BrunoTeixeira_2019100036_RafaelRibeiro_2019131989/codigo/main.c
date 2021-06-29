
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "algoritmo.h"
#include "utils.h"


int main(){
    char nome_fich[1000];
    int op;

    int **matriz,*sol_inic, *sol_best,custo,n, rondas = 15;
    int g, m, best_custo = 0, num_iter;
    float mbf = 0.0;

    struct info EA_param;
    pchrom pop = NULL, pais = NULL;
    chrom melhor_ronda_atual, melhor_ronda_final;
    int geracao_atual;
    int solucoes_invalidas;

    printf("Nome do ficheiro: ");
    fgets(nome_fich,1000,stdin);
    strtok(nome_fich,"\n");



    matriz = leDados(nome_fich, &m,&g);

    // N = M/G
    n = m/g;

    //mostraMatriz(matriz,m);

    //inicia numeros aleatorios
    init_rand();

    // Menu
    printf("1- Trepa Colinas\n");
    printf("2- Algoritmo Evolutivo\n");
    printf("3- Algoritmo Hibrido\n");

    printf("Escolha: ");scanf("%d",&op);

    if(op == 1){
        printf("Quantas iteracoes deseja fazer: ");scanf("%d", &num_iter);
        /*TREPA COLINAS*/

        //solucao inicial
        sol_inic = malloc(sizeof(int)* m);

        sol_best = malloc(sizeof(int)*m);

        if(sol_inic == NULL || sol_best == NULL){
            printf("Erro na alocacao de memoria\n");
            exit(1);
        }

        int i;

        for(i  = 0; i < rondas; i++){

            // gera e mostra solucao inicial
            printf("Solucao Inicial");
            geraSolInicial(sol_inic,m,g);
            mostraSol(sol_inic,m);

            custo = trepaColinas(sol_inic,matriz,m,g,n,num_iter);

            printf("\nRepeticao %d: \n",i);
            mostraSol(sol_inic,m);
            printf("Custo final: %d\n\n", custo);
            mbf += custo;

            if(i == 0 || best_custo < custo){
                best_custo = custo;
                substituiSol(sol_best,sol_inic,m);
            }
        }

        printf("\nMBF: %2f\n", mbf/i);
        printf("\nMelhor Solucao encontrada ");
        mostraSol(sol_best,m);
        printf("Custo final: %2d\n",best_custo);


        free(sol_best);
        free(sol_inic);

    }
    else if(op == 2){
        int x;

        //preencher a struct EA_param
        EA_param = leEA(nome_fich);

        for(x  = 0; x < rondas; x++ ){
            printf("\nRepeticao %d\n",x+1);
            printf("--------------------");

            //geracao da populacao inicial
            pop = initPop(&EA_param);

            // avalia populacao inicial
            verificaGeral_2(pop,&EA_param,matriz);


            /*DEBUG*/
            //mostraPop(a,&EA_param);
            // mostraTudo(pop,&EA_param);

            geracao_atual = 1;

            melhor_ronda_atual = pop[0];

            // encontra-se a melhor solucao dentro de toda a populacao
            melhor_ronda_atual = getMelhor(pop,&EA_param,melhor_ronda_atual);

            //mostraPop(melhor_ronda_atual,&EA_param);

            pais = malloc(sizeof(chrom)*EA_param.popsize);
            if(pais == NULL){
                printf("Erro na alocacao de memoria\n");
                exit(1);
            }

            while(geracao_atual <= EA_param.numGeracoes){
                //torneio binario
                torneioSelecao(pop,&EA_param,pais);

                //aplicar os operadores geneticos

                //crossover
                recombinacao(pais,&EA_param,pop);

                //mutacao
                mutacao(pop,&EA_param);


                //avalia a nova pop
                verificaGeral_2(pop,&EA_param,matriz);


                //atualizar a melhor solucao encontrada
                melhor_ronda_atual = getMelhor(pop,&EA_param,melhor_ronda_atual);

                //incrementamos a geracao atual
                geracao_atual++;
            }

            //Escreve resultados da repeticao que terminou
            solucoes_invalidas = contaInvals(&EA_param,pop);

            printf("\nNa repeticao %d a melhor solucao foi: ",x+1);
            mostraPop(melhor_ronda_atual,&EA_param);
            printf("Media de solucoes invalidas: %.2f\n",(float)solucoes_invalidas/EA_param.popsize);
            printf("--------------------\n");

            mbf += melhor_ronda_atual.fitness;

            if(x == 0 || melhor_ronda_atual.fitness > melhor_ronda_final.fitness)
                melhor_ronda_final = melhor_ronda_atual;

            free(pais);
            free(pop);
        }

        printf("\n\nMBF: %f\n", mbf/x);
        printf("\nMelhor solucao encontrada");
        mostraPop(melhor_ronda_final,&EA_param);
    }
    else if(op == 3){
        printf("Quantas iteracoes deseja fazer: ");scanf("%d", &num_iter);

        // METODO HIBRIDO
         int x;

        //preencher a struct EA_param
        EA_param = leEA(nome_fich);

        for(x  = 0; x < rondas; x++ ){
            printf("\nRepeticao %d\n",x+1);
            printf("--------------------");

            //geracao da populacao inicial
            pop = initPop(&EA_param);

            // avalia populacao inicial
            verificaGeral_1(pop,&EA_param,matriz);

            // HIBRIDO 1
            for(int i = 0; i < EA_param.popsize; i++){
                pop[i].fitness = trepaColinas(pop[i].p,matriz,m,g,n,num_iter);
            }



            geracao_atual = 1;

            melhor_ronda_atual = pop[0];

            // encontra-se a melhor solucao dentro de toda a populacao
            melhor_ronda_atual = getMelhor(pop,&EA_param,melhor_ronda_atual);

            //mostraPop(melhor_ronda_atual,&EA_param);

            pais = malloc(sizeof(chrom)*EA_param.popsize);
            if(pais == NULL){
                printf("Erro na alocacao de memoria\n");
                exit(1);
            }

            while(geracao_atual <= EA_param.numGeracoes){
                //torneio binario
                torneioSelecao(pop,&EA_param,pais);

                //aplicar os operadores geneticos

                //crossover
                recombinacao(pais,&EA_param,pop);

                //mutacao
                mutacao(pop,&EA_param);


                //avalia a nova pop
                verificaGeral_1(pop,&EA_param,matriz);


                //atualizar a melhor solucao encontrada
                melhor_ronda_atual = getMelhor(pop,&EA_param,melhor_ronda_atual);

                //incrementamos a geracao atual
                geracao_atual++;
            }


            /*
            // HIBRIDO 2
            for(int i = 0; i < EA_param.popsize; i++){
                pop[i].fitness = trepaColinas(pop[i].p,matriz,m,g,n,num_iter);
            }
            // chamamos a getMelhor porque o Hibrido2 pode melhorar
             melhor_ronda_atual = getMelhor(pop,&EA_param,melhor_ronda_atual);
            */


            //Escreve resultados da repeticao que terminou
            solucoes_invalidas = contaInvals(&EA_param,pop);

            printf("\nNa repeticao %d a melhor solucao foi: ",x+1);
            mostraPop(melhor_ronda_atual,&EA_param);
            printf("Media de solucoes invalidas: %.2f\n",(float)solucoes_invalidas/EA_param.popsize);
            printf("--------------------\n");

            mbf += melhor_ronda_atual.fitness;

            if(x == 0 || melhor_ronda_atual.fitness > melhor_ronda_final.fitness)
                melhor_ronda_final = melhor_ronda_atual;

            free(pais);
            free(pop);
        }

        printf("\n\nMBF: %f\n", mbf/x);
        printf("\nMelhor solucao encontrada");
        mostraPop(melhor_ronda_final,&EA_param);

    }


    else {
        printf("Essa opcao nao existe\n");
        exit(1);
    }

    for(int i = 0; i < m; i++){
            free(matriz[i]);
    }

    free(matriz);

    return 0;
}
