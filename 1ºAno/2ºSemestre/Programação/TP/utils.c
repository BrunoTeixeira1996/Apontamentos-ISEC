/* 
 * File:   utils.c
 * Author: Bruno Teixeira 2019100036
 * 
 * Created on 10 April 2020, 22:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "espaco.h"
#include "pessoas.h"
#include "utils.h"
#include "iter.h"

void initRandom() {
    srand(time(NULL));
}

int intUniformRnd(int a, int b) {
    return a + rand() % (b - a + 1);
}

int probEvento(float prob) {
    return prob > ((float) rand() / RAND_MAX);
}

int *copy(local *tab, int total) {

    int *ids = malloc(sizeof (int) * total);

    for (int i = 0; i < total; i++) {
        ids[i] = tab[i].id;
    }
    return ids;
}

void taxaSDI(p_pessoa p, double *taxa_saudavel, double *taxa_doente, double *taxa_imune, double *taxa_recuperado) {

    int saudavel = 0, doente = 0, imune = 0, recuperado = 0, total_pessoas = 0;


    while (p != NULL) {
        total_pessoas++;
        if (p->estado == 'S') {
            saudavel++;
        } else if (p->estado == 'D') {
            doente++;
        } else if (p->estado == 'I') {
            imune++;
        } else if (p->estado == 'R') {
            recuperado++;
        }
        p = p->prox;
    }

    *taxa_saudavel = saudavel / (double) total_pessoas;
    *taxa_doente = doente / (double) total_pessoas;
    *taxa_imune = imune / (double) total_pessoas;
    *taxa_recuperado = recuperado / (double) total_pessoas;

}

void printTaxaSDI(p_pessoa p) {
    p_pessoa aux;
    aux = p;
    double taxa_saudavel, taxa_doente, taxa_imune, taxa_recuperado;
    int total_pessoas;

    taxaSDI(aux, &taxa_saudavel, &taxa_doente, &taxa_imune, &taxa_recuperado);

    printf("\n");
    printf("======================================\n");
    printf("|\t         Taxas               |\n");
    printf("|                                    |\n");
    printf("|\tTaxa de saudaveis: %.2f      | \n", taxa_saudavel);
    printf("|\tTaxa de doentes: %.2f        | \n", taxa_doente);
    printf("|\tTaxa de imunes: %.2f         | \n", taxa_imune);
    printf("|\tTaxa de recuperados: %.2f    | \n", taxa_recuperado);
    printf("======================================\n");
    printf("\n");
}

void printfTaxaSDIFich(p_pessoa p) {
    p_pessoa aux;
    aux = p;
    double taxa_saudavel, taxa_doente, taxa_imune, taxa_recuperado;
    int total_pessoas, total_saudaveis, total_doentes, total_imunes, total_recuperados;

    taxaSDI(aux, &taxa_saudavel, &taxa_doente, &taxa_imune, &taxa_recuperado);

    FILE *f;

    f = fopen("reports.txt", "a");
    if (f == NULL) {
        printf("Erro ao escrever no ficheiro reports.txt\n");
        return;
    }

    fprintf(f, "======================================\n");
    fprintf(f, "|\t         Taxas               |\n");
    fprintf(f, "|                                    |\n");
    fprintf(f, "|\tTaxa de saudaveis: %.2f      | \n", taxa_saudavel);
    fprintf(f, "|\tTaxa de doentes: %.2f        | \n", taxa_doente);
    fprintf(f, "|\tTaxa de imunes: %.2f         | \n", taxa_imune);
    fprintf(f, "|\tTaxa de recuperados: %.2f    | \n", taxa_recuperado);
    fprintf(f, "======================================\n");
    fprintf(f, "\n");

    fclose(f);
}

void mediaIdadeDoentes(p_pessoa p, double *media, int *idade, int *tempo_doente) {
    int soma = 0, n_doentes = 0;

    while (p != NULL) {

        if (p->estado == 'D') {

            soma = soma + p->idade;
            n_doentes++;

            if (*(tempo_doente) < p->dias_doente) {
                *(tempo_doente) = p->dias_doente;
                *(idade) = p->idade;
            }
        }
        p = p->prox;
    }

    *(media) = soma / (double) n_doentes;


}

void printIdadeDoentes(p_pessoa p) {
    p_pessoa aux;
    aux = p;

    double media;
    int idade, tempo_doente;


    mediaIdadeDoentes(aux, &media, &idade, &tempo_doente);

    if (idade == 0) {
        printf("===============================================================================\n");
        printf("|\t                        Não há pessoas doentes                        |\n");
        printf("===============================================================================\n");
    } else {

        printf("===============================================================================\n");
        printf("|\t                        Médias                                        |\n");
        printf("|                                                                             |\n");
        printf("|\t A média de idades de pessoas doentes é de %.2f                      |\n", media);
        printf("| A pessoa que está ha mais tempo doente tem %d anos e está há %d dias doente |\n", idade, tempo_doente);
        printf("===============================================================================\n");
        printf("\n");
    }
}

void printIdadeDoentesFich(p_pessoa p) {
    double media;
    int idade, tempo_doente;
    p_pessoa aux;
    aux = p;

    FILE *f;

    f = fopen("reports.txt", "w");
    if (f == NULL) {
        printf("Erro ao escrever no ficheiro reports.txt\n");
        return;
    }

    mediaIdadeDoentes(aux, &media, &idade, &tempo_doente);

    if (idade == 0) {
        fprintf(f, "===============================================================================\n");
        fprintf(f, "|\t                        Não há pessoas doentes                        |\n");
        fprintf(f, "===============================================================================\n");
    } else {


        fprintf(f, "===============================================================================\n");
        fprintf(f, "|\t                   Dados relativos à primeira iteração                |\n");
        fprintf(f, "===============================================================================\n");
        fprintf(f, "\n");
        fprintf(f, "===============================================================================\n");
        fprintf(f, "|\t                        Médias                                        |\n");
        fprintf(f, "|                                                                             |\n");
        fprintf(f, "|\t A média de idades de pessoas doentes é de %.2f                      |\n", media);
        fprintf(f, "| A pessoa que está ha mais tempo doente tem %d anos e está há %d dias doente |\n", idade, tempo_doente);
        fprintf(f, "===============================================================================\n");
        fprintf(f, "\n");
    }
    fclose(f);
}

void probRecuperacao(p_pessoa p) {

    int contador = 0, idade = 0;
    float resultado;

    if (p->estado == 'D') {
        idade = p->idade;
        resultado = 1 / (double) idade;
        if (probEvento(resultado) == 1) {
            p->estado = 'R';
        }
    }

}

void durMaxInf(p_pessoa p) {
    int idade = 0, dias_doente = 0;
    float resultado;

    if (p->estado == 'D') {
        idade = p->idade;
        dias_doente = p->dias_doente;
        resultado = ((double) idade / 10) + 5;
        if ((int) resultado <= dias_doente) {
            p->estado = 'R';
        }
    }

}

void taxaImu(p_pessoa p) {

    if (p->estado == 'R') { //significa que eles recuperaram ou a duraçao maxima da infeção foi aplicada
        if (probEvento(0.2) == 1) {
            p->estado = 'I';
            printf("\nO doente %s ficou imune\n", p->nome);
        }
    }
}

void pessoasSalas(p_pessoa p, local *tab, int total) {
    int *ids;
    int pessoas_sala = 0;


    ids = copy(tab, total);

    printf("==================================================\n");
    printf("|\t        Pessoas por sala                 |\n");
    printf("|                                                |\n");
    for (int i = 0; i < total; i++) {
        p_pessoa aux = p;

        while (aux != NULL) {
            if (ids[i] == aux->local->id) {
                pessoas_sala++; // conta pessoas por sala
            }
            aux = aux->prox;
        }

        printf("|\t       Há %d pessoas na sala %d           |\n", pessoas_sala, ids[i]);
        pessoas_sala = 0;
    }
    printf("==================================================\n");
}

void taxaDi(p_pessoa p, local *tab, int total) {
    int *ids;
    int pessoas_sala = 0, conta_doentes = 0, taxa_d = 0;
    float res;


    ids = copy(tab, total);

    for (int i = 0; i < total; i++) {
        p_pessoa aux = p;


        while (aux != NULL) {
            if (ids[i] == aux->local->id) {
                pessoas_sala++; // conta pessoas por sala
                if (aux->estado == 'D') { // conta doentes por sala
                    conta_doentes++;
                }
            }

            aux = aux->prox;
        }
        res = (float) pessoas_sala * 0.05; // numero de pessoas que um doente infeta
        taxa_d = conta_doentes * (int) res; // total de pessoas que irão ficar doente em cada sala

        p_pessoa novo = p;
        while (taxa_d > 0 && novo != NULL) { // enquanto houver pessoas para ficarem doentes numa sala && novo nao chegar ao fim
            if (ids[i] == novo->local->id) { // se as pessoas estiverem na mesma sala
                if (novo->estado == 'S') { // se o estado for S , torna-se D e a ha menos 1 pessoa a ficar infetada
                    novo->estado = 'D';
                    taxa_d--;
                }
            }
            novo = novo->prox;
        }



        pessoas_sala = 0;
        conta_doentes = 0;
        res = 0;
        taxa_d = 0;
    }
}

int ligaDireta(int id_origem, int id_destino, int total, local *tab) {

    int i, j, flag = 0;

    for (i = 0; i < total && tab[i].id != id_origem; i++);

    if (i == total) {
        printf("O id de origem não existe\n");
        return 0; //o id_origem está errado
    } else {
        for (j = 0; j < total && tab[j].id != id_destino; j++);

        if (j == total) {
            printf("O id de destino não exsite\n");
            return 0; // o id_destino está errado
        } else {
            for (int x = 0; x < 3; x++) {
                if (tab[j].liga[x] == tab[i].id) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                return 1; // ha ligação direta
            } else {
                printf("Não é possível fazer a transferência porque não ha ligação direta entre as salas em questão\n");
                return 0; // nao ha ligação direta
            }
        }
    }
}

int verificaPessoas(int n_pessoas, int total, p_pessoa p, int id_origem, int id_destino, local *tab) {
    int numero_pessoas_origem = 0, flag = 0, numero_pessoas_destino = 0, capacidade_destino = 0, soma = 0;


    numero_pessoas_origem = contaPessoasSala(p, id_origem); //guarda o numero de pessoas na sala de origem e o numero de pessoas na sala de destino
    numero_pessoas_destino = contaPessoasSala(p, id_destino);


    for (int i = 0; i < total; i++) {
        if (tab[i].id == id_destino) { // guarda o valor da capacidade da sala de destino
            capacidade_destino = tab[i].capacidade;
            break;
        }
    }
    // se o nr de pessoas do destino < capacidade ainda ha espaço para inserir pessoas e se o n_pessoas for menor ou igual à quntiade de pessoas na sala de origem
    if (numero_pessoas_destino < capacidade_destino) {
        if (n_pessoas <= numero_pessoas_origem) {
            flag = 1;
        } else {
            printf("O numero de pessoas a transferir nao é válido\n");
        }
    } else {
        printf("A sala está cheia\n");
    }

    if (flag) {
        soma = numero_pessoas_destino + n_pessoas;
        if (soma <= capacidade_destino) { // verifico se ao inserir aquele nr de pessoas, se ultrapassa ou nao a capacidade de destino
            return 1;
        } else {
            printf("Ao inserir este numero de pessoas, irá ultrapassar a capacidade da sala de destino\n");
            return 0;
        }
    } else {
        return 0;
    }


}

int contaPessoasSala(p_pessoa p, int id_sala) {

    int numero_pessoas = 0;
    while (p != NULL) {
        if (p->local->id == id_sala) {
            numero_pessoas++;
        }

        p = p->prox;
    }

    return numero_pessoas;


}

int verificaIdsPessoas(p_pessoa p, int id_origem) {
    int flag = 0;

    while (p != NULL) {
        if (p->local->id == id_origem) {
            flag = 1;
            break;
        }
        p = p->prox;
    }
    if (flag) {
        return 1;
    } else {
        printf("Não há nenhuma pessoa na sala de origem\n");
        return 0;
    }
}

void transPesso(p_pessoa p, int total, local *tab) {
    int n_pessoas, id_origem, id_destino, contador, flag = 0;
    p_pessoa aux;

    do {
        printf("Sala de origem: ");
        scanf("%d", &id_origem);

        printf("Sala de destino: ");
        scanf("%d", &id_destino);
    } while (ligaDireta(id_origem, id_destino, total, tab) == 0 || verificaIdsPessoas(p, id_origem) == 0);

    do {
        printf("Quantas pessoas da sala de origem quer passar? ");
        scanf("%d", &n_pessoas);

    } while (verificaPessoas(n_pessoas, total, p, id_origem, id_destino, tab) == 0);

    contador = n_pessoas;



    int encontrou;

    for (int i = 0; i < total; i++) {
        if (id_destino == tab[i].id) {
            encontrou = i;
            break;
        }
    }

    while (contador != 0) {

        int numero_pessoas_origem = contaPessoasSala(p, id_origem);

        aux = p;

        int nb = intUniformRnd(1, numero_pessoas_origem);

        while (aux != NULL) {
            if (aux->local->id == id_origem) { // o nb é um nr aleatorio no limite do numero_pessoas_origem
                nb--;

                if (nb == 0) { // significa que ja encontrei a pessoa que vai ser transferida

                    aux->local = &tab[encontrou];
                    contador--;
                    flag = 1;
                    break;
                }

            }
            aux = aux->prox;
        }

    }
    if (flag) {
        printf("Transferência feita com sucesso\n");
    }
}

int menu() {
    int i;
    printf("==================================================\n");
    printf("|\t               Menu                      |\n");
    printf("|                                                |\n");
    printf("|\t 1 - Avançar uma iteração na simulação   | \n");
    printf("|\t 2 - Apresentar estatisticas             | \n");
    printf("|\t 3 - Adicionar doente                    | \n");
    printf("|\t 4 - Transferir pessoa para outro local  | \n");
    printf("|\t 5 - Mostrar informação das pessoas      | \n");
    printf("|\t 6 - Voltar atrás X iterações            |   \n");
    printf("|\t 7 - Limpar o terminal                   | \n");
    printf("|\t 8 - Terminar simulação                  |\n");
    printf("==================================================\n");
    printf("Escolha uma opção:");
    printf("\n");
    do {
        scanf("%d", &i);
    } while (i < 1 || i > 9);

    return i;
}

void limpaTerminal() {
    printf("\e[1;1H\e[2J");
}

void mostraIteracoesFich(int *conta_ite) { /*Apresentar o nr total de iterações para escrever no ficheiro no final da simulação*/

    FILE *f;

    f = fopen("reports.txt", "a");

    if (f == NULL) {
        printf("Houve um erro a escrever o numero de iterações no ficheiro reports.txt\n");
        return;
    }
    fprintf(f, "================================\n");
    fprintf(f, " | Houve no total %d iterações |\n", *(conta_ite));
    fprintf(f, "=================================\n");
    fclose(f);
}

void escreveUltimaFich(p_pessoa p) {
    FILE *f;
    char file[32];

    printf("Qual é o nome do ficheiro de texto para colocar a informação das pessoas, relativamente à última iteração? ");
    scanf("%s", file);
    f = fopen(file, "w");

    if (f == NULL) {
        printf("Erro a abrir o ficheiro\n");
        return;

    }
    while (p != NULL) {
        fprintf(f, "Id: %d Nome: %s  Idade: %d Estado: %c ", p->local->id, p->nome, p->idade, p->estado);
        if (p->estado == 'D') {
            fprintf(f, "%d", p->dias_doente);
        }
        fprintf(f, "\n");
        p = p->prox;
    }
    fclose(f);
}

void printaHead() {
    FILE *f;

    f = fopen("reports.txt", "a");

    if (f == NULL) {
        printf("Erro a escrever no ficheiro");
        return;
    }
    fprintf(f, "===============================================================================\n");
    fprintf(f, "|\t                   Dados relativos à última iteração                |\n");
    fprintf(f, "===============================================================================\n");
    fprintf(f, "\n");
    fclose(f);
}

void escreveUltimoReport(p_pessoa p) {
    FILE *f;

    f = fopen("reports.txt", "a");

    if (f == NULL) {
        printf("Erro a abrir o ficheiro\n");
        return;

    }
    fprintf(f, "===============================================================================\n");
    fprintf(f, "|\t                   Informação final das pessoas                       |\n");
    fprintf(f, "===============================================================================\n");
    fprintf(f, "\n");
    while (p != NULL) {
        fprintf(f, "Id: %d Nome: %s  Idade: %d Estado: %c ", p->local->id, p->nome, p->idade, p->estado);
        if (p->estado == 'D') {
            fprintf(f, "%d", p->dias_doente);
        }
        fprintf(f, "\n");
        p = p->prox;
    }
    fclose(f);
}

void terminaSimu(p_pessoa p, int conta_ite) {
    printaHead();
    printfTaxaSDIFich(p);
    escreveUltimaFich(p);
    mostraIteracoesFich(&conta_ite);
    escreveUltimoReport(p);

}