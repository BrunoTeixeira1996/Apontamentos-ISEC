# Aula 29/11/2021

## LINQ Joins

![image](https://user-images.githubusercontent.com/12052283/143854787-1e5030d2-07bb-4ebb-b08e-9467136e8596.png)

### Inner Join

![image](https://user-images.githubusercontent.com/12052283/144715245-b26486a0-ab62-484b-b3f0-92aeeaf3a10a.png)

### Group Join

- Query syntax

![image](https://user-images.githubusercontent.com/12052283/144715276-0799e64d-bb35-42b7-b4e0-4929ec9c0d4a.png)

- Extension method

![image](https://user-images.githubusercontent.com/12052283/144715289-f670b994-0c40-4d56-9d75-c2c1fd57756a.png)

### Cross Join

![image](https://user-images.githubusercontent.com/12052283/144715315-ab3dfded-df61-4ce4-8564-0b39fa633b69.png)


- Query syntax

![image](https://user-images.githubusercontent.com/12052283/144715330-d45474bf-f872-4c12-8b16-4345065a2796.png)


- Extension method

![image](https://user-images.githubusercontent.com/12052283/144715335-f55d3c59-45ca-4976-9404-1079b2987939.png)

## Any

 - Retorna um boleano
 - Existe algum aluno com media superior a 10???
 
## All

- Retorna um boleano
- Todos os alunos têm média positiva????

![image](https://user-images.githubusercontent.com/12052283/144715369-07ec0efb-e3d2-4fbe-a4c1-e4143876e04c.png)

## Skip

- Permite saltar um determinado numero de elementos e retorna os restantes

## Take

- Retorna um numero especifico de elementos

![image](https://user-images.githubusercontent.com/12052283/144715406-bd2e8d90-960d-4d14-8338-a8a67cd28e11.png)

## TakeWhile

- Retorna elementos que satisfaçam uma determinada condição. Quando a condição já for verdadeira, termina

## SkipWhile

- Permite fazer o skip de elementos em sequência baseados numa condição. Quando deixar de ser verdadeira, retorna os restantes elementos

## First / Last

- Retorna o primeiro/último elemento da sequência ou o primeiro/último elemento correspondente ao predicado especificado
- se não existirem elementos na sequência, é gerada uma excepção **Invalid Operation Exception**  com a mensagem "Sequence contains no elements"

## FirstOrDefault / LastOrDefault

- Retorna o primeiro/último elemento da sequência ou o primeiro/último elemento correspondente ao predicado especificado

## Single

- Se a sequência contém exactamente um elemento, ouexactamente um elemento que satisfaça a condição especificada no predicado, então esse elemento é devolvido

## SingleOrDefault

- Igual ao comportamento do Single(), no entanto se nãoexistirem elementos ou se não existirem elemetos que satisfaçam a condição do predicado, em vez de gerar excepção, é retornado o valor por omissão do tipo correspondente default(T)

## ElementAt

- Retorna um elemento da sequência baseado na posição index especificada

## ElementAtOrDefault

- Igual ao comportamento do Element(), no entanto se nãoexistir elemento no indice especificado, retorna o valor por omissão

## Agregação

### Count

![image](https://user-images.githubusercontent.com/12052283/144715616-143c2c87-5f02-459d-be85-8ec1ee5527c3.png)

### Sum

![image](https://user-images.githubusercontent.com/12052283/144715622-3e29a2f4-7dba-41a7-99ea-c9cd4505b079.png)

### Min / Max

![image](https://user-images.githubusercontent.com/12052283/144715636-95d70a0b-5e80-4071-9615-5dc471787e46.png)

### Average

![image](https://user-images.githubusercontent.com/12052283/144715642-a0cdba16-83de-4cd7-a158-c93b9ca1c1d0.png)

## Conjuntos (Union, Intersect, Concat, Except, Distinct)

![image](https://user-images.githubusercontent.com/12052283/144715664-ab751e97-5093-4fee-90cf-fb6f9ba7bee4.png)

## Exercicio -> Selcionar os alunos cujo nome começa por "F"

![image](https://user-images.githubusercontent.com/12052283/144715714-eaf6681e-c013-45b1-a330-d50e88ecd723.png)


## Exercicio -> Selcionar os alunos cujo o ultimo nome começa por "F"

![image](https://user-images.githubusercontent.com/12052283/144715718-abb6b1fd-424b-4ffe-a13c-c84f331b3df4.png)
