/*
 * File:   pessoas.c
 * Author: Bruno Teixeira 2019100036
 *
 * Created on 04 April 2020, 11:50
 */

#include "pessoas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void mostraInfoPessoa(p_pessoa aux) {
    p_pessoa p = aux;

    while (p != NULL) {
        printf("Id: %d Nome: %s  Idade: %d Estado: %c ", p->local->id, p->nome, p->idade, p->estado);
        if (p->estado == 'D') {
            printf("%d", p->dias_doente);
        }
        printf("\n");
        p = p->prox;
    }
}

p_pessoa escreveNaLista(p_pessoa p) {

    FILE *fp;
    char file[32];

    // o p será o primeiro nó
    p_pessoa novo = NULL; // novo nó
    p_pessoa anterior = NULL; // nó anterior

    if (p) {
        free(p);
    }


    printf("Qual é o nome do ficheiro de texto, relativo às pessoas? ");
    scanf("%s", file);
    fp = fopen(file, "r");

    if (fp == NULL) {
        printf("Erro a abrir o ficheiro\n");
        return 0;
    }

    while (!feof(fp)) { // percorre o ficheiro txt até ao EOF

        novo = malloc(sizeof (pessoas)); //aloca espaço de memoria para o novo nó
        if (novo == NULL) {
            printf("Erro na alocacao de memoria\n");
            fclose(fp);
            return 0;
        }
        if (fscanf(fp, "%s %d %c", novo->nome, &novo->idade, &novo->estado) == 3) {
            if (novo->idade < 0) {
                printf("As idades não podem ser negativas\n");
                return 0;
            }
            if (novo->estado == 'D') { // se o estado for D, entao vale a pena receber a sua informaçao
                fscanf(fp, "%d", &novo->dias_doente);
            }
            novo->prox = NULL;
            if (p == NULL) { // se a lista estiver vazia o p é o ultimo nó
                p = novo;
            } else { // se a lista nao estiver vazia, o anterior aponta para o novo que neste caso é o ultimo
                anterior->prox = novo;
            }
            anterior = novo; // o anterior é o novo
        }
    }
    return p;
}

void inserePessoasLocais(local *tab, p_pessoa p, int total) {
    int capacidade, indice, *capacidades, flag = 0;

    capacidades = malloc(sizeof (total));


    if (capacidades != NULL) {

        for (int i = 0; i < total; i++) {
            capacidades[i] = tab[i].capacidade;
        }

        while (p != NULL) {

            for (int j = 0; j < total; j++) {

                if (capacidades[j] != 0) { // verifica se ha locais ainda com capacidade
                    flag = 1;
                    break;
                }
            }

            if (!flag) {
                printf("Não há espaço suficiente para participarem todas as pessoas\n");
                break;
            }

            do {
                indice = intUniformRnd(0, total - 1); // gera um indice de 0 ao numero total-1 para ser usado na posiçao dos IDs
            } while (capacidades[indice] == 0); // procura um local com capacidade 

            p->local = &tab[indice]; // insere a pessoa no local

            capacidades[indice] -= 1; // decrementa 1 valor na capacidade visto que foi inserida uma pessoa


            p = p->prox;
        }

    } else {
        printf("Erro na alocação de memória\n");
        return;
    }
}

p_pessoa criaPessoa(p_pessoa p, local *tab, int total) {
    int i = 0;
    p_pessoa novo;
    p_pessoa aux;

    novo = malloc(sizeof (pessoas));


    if (novo == NULL) {
        printf("Erro na alocação de memória\n");
        return p;
    } else { // adiciona uma pessoa nova na lista ligada
        int flag = 0;
        int id = 0;
        int capacidade = 0;


        while (!flag) {
            aux = p;
            printf("Qual é o id: ");
            scanf("%d", &id);
            for (i = 0; i < total; i++) { // percorro as salas
                if (id == tab[i].id) { // se encontrar o id que o utilizador colocou
                    capacidade = contaPessoasSala(aux, id); // calculo a capacidade da sala em questão
                    if (capacidade + 1 <= tab[i].capacidade) { // verifico se ha capacidade ainda
                        flag = 1;
                        break;
                    } else {
                        printf("Na sala %d nao há capacidade suficiente para adicionar mais um doente\n", tab[i].id);
                    }
                }
            }
        }

        if (flag) {
            novo->local = &tab[i];
            printf("Qual é o identificador da pessoa: ");
            scanf(" %s", novo->nome);

            do {
                printf("Qual é a idade: ");
                scanf("%d", &novo->idade);
            }while(novo->idade < 0);


            novo->estado = 'D';
            
            do{
             printf("Há quantos dias esta doente: ");
             scanf("%d", &novo->dias_doente);   
            }while(novo->dias_doente < 0);
            

            novo->prox = p; // digo que o novo aponta para o primeiro da lista (p aponta para o primeiro da lista)
            p = novo; // digo que o p, é agora o novo, logo o novo fica o primeiro da lista
        }




    }
    return p;

}


