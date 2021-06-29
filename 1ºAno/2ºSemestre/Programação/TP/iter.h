/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   iter.h
 * Author: Bruno Teixeira 2019100036
 *
 * Created on 01 June 2020, 19:37
 */

#ifndef ITER_H
#define ITER_H

typedef struct iteracoes iteracoes, *p_iteracoes;
struct iteracoes{
    int numero_iteracoes;
    p_pessoa pessoa;
    p_iteracoes prox;
};



p_iteracoes copia_lista(p_iteracoes lista_iteracoes, p_pessoa pessoas, int conta_ite);
void escreve_tudo(p_iteracoes p);
p_pessoa voltaXIte(p_pessoa p, p_iteracoes lista_iteracoes, int *aux_conta);
p_pessoa limpaLista(p_pessoa p);

#endif /* ITER_H */
