# Algoritmos & Stuff

## Algortimo de ordenação -> BubbleSort
```c
#include <stdio.h>

void bubbleSort(int array[], int size)
{
  for (int step = 1; step < size ; ++step)
  {
    for (int i = 0; i < size - step - 1; ++i)
    {
      // To sort in descending order, change">" to "<".
      if (array[i] > array[i + 1])
      {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
```
```c
for com o começo i = 1 até ao total do array
    for com j = 0, até ao total-i
        se(string1 > string2)
            auxiliar = string1
            string1 = string2
            string2 = auxiliar
```
## Algoritmo eliminação ordenada 
```c
Encontrar a posiçao do elemento a eliminar 
Fazer  for j = pos até j < tamanho-1
    depois pegar no array[j] = array[j+1]
```

# Ponteiros
*Um ponteiro é uma variável capaz de armazenar um endereço de memória ou o endereço de outra variável.*
![ponteiros1](https://user-images.githubusercontent.com/12052283/78192428-0a86ff80-7470-11ea-8491-08e483b1ca4d.png)


## Exemplo
```c
#include <stdio.h>  
int main()  
{  
	int a; 
	int *ptr; // declara um ponteiro para um inteiro  
	// um ponteiro para uma variável do tipo inteiro  
	a = 90; 
	ptr = &a;  
	printf("Valor de ptr: %p, Conteúdo de ptr: %d\n", ptr, *ptr);
}
```
**__Output__**
```
Valor de ptr: 0x7ffe6a9de83c, Conteúdo de ptr: 90
```
## Aceder ao conteúdo de uma posição de memória
*Para aceder ao conteudo de uma posição de memoria, cujo endereço esta armazenado num ponteiro, usa-se o operador de referencia -> asterisco.*
```c
#include <stdio.h>  
int main()  
{  
	int x;  
	int *ptr;  
	x = 5;  
	ptr = &x;  // a partir de agora se alterar o *ptr, altero tambem o x
	printf("O valor da variável X é: %d\n", *ptr);
	*ptr = 10;
	printf("Agora, X vale: %d\n", *ptr);  

}
```
## Ponteiro e NULL
*Uma falha de segmentação (segmentation fault) ocorre quando um programa tenta aceder a um endereço na memória que está reservado ou que não existe.*
**__Programa com erro__**
```c
#include <stdio.h>
int main(){

  int  a = 5;
  int *p = null;
      *p = a;
}
```
**__O que acontece aqui?__**
*O programa termina com um segfault, uma vez que estamos a tentar colocar o valor 5 num endereço invalido. Para isto nao acontecer, o ponteiro dever ser sempre inicilizado com um endereço válido*.
__Por exemplo assim__
```c
#include <stdio.h>
int main(){
  int  a = 5;
  int *p = NULL;
       p = &a;

  /* A operação não é permitida */
  if(p == NULL) return 0 ;
     else{
          printf("Endereço a disposição:%p\n", p );
          *p = a; /* Pode colocar 5 */
    }
}
```
## Mais operações com Ponteiros
```c
int *a, *b, c = 4, d = 2;
a = &c;        // **a** apontará para **c**
b = &d;        // **b** apontará para **d**
*b = 8;        // altero o valor existente na variavel **d**
*a = *b;       // copio o valor de **d** (apontado por **b**)
                 // para **c** (apontado por **a**)
*a = 1;        // altero o valor da variável **c**
b = a;         // **b** aponta para o mesmo lugar que **a**,
                 // ou seja, para **c**
*b = 0;        // altero o valor de **c**
(*p)++;        // incrementamos o valor que o p tem
```
## Ponteiros e Vetores
*Em C, os elementos de um vetor são sempre guardados sequencialmente, a uma distância fixa um do outro. Com isso, é possível facilmente passar de um elemento a outro, percorrendo sempre uma mesma distância para frente ou para trás na memória. Dessa maneira, podemos usar ponteiros e a aritmética de ponteiros para percorrer vetores. Na verdade, vetores _são_ ponteiros ― um uso particular dos ponteiros.*
__Exemplo__
```c
#include <stdio.h>
 
 int main ()
 {
    int i;
    int vetorTeste[] = {4, 7, 1};
    int *ptr = vetorTeste;
 
    printf("%p\n", vetorTeste);
    printf("%p\n", ptr);
    printf("%p\n", &ptr);
 
    for (i = 0; i < 3; i++)
    {
       printf("O endereço do índice %d do vetor é %p\n", i, &ptr[i]);
       printf("O valor do índice %d do vetor é %d\n", i, ptr[i]);
    }
    return 0;
   }
```
__Output__
```
0x7ffe192fd68c
0x7ffe192fd68c
0x7ffe192fd680
O endereço do índice 0 do vetor é 0x7ffe192fd68c
O valor do índice 0 do vetor é 4
O endereço do índice 1 do vetor é 0x7ffe192fd690
O valor do índice 1 do vetor é 7
O endereço do índice 2 do vetor é 0x7ffe192fd694
O valor do índice 2 do vetor é 1
```
## Ponteiros para funções
__Chamada Por Referência__

*Quando fazemos a chamada de uma função podemos passar argumentos, caso existam, num processo conhecido como **chamada por valor**. Esse processo é caracterizado por copiar os valores dos argumentos para os parâmetros da função. Outro método de passar um valor para função é denominado **chamada por referência**. Nesse procedimento o endereço do argumento é passado para função, logo temos que utilizar ponteiros para manipular os endereços!*

__Porquê?__

*Esse processo é interessante, pois possibilita que alterações realizadas num parâmetro dentro de uma função alterem o valor do argumento, que está em outro escopro.*
```c
#include <stdlib.h>

void  AlterarVetor(int *vetor, int elementos){
	int  i;
	if(vetor  !=  NULL){
		for(i  =  0;  i  <  elementos;  i++){
			*(vetor)  =  *(vetor)  *  2;  //ex: V[i] = V[i] * 2
			vetor++;  //desloca o ponteiro para o próximo elemento
			}
		}
}
int  main()
{
	int v[] = {5,  10,  15,  3,  10,  76,  5,  13,  33,  45};
	int *pt;
	int i;
	pt = v;  //aponta para a primeira posiçao do vetor
	AlterarVetor(v,  10);
	for(i  =  0;  i  <  10;  i++){
		printf("V[%i] = %i\r\n",  i,  *(pt  +  i));
		}
	return  0;
}

```
## Retornando um Ponteiro
*Uma função pode retornar qualquer tipo de dado válido em C, portanto pode retornar um ponteiro! Uma função que retorna um ponteiro deve declarar explicitamente qual o tipo de ponteiro que está a retornar .*
*Outro uso comum é na utilização das funções de alocação dinâmica de memória, na qual as operações utilizam sempre endereço de blocos de memória.*

__Exemplo 1__
```c
#include <stdio.h>

void troca(int *i, int *j){
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

int main(){
	int a, b;
	
	a = 5;
	b = 10;
	
	printf ("%d %d\n", a, b);
	troca (&a, &b);
	printf ("%d %d\n", a, b);
	return  0;
}
```
__Output__
```
5 10
10 5
```
__Exemplo 2__
```c
#include<stdio.h>

int *return_pointer(int *p, int n){
	p = p + n;
	return p;
}

int main(){

	int i = 4, *ptr;
	int arr[] = {11, 22, 33, 44, 55};

	printf("Endereço do array = %p\n", arr);
	
	//nao usamos & no arr porque o arr já é um ponteiro
	ptr = return_pointer(arr, i);
	printf("Endereço do ptr = %p\n\n" , ptr);
	printf("Endereço: %p valor: %d\n", ptr, *ptr);
	
	return  0;
}
```
__Output__
```
Endereço do array = 0x7ffec37b68b0
Endereço do ptr = 0x7ffec37b68c0
Endereço: 0x7ffec37b68c0 valor: 55
```
# Estruturas
*As estruturas (structs) permitem com que possamos ter variáveis de vários tipos aglomerados sob o mesmo nome. E esse mesmo nome vai passar a ser um novo tipo de dados tal como o int ou float.*

__Exemplo__
```c
struct dados {
   char  nome[100]; 
   char nconta[15];
   int montante;
 };
```

![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Structure-In-C.png =350x)
## Declarando variaveis
```c
struct dados m;
struct dados n;
```
### Typedef
*Associa um novo nome a um tipo de dados, sendo mais pratico usar um identificador mais curto.*
```c
typedef struct dados{
	char nome[100];
	char nconta[15];
	int montante;
}cliente;
```
*Uma vez que ja criamos aquela struct com o typedef, podemos tambem declarar variaveis da seguinte maneira*
```c
cliente b;
cliente a;
```
## Acesso aos campos
### Utilização: nome_da_variavel.nome_do_campo

__Exemplo__
```c
m.montante = 1200;
scanf(“ %99[^\n]”,m.nome); 
if(strcmp(m.nconta, "X1234") == 0) 
	m.montante += 100;
```
## Estruturas encadeadas
```c
struct data{ 
	int dia, mes, ano; 
}; 
struct dados_d { 
	char nome[100];
	char nconta[15];
	int montante;
	struct data in; 
}; 
struct dados_d m; // m é variavel do tipo dados_m
```
## Estruturas em funções
*Podemos tambem passar estruturas como argumento de uma função.*
__Atenção que a estrutura é passada por valor__
```c
void escreve_info(cliente a){
	printf("Nome: %s\nNº conta: %s\tSaldo: %d\n",a.nome,a.nconta,a.montante);
	}
```
### Retornar uma estrutura
*Esta função inicializa uma estrutura do tipo cliente e devolve-a preenchida*
```c
cliente obtem_info(){
    cliente t;
    
    printf("Nome: ");scanf(" %[^\n]", t.nome);
    printf("Conta: ");scanf("%s", t.nconta);
    printf("Montante: ");scanf("%d",&(t.montante));
    
    return t;
}
```
## Estruturas e ponteiros
*Os ponteiros aqui sao fundamentais uma vez que conseguem apontar para endereços e manipular aquilo que quisermos.*
```c
cliente a = { "Bruno", "X100", 1000};
cliente *p; // declaração
p = &a // associar
p->montante = 500; //utilizar
printf("%s\n", p->nome);
```
__Exemplo__
*Função que transfere um determinado montante entre 2 clientes*
```c
int transfere(cliente *origem, cliente *destino, int valor){
	if(origem->montante < valor){
		return 0;
	}
	else{
		origem->montante -= valor;
		destino->montante += valor;
		return 1;
	}
}
```
## Array de estruturas com tamanho fixo
*Muito util por exemplo para armazenar informação relativa a diversos clientes*
__Atenção que o tamanho do array neste exemplo é sempre fixo__
```c
#define MAX 100

int main(){
	cliente banco[MAX];
	int total = 0;
	...
```
*Com este array podemos fazer varias coisas, por exemplo, adicionar clientes, eliminar clientes, listas informações dos clientes, etc etc*

__Mostrar a informação completa dos clientes__
```c
void escreve_todos(cliente tab[], int total){
	int i;
	for(i = 0; i < n; i++){
		escreve_info(tab[i]);
		}
	}
```
__Adicionar um cliente__
```c
void adiciona_cliente(cliente tab[], int *total){
// *total é um ponteiro para o numero de clientes
// usamos ponteiro aqui porque queremos manipular o array
	if(*total >=MAX){
		printf("Tabela completa\n");
	}
	else{
		tab[*total] = obtem_info();
		(*total)++; // inserimos 1 cliente logo o tamanho aumenta
	}
}
```
__Eliminar um cliente(procurando pelo nº de conta)__
*A estratégia é, obter o nº de conta, procurar esse cliente no array, se o cliente existir, temos entao de retirar da posiçao em que se encontra e atualizar o nº de clientes*
```c
void elimina_cliente(cliente tab[], int *n){
	char st[15];
	int i;
	
	printf("Nº de conta do cliente a eliminar: ");scanf(“ %14s” st);
	
	for(i=0; i<*n && strcmp(st, tab[i].nconta)!=0; i++);

	if(i==*n){
		printf("Cliente não existe\n");
	}
	else{
		tab[i] = tab[*n-1];//colocamos o ultimo elemento na posiçao do cliente a eliminar
		(*n)--;
	}
}
```
*Podemos tambem eliminar o cliente de forma ordenada*
```c
void elimina_clienteOrd(cliente tab[], int *n){
    char st[100];
    int i;
    
    printf("Nº de conta do cliente a elminar: ");scanf("%s",st);
    for(i=0; i < *n && strcmp(st,tab[i].nconta) != 0; i++);
    
    if(i == *n){
        printf("Cliente nao existe\n");
    }
    else{
        for(int j = i; j < *n-1; j++){
            tab[j] = tab[j+1];
        }
        (*n)--;
    }
    
}
```

# Gestão dinâmica de memória
*A alocação dinâmica de memória é um mecanismo utilizado para possibilitar que uma quantidade de memória seja reservada durante o tempo de execução de uma aplicação. A região de memória utilizada para alocação dinâmica é conhecida como heap.*
*Usando a biblioteca* __stdlib.h__  *podemos usar funções para fazer esta gestão.*
__malloc__ / __calloc__ / __realloc__ / __free__

#### malloc(memory allocation)
*Aloca espaço para um bloco de bytes consecutivos na RAM*
*É um ponteiro para o espaço reservado e devolve NULL caso dê erro. O size_t é o numero de bytes a reservar.*
```c
void *malloc(size_t tam);
```
*Reservar espaço para armazenar __tam__ inteiros, sendo o valor do __tam__ indicado pelo utilizador.*
```c
int main(){
	int tam, *tab = NULL;
	
	printf("Numero de elementos: ");
	scanf("%d", &tam);
	tab = malloc(sizeof(int) * tam);
	if(tab == NULL){
		printf("Erro na alocação");
	}
	return 0;
}
```
#### free
*As variáveis alocadas estaticamente dentro de uma função, também conhecidas como variáveis locais, desaparecem assim que a execução da função termina. Já as variáveis alocadas dinamicamente continuam a existir mesmo depois que a execução da função termina. Se for necessário limpar a memória ocupada por essas variáveis, é preciso recorrer à função free.*
```c
void free(void *p);
```
