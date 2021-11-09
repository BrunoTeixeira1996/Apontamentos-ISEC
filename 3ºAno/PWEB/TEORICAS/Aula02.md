# Aula 18/10/2021

## Namespaces

- O código dos programas C# estão organizados em *namespaces*
  - Organiza um conjunto de classes relacionadas entre si
  - As classes podem ter nomes iguais, desde que estejam em *namespaces* diferentes
  - Um *namespace* pode conter outros namespaces

## POO - Principios

- Abstração -> utilizada para a definição de entidades do mundo rial
- Encapsulamento -> tem como objetivo a ocultação de pormenores internos da classe
- Herança -> como um filho pode herdar coisas dos pais, uma classe pode herder atributos e métodos de outra
- Polimorfismo -> permite ao programador definir métodos genéricos em classes ou interfaces, que podem ser implementados de diversas formas nas respetivas subclasses

- Todo **objeto** possui:
  - **Estado**: conjunto de propriedades de um objeto
  - **Comportamento**: conjunto de ações possíveis sobre o objeto
  - **Unicidade**: todo o objeto é único

- **Classes**
  - Definem os tipos de objetos
  - Definem quais os dados e o código dos objetos
  
![image](https://user-images.githubusercontent.com/12052283/137706883-cfd7db90-a606-4896-b5b9-65bf6b8d1bc5.png)


### Criação de um objeto

- **Definição da classe**
- **Criação do objeto**

![image](https://user-images.githubusercontent.com/12052283/137707283-532f6a45-07b1-441f-913b-6e191f1b3cd8.png)

### Construtor

![image](https://user-images.githubusercontent.com/12052283/137708098-4baaf71c-9121-4b95-88dc-525cba65b38f.png)

## Gets e Sets

- Podemos meter **get** e **set** ou só 1 deles
- Tambem podemos ter código dentro do get e do set
- https://stackoverflow.com/a/5096967

![image](https://user-images.githubusercontent.com/12052283/137710868-779af74e-9456-4443-8f0b-0de76581de77.png)

## Parâmetros *ref* vs *out*

![image](https://user-images.githubusercontent.com/12052283/139414239-b66b78f9-cbb6-4636-9776-18c499335075.png)

## Membros virtuais

- É um membro na classe base que define uma implementação por omissão que pode ser alterada (overridden) pela classe derivada

## Classes Abstratas e Sealed

- A palavra chave *abstract* permite criar classes e membros de classes incompletas que têm de ser implementados na classe derivada

- A palavra chave *sealed* evita que a classe oumembros virtuais sejam herdadados

## Palavra chave *as* em Csharp

- *as* tenta converter um objeto para um tipo específico e retorna *null* se a conversão falhar

![image](https://user-images.githubusercontent.com/12052283/139419498-87e2b3ff-9e5c-4d45-874f-a67e09a91780.png)

## Palavra chave *is* em Csharp

- *is* permite de forma rápida determinar se um determinado objecto é compatível com um tipo e devolve *false* caso não sejam


![image](https://user-images.githubusercontent.com/12052283/139419620-ca35efba-f52b-4ace-a737-1762cf46d133.png)
