/* 
 * File:   espaco.h
 * Author: Bruno Teixeira 2019100036
 *
 * Created on 04 April 2020, 11:50
 */

#ifndef ESPACO_H
#define ESPACO_H


typedef struct sala local, *plocal;
struct sala{
    int id; // id númerico do local
    int capacidade; // capacidade maxima
    int liga[3]; // id das ligações (-1 nos casos nao usados)
};

void mostraTodosLocais(local tab[], int total); //função que mostra todos os locais
local *escreveArrayLocal(local *tab, int *total); // função que lê dados do ficheiro e escreve num array dinâmico
void validaDadosIniciais(local *tab, int total); // função que valida dados

#endif /* ESPACO_H */
