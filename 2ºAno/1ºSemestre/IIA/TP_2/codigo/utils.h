
int **leDados(char *nome_fich, int *m, int *g); // le dados do ficheiro e preenche matriz
void mostraMatriz(int **mat, int m); //mostra dados da matriz
int verificaAux(int *aux,int g,int n);
void geraSolInicial(int *solucao, int m, int g); // gera solucao inicial
void mostraSol(int *solucao, int m); // mostra solucao inicial

int calculaFit(int *solucao, int m, int g,int **matriz, int n); // calcula qualidade da solucao
void substituiSol(int *a, int *b, int m); //substitui solucao por uma nova


struct info leEA(char *nome_fich); // preenche uma struct info
pchrom initPop(struct info *d); // inicia populacao
void mostraPop(chrom x, struct info *d); // mostra uma solucao
void mostraTudo(pchrom x, struct info *d); // mostra a populacao total

int verificaValida(int *solucao, struct info *d); //valida solucao
int verificaValidaPen(int *solucao, struct info *d);//valida solucao com penalizacao
int contaNumsArray(int *solucai, int num, struct info *d); // conta um numero especifico num array
int avaliaIndividual_1(int *solucao, struct info *d, int **mat, int *valido); // penalizacao cega
int avaliaIndividual_2(int *solucao, struct info *d, int **mat, int *valido); // penalizacao e reparacao
void verificaGeral_1(pchrom pop, struct info *d, int **mat); // penalizacao cega
void verificaGeral_2(pchrom pop, struct info *d, int **mat); // com penalizacao e reparacao

chrom getMelhor(pchrom pop, struct info *d, chrom best); // devolve melhor solucao
int contaInvals(struct info *d,pchrom pop); // conta solucoes invalidas
int contaMenosUns(int *aux, int tam);


void reparacao(int *solucao, struct info *d);

void init_rand(); // inicializa o gerador de nrs aleatorios
int random_l_h(int min,int max); // devolve um int aleatorio num intervalor
float rand_01(); //devolve um valor entre 0 e 1
