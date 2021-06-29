/* 
 * File:   utils.h
 * Author: Bruno Teixeira 2019100036
 *
 * Created on 10 April 2020, 22:27
 */

#ifndef UTILS_H
#define UTILS_H

// Funções dadas no enunciado
void initRandom();
int intUniformRnd(int a, int b);
int probEvento(float prob);


/*Funções Auxiliares*/
int *copy(local *tab, int total); // função que copia os IDs do tab para um novo array dinamico ids
int contaPessoasSala(p_pessoa p, int id_sala); // função que conta o numero de pessoas por sala
int ligaDireta(int id_origem, int id_destino, int total, local *tab); // função que verifica se dois locais tem ligação direta
int verificaPessoas(int n_pessoas, int total, p_pessoa p, int id_origem, int id_destino, local *tab); // verifica se é possivel transferir pessoas entre salas
void mostraIteracoesFich(int *conta_ite); // conta o numero de iterações da simulação
void printaHead(); // função que escreve no ficheiro os dados relativos à última iteração
void limpaTerminal(); // função que limpa o terminal
int verificaIdsPessoas(p_pessoa p, int id_origem); // função que vê se existe o id_origem nas pessoas

/*Funções de escrita*/
void printIdadeDoentes(p_pessoa p);
void printIdadeDoentesFich(p_pessoa p);
void printTaxaSDI(p_pessoa p);
void printfTaxaSDIFich(p_pessoa p);


/*Funções Probabilidades e Taxas*/
void pessoasSalas(p_pessoa p, local *tab, int total); // função que mostra a distribuição de pessoas por salas
void probRecuperacao(p_pessoa p); // probabilidade de recuperação de uma pessoa - p->estado 'R'
void durMaxInf(p_pessoa p); // duração máxima da infeção
void taxaImu(p_pessoa p); // taxa de imunidade
void taxaDi(p_pessoa p, local *tab, int total); // taxa disseminação
void taxaSDI(p_pessoa p, double *taxa_saudavel, double *taxa_doente, double *taxa_imune, double *taxa_recuperado); // mostra taxa de Saudaveis Doentes e Imunes
void mediaIdadeDoentes(p_pessoa p, double *media, int *idade, int *tempo_doente); // media da idade das pessoas doentes e pessoa ha mais dias doente



/*Funções da simulação*/
void transPesso(p_pessoa p, int total, local *tab);//transfere N pessoas de um local origem para um local destino
void terminaSimu(p_pessoa p, int conta_ite); // termina a simulação
void escreveUltimaFich(p_pessoa p); // escreve num ficheiro o estado das pessoas na ultima iteração
int menu(); // menu da aplicação
void escreveUltimoReport(p_pessoa p); //escreve no ficheiro reports

#endif /* UTILS_H */
