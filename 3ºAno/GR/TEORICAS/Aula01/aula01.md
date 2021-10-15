# Aula 11/10/2021

## Definição de Gestão de Redes

- Refere-se à atividade associada à manutenção de uma rede em funcionamento, juntamente com toda a tecnologia necessária para suportar essas atividades.

- Ou seja, gestão de redes refere-se às **atividades**, **métodos**, **procedimentos** e **ferramentas** que dizem respeito à **operação**, **administração**, **manutenção** e **provisionamento** de sistemas em rede.

### Operação da rede

- Refere-se com a manutenção de rede em funcionamento e sem falhas.

- Inclui monitorização da mesma de forma a prever potenciais problemas, idealmente antes de estes afetarem a rede

### Administração da rede

- Refere-se as operações de manter debaixo de olho os recursos da rede e de que forma estes são distribuidos

### Manutenção da rede

- Está relacionada com operações de reparação e upgrades para o bom funcionamento da rede

### Provisionamento da rede

- Está relacionado com a configuração de recursos na rede de forma a fornecer um determinado serviço

## TCO (Total Cost Ownership)

- **Custo do equipamento**

- **Custo operacional**

![image](https://user-images.githubusercontent.com/12052283/137474148-f8435fb3-7bca-4d67-92ce-41b4e7889800.png)

## Caracteristicas das Aplicações de Gestão

### Aplicações de Provisionamento

- Estas estão "preocupadas" com o ajuste de configurações dos equipamentos de rede

- Nomeadamente ligar um serviço, enviando pedidos para um elemento de rede e processando as respostas destes e enviando os parâmetros necessários para a correta configuração do equipamento

![image](https://user-images.githubusercontent.com/12052283/137474921-dad03dab-de37-4636-b95e-80eabb3ac92e.png)


### Sistemas de *interrupt-driven*

- Estes normalmente são sistemas de alarme, sendo que é um aspeto importante da gestão de redes manter um seguimento da saude da mesma

- Envolve a monitorização da rede para capturar alarmes enviados pelos elementos

![image](https://user-images.githubusercontent.com/12052283/137474964-58991a41-c8de-4ca2-bde3-8f5b7e9a10e9.png)

### Aplicações *number-crunching*

- São aplicações que pegam nos dados enviados pelos equipamentos (muitas vezes estes dados vêm em formato de *log* ou seja muito dificeis de serem percebidos a olho humano), "mastigam" os mesmos tornado-os mais percetiveis a olho humano , criando por exemplo gráficos, tabelas, etc

## O problema da escala

- Existe um problema, chamada o problema da escala em que este diz o seguinte
	- **A capacidade da rede evolui mais rápido que a capacidade de processamento sendo isto muito mau para a gestão de redes**

![image](https://user-images.githubusercontent.com/12052283/137475515-eb9a06d1-bd28-4a33-b1ab-59ef92a880d6.png)

## Resolvendo o problema da escala

### Operações concorrentes

- Neste caso em vez de esperarmos pela resposta depois de termos enviado um pedido, enviamos pedidos em simultâneo

![image](https://user-images.githubusercontent.com/12052283/137475720-1078c47a-42a3-48f1-be82-7215385fa6d4.png)

### Propagação de eventos

- Estes eventos devem ser propagados de forma eficiente para o sistema

- Ou seja, quando um evento de rede é recebido a aplicação de gestão deve de forma rápida e eficiente identificar onde é que o evento pertence (qual é o dispositivo, qual o seu hardware, quais as suas implicações, etc)

### Scoping

- O scoping é a forma como acedemos a grandes blocos de informação de forma eficiente

- Por exemplo, se tivermos numa festa e tivermos a limpar os pratos, mais vale trazer um conjunto de pratos do que levar um de cada v

![image](https://user-images.githubusercontent.com/12052283/137475974-8c0c71ed-7adf-4cd2-846b-3acaa7795327.png)

## Referências

- *Network Management Fundamentals* , Alexander Clemm, Cisco Press, 2007, capítulo 1, pp.5-45