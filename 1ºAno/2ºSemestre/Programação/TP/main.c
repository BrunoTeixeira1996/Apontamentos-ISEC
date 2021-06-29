/* 
 * File:   main.c
 * Author: Bruno Teixeira 2019100036
 *
 * Created on 03 April 2020, 22:57
 */

#include <stdio.h>
#include <stdlib.h>
#include "espaco.h"
#include "pessoas.h"
#include "utils.h"
#include "iter.h"

void avaInt(p_pessoa p, local *tab, int total){
    taxaDi(p,tab,total);
    while(p != NULL){
        if(p->estado == 'D'){
        p->dias_doente++;
        }
        probRecuperacao(p); // probabilidade de recuperaçao. se recuperar  p->estado = 'R'
        durMaxInf(p); // duração máxima da infeção
        taxaImu(p); // taxa de imunidade        
        p = p->prox;
    }
    
}

void mostraEst(p_pessoa p, local *tab, int total){
    double media;
    int idade, tempo_doente, total_pessoas;
    double taxa_saudavel, taxa_doente, taxa_imune,taxa_recuperado;
    
    taxaSDI(p,&taxa_saudavel,&taxa_doente,&taxa_imune,&taxa_recuperado); // taxas das pessoas
    printTaxaSDI(p); // mostra no terminal    
    mediaIdadeDoentes(p,&media,&idade,&tempo_doente); // media idade das pessoas doentes
    printIdadeDoentes(p); // mostra no terminal 
    
    pessoasSalas(p,tab,total); //pessoas por sala
}

int main(int argc, char** argv) {
    
    p_iteracoes lista_iteracoes = NULL; // lista das iteracoes
    
    local *sitio = NULL; // array dinamico dos locais
    p_pessoa lista = NULL; // lista ligada
    int *ids; // array com os ids
    int total = 0, i, n_ant = 0;
    
    
    sitio = escreveArrayLocal(sitio,&total); //le o ficheiro e insere no array dinamico os dados da estrutura que esta contida no ficheiro
    if(sitio == 0){
        return 0;
    }
    
    validaDadosIniciais(sitio,total); // valida os ids, sendo eles unicos e positivos
    

    
    lista = escreveNaLista(lista); // funçao que escreve na lista ligada as pessoas
    if(lista == 0){
        return 0;
    }
    
    initRandom();


    inserePessoasLocais(sitio,lista,total);


    printIdadeDoentesFich(lista);
    printfTaxaSDIFich(lista);
    

    printf("\n");
    

    int conta_ite = 0;
    int aux_conta = 0;
    
     do{
         printf("\n");
         printf("\t               Dia %d\n", aux_conta);
        i = menu();
        switch(i){
            case 1: lista_iteracoes = copia_lista(lista_iteracoes,lista, conta_ite);
                    avaInt(lista,sitio,total);
                    conta_ite++;
                    aux_conta++;
                    break;        
            case 2: mostraEst(lista,sitio,total);break;
            case 3: lista = criaPessoa(lista,sitio,total);break;
            case 4: transPesso(lista,total,sitio);break;
            case 5: mostraInfoPessoa(lista);break;
            case 6: lista = voltaXIte(lista,lista_iteracoes,&aux_conta);
                    conta_ite = aux_conta;break;
                    break;
            case 7: limpaTerminal(); break;
            case 8:terminaSimu(lista,conta_ite);return 0;
        }
        
    }while( i != 9);
    
    free(lista);
    free(sitio);
    free(lista_iteracoes);
   return 0;
}

