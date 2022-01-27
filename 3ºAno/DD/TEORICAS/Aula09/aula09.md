# Aula 07/01/2022

![image](https://user-images.githubusercontent.com/12052283/148589133-9d126b51-de77-4b5e-8b58-c57af6b1763b.png)

- O DiffServ só funciona se o tráfego não for demais, ou seja, se limitarmos o tráfego que entra na nossa rede e isso é feito na camada de acesso

- Nos podemos trabalhar no trafego que entra para limitar a quantidade de trafego que nos entra numa determinada interface

- Mas aqui na cadeira temos de nos preocupar com o tráfego que sai e não o que entra no entanto é obvio que se deixamos muito tráfego entrar o caos instala-se

## Politicas de admissão

- Quando o tráfego em excesso atinge o limite definido para o *burst* o tráfego é descartado ou remarcado

### Metáfora Token Bucket

- Ha um contador na porta de entrada e esse contador esta sempre a entrar
  - Cada vez que entra trafego o contador incrementa
  - Cada vez que sai trafego o contador decrementa
  - Se ele passar o limite que nós definimos, o que entra é descartado
  - Ou seja, nós definimos o limite e definimos o nivel de escoamento

![image](https://user-images.githubusercontent.com/12052283/148591640-2c9eedcb-6d51-4266-9865-d3c395aa05a4.png)

## Filas de espera de ingresso

![image](https://user-images.githubusercontent.com/12052283/148592491-5f84c280-61b3-4c87-846f-99bb5b449c16.png)

- A fila prioritária recebe uma fração **garantida** da largura de banda da *stack ring*, facto que assegura um atraso limitado na presença de congestão
- O resto da largura de banda é repartida por ambas as filas de espera na proporção configurada

- **A politica usada para servir as filas de espera de ingresso é chamada de Shaped Round Robin**
  - Sobre as filas de ingresso o escalonamento opera apenas em modo *shared*

## Filas de espera de egresso (que sai)

- Q (Queue)
- T (Threshold)
- P (Priority)

- 4Q1T (4 Queue, 1 Threshold)
- 1P3Q1T (1 Priority, 3 Queue, 1 Threshold)


![image](https://user-images.githubusercontent.com/12052283/148592880-440ca65f-0b44-4a27-9272-eb2ab9f9c209.png)

![image](https://user-images.githubusercontent.com/12052283/148593160-7a35ed0c-b2ba-4846-b078-f677cbf140cd.png)

- Para eu ter mais formas diferentes de tratar o tráfego, posso criar limiares(threshold) para que tipos de tráfegos diferentes entrem para a mesma fila

![image](https://user-images.githubusercontent.com/12052283/148593579-6f7a33ee-aab4-4680-a6ce-349e284acc20.png)

## Imagem importante do QoS (pag 224)

- Vamos trabalhar no modelo 1P3Q3T
  - 1 fila prioritaria (é sempre a 1)

![image](https://user-images.githubusercontent.com/12052283/148594133-8e72c7a0-586e-4aff-9df0-a7e6033ca69c.png)

- Podemos dizer que a fila 1 é prioritaria e aqui estamos a trabalhar no **modelo 1P3Q3T**
  - Se dissermos isto, este tráfego passa sempre à frente de todos

- Se dissermos que estamos a trabalhar sem filas prioritária estamos a usar o **modelo 4Q3T**

- No shaped
  - Podemos configurar

- No share
  - Podemos configurar
  
### Gestão de buffers de egresso

- O switch reserva um mínimo de buffers para cada fila para evitar que uma fila ou interface prive as restantes de espaço
  
### Como é que funciona?

- **As filas de egresso podem ser atendidas em modo shared ou em modo shapped**

![image](https://user-images.githubusercontent.com/12052283/148594697-0f6d3114-5371-4b09-ada4-ece764dd4f1a.png)

![image](https://user-images.githubusercontent.com/12052283/148596096-954fc558-5509-4866-b134-a4e8166b1c8b.png)

## Em suma

- O tráfego é marcado à entrada do switch
- Em função do possível *policyng* o excedente é então descartado ou remarcado
- Em função das condições de congestão da *switch fabric* pode ou não passar pelas filas de ingresso da interface de entrada
- Uma réplica é então comutada para determinada interface de saída em função do valor e tipo de endereço
- Em função da classificação do quadro é escolhida a fila de egresso
- Em função da classificação do quadro é escolhido um dos três threshold limits e o quadro entra na fila ou é linearmente descartado
- Em função da parametrização das quatro filas o quadro é enviado para o meio fisico em determinado instante
