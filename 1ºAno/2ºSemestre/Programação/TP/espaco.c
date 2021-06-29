
/* 
 * File:   espaco.c
 * Author: Bruno Teixeira 2019100036
 * 
 * Created on 04 April 2020, 11:50
 */
#include "espaco.h"
#include <stdio.h>
#include <stdlib.h>

void mostraTodosLocais(local *tab, int total) {

    for (int i = 0; i < total; i++) {
        printf("Id: %d\n", tab[i].id);
        printf("Capacidade: %d\n", tab[i].capacidade);
        for (int j = 0; j < 3; j++) {
            if (tab[i].liga[j] >= 0) {
                printf("Liga: %d\n", tab[i].liga[j]);

            }

        }
        printf("====================\n");

    }
}

local *escreveArrayLocal(local *tab, int *total) {
    local *p = NULL;
    FILE *fp;
    int len;
    char file[32];

    printf("Qual é o nome do ficheiro relativo ao espaço a utilizar na simulação? ");
    scanf("%s", file);
    fp = fopen(file, "rb");

    if (fp == NULL) {
        printf("Certifique-se que o ficheiro existe\n");
        return 0;
    }
    fseek(fp, 0, SEEK_END); // coloco o cursor no fim do ficheiro

    len = ftell(fp); // descobre o tamanho do ficheiro


    *total = len / sizeof (local); // calculo aqui quantas estruturas existem em cada ficheiro

    p = malloc(sizeof (local) * *(total)); // aloco um espaço de memoria consoante o resultado do *total

    if (p == NULL) {
        return tab;
    }
    tab = p; // uma vez que a alocaçao nao falhou, posso apontar o tab para o mesmo endereço do p
    fseek(fp, 0, SEEK_SET); // volto a colocar o cursor no inicio do ficheiro

    for (int i = 0; i < *total; i++) {
        fread(&tab[i], sizeof (local), 1, fp); // leio do ficheiro cada estrutura e coloco no array dinamico
    }


    fclose(fp);

    return tab;

}

void validaDadosIniciais(local *tab, int total) {

    int id_adjacente;

    // para cada sala no array de salas
    for (int i = 0; i < total; i++) {


        for (int x = i + 1; x < total; x++) {
            // se houverem ids repetidos o programa termina
            if (tab[i].id == tab[x].id) {
                printf("Há ids repetidos");
                return;
            }
        }


        // procura se ha ids negativos
        if (tab[i].id < 0) {
            printf("Os ids dos locais tem de ser sempre positivos\n");
            return;
        }


        local sala1 = tab[i];
        int id_sala1 = sala1.id;

        // percorre o respetivo array das ligacoes
        for (int j = 0; j < 3; j++) {
            // se a ligacao for -1 nao interessa porque significa que nao liga a nada
            if (sala1.liga[j] != -1) {
                id_adjacente = sala1.liga[j];
            }


            //procura a sala com id igual a id_adjacente no array de salas
            for (int k = 0; k < total; k++) {
                local sala2 = tab[k];

                // caso a sala encontrada for igual à atual, continua sem fazer nada
                if (sala2.id == id_sala1) continue; // fazemos isto porque a sala 2 pode ser == à sala1 uma vez que começamos do 0 aqui 

                int sala1_encontrada = 0;

                // se o id da sala2 for igual à ligacao da sala adjacente
                if (sala2.id == id_adjacente) {

                    //procura o id da sala 1 na lista de ligacoes da sala2
                    for (int l = 0; l < 3; l++) {

                        //se encontrar poe a flag a 1
                        if (sala2.liga[l] == id_sala1) {
                            sala1_encontrada = 1;
                            break;
                        }
                    }
                }
                // se ja encontrou nao vai continuar a procurar pela sala
                if (sala1_encontrada)break;

                    // se nao encontrou houve um erro e ha ligacoes mal feitas
                else return;

            }
        }

    }

}


