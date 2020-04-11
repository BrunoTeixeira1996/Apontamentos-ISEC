# TAC
## Conversões

__Decimal para binario puro__

*Para fazermos esta conversão, basta dividirmos o numero decimal por 2(binario) e ir guardando o resto. Caso dê uma divisão inteira, o resto é 0, caso contrario o resto é 1*

__Exemplo__ : 153 para binario
153 : 2 = 76,5 -> 1
76 : 2 = 38 -> 0
38 : 2 = 19 -> 0
19 : 2 = 9,5 -> 1
9 : 2 = 4,5 -> 1
4 : 2 = 2 -> 0
2 : 2 = 1 -> 0
1 : 2 = 0,5 -> 1

*Agora começamos de baixo para cima, pegando no resto.*

*Logo , 153 para binario é __10011001__*

*Caso o numero decimal contenha uma virgula, fazemos exatamente o mesmo, no entanto a partir da virgula, fazemos multiplicações sucessivas por 2*

__Exemplo__ : 48,45 para binario
48 : 2 = 24 -> 0
24 : 2 = 12 -> 0
12 : 2 = 6 -> 0
6 : 2 = 3 -> 0
3 : 2 = 1,5 -> 1
1 : 2 = 0,5 -> 1
0,45 x 2 = 0,9 -> 0
0,9 x 2 = 1,8 -> 1
0,8 x 2 = 1,6 -> 1

*Nas divisoes usamos o numero debaixo para cima, na multiplicação usamos de cima para baixo.*

*Logo, 48.45 para binário é  __110000,011__.*

__Binario para Octal/Hexadecimal__

*Caso seja preciso passar de decimal para octal, ou hexadecimal, o melhor será sempre passar para binario e depois de binario para octal ou hexadecimal*

__Usamos uma tabela para ser mais facil representar__

__Por exemplo octal__

![Untitled Diagram](https://user-images.githubusercontent.com/12052283/79046541-7bb17a00-7c09-11ea-8beb-cf03dbb2ec9f.png)


*Se tivermos o numero __10010101__ para passarmos para octal, basta ir da direita para a esquerda e agrupar de 3 em 3 e olhar para a tabela acima.*
*Assim __10010101__ para octal é 225.*

__Por exempo para hexadecimal__

![Untitled Diagram (1)](https://user-images.githubusercontent.com/12052283/79046839-13639800-7c0b-11ea-8bda-4a2db16545b7.png)


*Fazemos exatamente a mesma coisa, no entanto aqui agrupamos da direita para a esquerda mas de 4 em 4.*

*Assim __10010101__ para hexadecimal é 95.*

*Depois disto conseguimos converter para qualquer base.
O truque é sempre o mesmo, passar para a base 10 e depois da base 10 passar para a base pretendida.*

__Por exemplo__
__101 base 3 para base 4__

*Passamos 101 para base 10*

![CodeCogsEqn (1)](https://user-images.githubusercontent.com/12052283/79047180-06e03f00-7c0d-11ea-8c26-2cfa6047a196.gif)

*Agora que ja temos o 10 em base decimal, passamos para base 4*

10 : 4 = 2.5

Pegamos em 0.5 e multiplicamos por 4 para saber o resto.

0.5 x 4 = 2
2 : 4 = 0.5
0.5 x 4 = 2

*Logo 101 em base 3 é 22 em base 4.*

## Códigos bipolares

*Aqui ja vamos representar binarios com sinal, uma vez que em cima o binario é sempre positivo, aqui pode ser positivo ou negativo.*

__Sinal e valor absoluto(SVA)__

![CodeCogsEqn (2)](https://user-images.githubusercontent.com/12052283/79047430-5a9f5800-7c0e-11ea-9915-7af3b0d0a34e.gif)

*Sendo __n__ o __nr de bits a serem usados__*.

*Se o nr for positivo usamos 0 , se for negativo usamos 1.*

__Por exemplo__

*+6 em base 10 , qual será o nr em SVA?*
*Dizendo que __n__ = 5 (é dado nos exercicios)*
*Primeiro colocamos o +6 em binário puro -> +(110)*
*Depois acrescentamos os bits, para ter o mesmo numero que o enunciado pede, caso seja necessário no lado esquerdo -> +(00110)*
*Acrescentamos em cima o 0 porque o numero é positivo.*
*Fica entao 00110 em SVA.*

__Agora negativo__

*-6 em base 10, para SVA*
*-(110) = -(00110) = 10110 em SVA*

*Se nos derem este nr em SVA e pedirem a sua versão em decimal fazemos como mostra na figura em baixo.*

![Untitled Diagram (2)](https://user-images.githubusercontent.com/12052283/79047703-3a709880-7c10-11ea-82a9-118da21f7179.png)

*Logo o numero será -2 em base decimal.*

__Complementos de 1(C1)__

*A formula para saber se um certo nr cabe em C1 com o nr de bits dado é exatamente igual ao SVA.*

*Em C1 quando estamos a trabalhar com numeros positivos, fica exatamente igual ao binário puro*

*+6 em base decimal para C1 é 00110 __Atenção , o nr de bits é exatamente igual ao de cima só como exemplo, ou seja, 5 bits__.*

*-6 em base decimal para C1 já é diferente.*

*Alteramos entao o -6 para binário puro, acrescentamos os devidos bits se necessário e invertemos todos os bits.*

*-6 -> -(110) -> -(00110) -> 11001 em C1*


*Se nos derem um determinado nr em C1 e pedirem para convertermos para decimal, fazemos o seguinte*

![Untitled Diagram (3)](https://user-images.githubusercontent.com/12052283/79048107-a05e1f80-7c12-11ea-9cb7-c8b96a15c865.png)

__Complementos de 2 (C2)__

![CodeCogsEqn (3)](https://user-images.githubusercontent.com/12052283/79048137-d7cccc00-7c12-11ea-9d10-2c2d6636e4cc.gif)

*Aqui só subtraimos na parte positiva, logo ganhamos um valor.*

*Se o nr for positivo, é exatamente igual ao C1.*

*Nos numeros negativos, percorremos da direita para a esquerda até encontrarmos o 1. Quando o encontrarmos, a partir desse 1 , invertemos os numeros todos.*

![Untitled Diagram (4)](https://user-images.githubusercontent.com/12052283/79048328-4bbba400-7c14-11ea-9b1f-3afe7d44bbdd.png)

__Binário deslocado (BD)__

![CodeCogsEqn (5)](https://user-images.githubusercontent.com/12052283/79048360-8291ba00-7c14-11ea-8cc2-670acc372819.gif)

*Sendo nr de bits = 5*

__Atenção que aqui o nr positivo é 1 e o negativo é 0__

*__+6 em decimal para BD__*

![CodeCogsEqn (6)](https://user-images.githubusercontent.com/12052283/79048432-e61be780-7c14-11ea-85df-7d5e544d34ca.gif)

*+6 = 6 + 16 = 22 -> 22  = 10110 em BD*

*-6 = -6 +16 = 10 -> 01010 em BD*

*Se nos derem o seguinte numero em BD*

![Untitled Diagram (5)](https://user-images.githubusercontent.com/12052283/79048649-6c84f900-7c16-11ea-8860-1f2ebfd1d558.png)

__Exercicios comuns__

![image](https://user-images.githubusercontent.com/12052283/79048717-ec12c800-7c16-11ea-9780-0570ac884e13.png)

__Resolvendo__

![Untitled Diagram (6)](https://user-images.githubusercontent.com/12052283/79049018-ecac5e00-7c18-11ea-9a05-278f8d3a105b.png)

__Estender numeros com sinal__

*Quando se fala em estender numeros com sinal, temos de ver os bits que o enunciado nos dá primeiro.*

*Depois disso, pegamos no numero , e vemos se esse numero em binario começa com 0 ou 1. Se começar com 1 temos de acrescentar F's se começar com 0, acrescentamos 0's.*

__Contrair numeros com sinal__

*Para contrair temos de ver quantos bits nos pedem. Vemos o sinal do numero dado e vemos de dá para alterar.*

__Por exemplo__

*__Contrair o numero FFFF67 para 8 bits__*

*Não é possivel porque 6 é positivo(começa com 0) e F é negativo(começa com 1), logo o se fossemos contrair o numero ele mudava de sinal.*

*__Contrair o numero FFFF85 para 8 bits__*

*É possivel, uma vez que F começa com 1 e 8 tambem começa com 1 em binario, logo iria ficar só 85.*

## Aritmética
*Em baixo temos um exemplo de uma soma e um exemplo de uma subtração em binário.*

![Untitled Diagram (7)](https://user-images.githubusercontent.com/12052283/79049624-993c0f00-7c1c-11ea-9b23-7e3cb765674e.png)

*Em baixo temos um exemplo da soma e da subtração em hexadecimal.*

![Untitled Diagram (8)](https://user-images.githubusercontent.com/12052283/79049959-c5588f80-7c1e-11ea-8642-b51f9cd60544.png)

### Aritmetica em C2

![Untitled Diagram (9)](https://user-images.githubusercontent.com/12052283/79050294-f5a12d80-7c20-11ea-9268-e57d86f2b0f8.png)

## IEEE 754

*O IEEE 754 apresenta a virgula flutuante, importante depois para a programação em Assembly.*

__float__ -> 32 bits -> Precisão simples.

__double__ -> 64 bits -> Precisão dupla.

![CodeCogsEqn (9)](https://user-images.githubusercontent.com/12052283/79050428-d8209380-7c21-11ea-8620-f0a52c658049.gif)

__S__ -> sinal -> + (0) , - (1)

__M__ -> Mantissa

__E__ -> Exponente


## Exercicio

### Passar o numero 9 para IEEE754

![Untitled Diagram (10)](https://user-images.githubusercontent.com/12052283/79050787-40707480-7c24-11ea-86d6-becc14891144.png)

### Passar o numero -153,625 para IEEE754

![Untitled Diagram (11)](https://user-images.githubusercontent.com/12052283/79051232-fccb3a00-7c26-11ea-9ecd-58b30c8d8bf9.png)

### Agora ao contrário

*Se nos derem um numero em formato IEEE754 de precisão simples e quiserem que esse numero seja convertido para decimal? Como é que fazemos?*

### Por exemplo o numero C2E48000 de IEEE754 para decimal

![Untitled Diagram (12)](https://user-images.githubusercontent.com/12052283/79051643-1b323500-7c29-11ea-8b5a-deeca509c302.png)


### Mesmo exercicio mas com o numero 3F880000

![Untitled Diagram (13)](https://user-images.githubusercontent.com/12052283/79051892-a7912780-7c2a-11ea-890e-008104200579.png)

