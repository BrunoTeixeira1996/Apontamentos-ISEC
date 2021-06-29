/* 
 * File:   pessoas.h
 * Author: Bruno Teixeira 2019100036
 *
 * Created on 04 April 2020, 11:50
 */

#ifndef PESSOAS_H
#define PESSOAS_H
#include "espaco.h"

typedef struct pessoas pessoas, *p_pessoa;
struct pessoas{
    char nome[100]; // Identificador único alfanumérico (1 palavra)
    int idade; // idade da pessoa
    char estado; // Estado: 'S' -> Saudavel, 'D' -> Doente, 'I' -> Imune
    int dias_doente; // caso esteja doente, mostra ha quantos dias foi infetado
    p_pessoa prox; // ponteiro que aponta para o proximo elemento da lista
    plocal local; // ponteiro que aponta para a estrutura referente ao espaço
};

p_pessoa escreveNaLista(p_pessoa aux); // função que le o ficheiro txt e escreve na lista ligada
void mostraInfoPessoa(p_pessoa p); // função que mostra informação que está contida na lista ligada
void  inserePessoasLocais(local *tab, p_pessoa p, int total); // função que insere pessoas em locais
p_pessoa criaPessoa(p_pessoa p, local *tab, int total); // função que cria uma pessoa para o inicio da lista ligada


#endif /* PESSOAS_H */
