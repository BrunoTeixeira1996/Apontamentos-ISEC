/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iter.c
 * Author: Bruno Teixeira 2019100036
 * 
 * Created on 01 June 2020, 19:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoas.h"
#include "iter.h"

p_iteracoes copia_lista(p_iteracoes lista_iteracoes, p_pessoa Pessoas, int conta_ite) {
    p_iteracoes novoIte, aux;
    p_pessoa no_pessoa, lista_aux, pessoas_aux;


    novoIte = malloc(sizeof (iteracoes)); // aloco espaço para o nó da lista principal

    if (novoIte == NULL) {
        printf("Erro na alocação de memória\n");
        return lista_iteracoes;
    }

    novoIte->pessoa = NULL;
    novoIte->numero_iteracoes = conta_ite;
    if (lista_iteracoes == NULL) {
        lista_iteracoes = novoIte;
        novoIte->prox = NULL;
    } else {

        aux = lista_iteracoes;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novoIte;
        novoIte->prox = NULL;
    }


    pessoas_aux = Pessoas;

    while (pessoas_aux != NULL) { // percorro a lista das pessoas

        no_pessoa = malloc(sizeof (pessoas)); // aloco espaço para uma pessoa

        if (no_pessoa == NULL) {
            printf("Erro na alocação de memória\n");
            return lista_iteracoes;
        }
        strcpy(no_pessoa->nome, pessoas_aux->nome);
        no_pessoa->idade = pessoas_aux->idade;
        no_pessoa->estado = pessoas_aux->estado;
        no_pessoa->dias_doente = pessoas_aux->dias_doente;
        no_pessoa->prox = NULL;
        no_pessoa->local = pessoas_aux->local;

        if (novoIte->pessoa == NULL) { // se for insereção no inicio
            novoIte->pessoa = no_pessoa;
        } else {

            lista_aux = novoIte->pessoa;

            while (lista_aux->prox != NULL) {
                lista_aux = lista_aux->prox;
            }
            lista_aux->prox = no_pessoa;
        }
        pessoas_aux = pessoas_aux->prox;
    }


    return lista_iteracoes;

}

void escreve_tudo(p_iteracoes p) {

    p_iteracoes aux = p;
    p_pessoa lista_p;


    while (aux != NULL) {
        printf("Numero da iteracao %d\n", aux->numero_iteracoes);
        lista_p = aux->pessoa;
        while (lista_p != NULL) {
            printf("Id:  Nome: %s  Idade: %d Estado: %c ",  lista_p->nome, lista_p->idade, lista_p->estado);
            if (lista_p->estado == 'D') {
                printf("%d", lista_p->dias_doente);
            }
            printf("\n");
            lista_p = lista_p->prox;
        }
        aux = aux->prox;
        printf("\n");
    }
}

p_pessoa voltaXIte(p_pessoa p, p_iteracoes lista_iteracoes, int *aux_conta) {
    p_iteracoes aux_ite, aux_elim;
    p_pessoa aux_pessoa = NULL, no_pessoa, corre;
    int n_ant = 0;

    do {
        printf("Quantas iterações quer recuar?");
        scanf("%d", &n_ant);
    } while (n_ant < 1 || n_ant > 3 || (*aux_conta - n_ant) < 0);

    aux_ite = lista_iteracoes;

    while ((*(aux_conta) - n_ant) != aux_ite->numero_iteracoes) {
        if (aux_conta == NULL) {
            return NULL;
        }
        aux_ite = aux_ite->prox;
    }
    *(aux_conta) = aux_ite->numero_iteracoes; // troco o dia para o dia que quero ir


    if (aux_ite == NULL) {
        printf("Erro\n");
        return p;
    } else {
        p = limpaLista(p);

        aux_pessoa = aux_ite->pessoa;

        while (aux_pessoa != NULL) { 
            no_pessoa = malloc(sizeof (pessoas));

            if (no_pessoa == NULL) {
                return p;
            }

            strcpy(no_pessoa->nome, aux_pessoa->nome);
            no_pessoa->estado = aux_pessoa->estado;
            no_pessoa->idade = aux_pessoa->idade;
            no_pessoa->dias_doente = aux_pessoa->dias_doente;
            no_pessoa->local = aux_pessoa->local;
            no_pessoa->prox = NULL;
            
            if (p == NULL) {
                p = no_pessoa;
            } else {
                corre = p;

                while (corre->prox != NULL) {

                    corre = corre->prox;
                }
                corre->prox = no_pessoa;
            }
            aux_pessoa = aux_pessoa->prox;
        }
       
    }

    return p;
}

p_pessoa limpaLista(p_pessoa p) {
    p_pessoa aux;

    while (p != NULL) {
        aux = p;
        p = p->prox;
        free(aux);
    }

    return p;
}