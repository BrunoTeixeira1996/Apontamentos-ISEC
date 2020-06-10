# Memória Virtual (Aula 18/03/2020)

Envolve obrigatoriamente a existência de um disco, HDD por exemplo

O que está na memória virtual, tem de estar presente em algum lado na memória fisica tambem.

Normalmente a memória virtual é maior que a física então, em certos momentos, a virtual pode estar a receber algo que a física não esteja. __(desenho 1)__

__Solução encontrada__

    Uma das regras para este problema, diz que sai da memória física o programa
    que já não é utilizado há mais tempo e vai para o HDD (ganhando um espaço
    para receber a nova instrução que está à espera). 
    (desenho 2)

A memória virtual tambem pode apontar diretamente para o HDD, por intermédio do __memory map__ . __(desenho 3)__

![image](https://user-images.githubusercontent.com/12052283/84324804-d8c59f80-ab68-11ea-9024-0146a96d1d82.png)

__Nota__

    O Disco é 1000x mais lento que a RAM
    O Endereço virtual têm mais bits que o endereço real

## Microprocessador 80286


Traz o __modo real__ e o __modo protegido__

__Modo Protegido__

    Programas estão separados e protegidos uns dos outros por barreiras para que
    não colidam entre si.
    O 8086 não tinha este modo.


# Microprocessador 80386 DX (Aula 19/03/2020)

Apresenta uma pre-tech cache memory : com a tecnologia __SRAM__ armazena os mesmos programas que a __DRAM__, mas 100x mais rápido, então o processador consegue aceder a eles mais facilmente sem ter de ir à __DRAM__.

Assim a __SRAM__ trabalha em conjunto com a __DRAM__ para rapidamente fornecer os dados ao processador.

![image](https://user-images.githubusercontent.com/12052283/84325386-2abaf500-ab6a-11ea-9b96-76f7247a41c2.png)


# <span style="background-color: #FFFF00; color: #000"> Pergunta de exame</span>

__Para que é necessária a cache?__

    Como explicado anteriormente, a cache tem o objetivo de melhorar a velocidade
    de execução do processador e consequentemente da máquina.

    A memória principal é mais lenta que a cache, portante ao existirem alguns
    programas na cache, conseguimos ir lá buscá-los e processá-los muito mais
    rápidamente tendo melhor performance de execução de programas.


# <span style="background-color: red; color: #000"> Errado</span>

    Não responder que serve para aumentar o armazenamento. Aliás, a cache
    até tem pouco espaço de armazenamento.

## Principio da proximidade

__Como aceder à memória e a que programas?__

    Principio temporal: Ir buscar o que foi acedido há menos tempos.

    Principio espacial : Ir buscar o que está mais proximo em termos de endereço.

## Mapeamento direto

    Cada linha da RAM é colocada na linha da cache que tiver a mesma terminação


![image](https://user-images.githubusercontent.com/12052283/84326125-cac54e00-ab6b-11ea-8f4a-347de9cd1479.png)


Para a resolução dos problemas anteriores, a cache ainda é formada pela __Tag__ e __Valid__, que ajudam na construção do endereço de cada programa.

* __TAG__
    * Os restantes bits do endereço são lá colocados.

* __Valid__
    * CPU consegue saber se o programa que está na cache é válido com um bit extra
    que indica se os dados dessa linha são válidos.


![image](https://user-images.githubusercontent.com/12052283/84326573-c3eb0b00-ab6c-11ea-9e50-a46273a79844.png)


# <span style="background-color: #FFFF00; color: #000"> Exercicio</span>

* __Uma máquina com RAM de 32 bits, uma cache de 64kbytes e com os blocos
    de 1byte cada__

    * Quantos bits são necessários para a TAG?
    * Capacidade total da cache?


![image](https://user-images.githubusercontent.com/12052283/84326693-16c4c280-ab6d-11ea-89e2-812668320829.png)

![image](https://user-images.githubusercontent.com/12052283/84326769-4247ad00-ab6d-11ea-8c43-ce9272602be4.png)


# Tecnologia Superescalar (Aula 01/04/2020)

Inicialmente o processador tratava de um programa de cada vez e outros tinham de ficar à espera - elevado tempo de execução.

## <span style="background-color: green; color: #fff"> Solução (pipeline)</span>

    Fazer uma instrução de um programa e quando esta acabar, fazer a mesma
    instrução do programa seguinte e ao mesmo tempo o primeiro programa continua
    a avançar - espécie de produção em série.

    Para isto foi necessário mudar a unidade de controlo para começar a gerir
    vários programas ao mesmo tempo.


## Tipos de Pipeline

__Pipeline Simples__

    Processador realiza até 4 instruções diferentes de programas diferentes ao
    mesmo tempo.

__Super-Pipeline__

    Processador realiza várias instruções iguais de programas diferentes ao mesmo
    tempo.

    Tem um desfasamento no inicio do arranque de cada operação.

__Super-Escalaridade__

    Parecido ao anterior mas com mais capacidade de processamento.

Nas super, microprocessador é quem determina quantas e quais instruções se fazem ao mesmo tempo.


![image](https://user-images.githubusercontent.com/12052283/84327235-5cce5600-ab6e-11ea-9c42-117c439f6a16.png)


## Limitações das super

* As intruções podem ocorrer sem outras anteriores terem sido finalizadas
* Essas instruções podem precisar de dados das anteriores, gerando aí um problema, pois precisam de esperar por elas, __travando todo o processo.__


## <span style="background-color: green; color: #fff"> Solução </span>

    Colocar essas instruções que necessitam de outras para último e assim as que
    estavam a ficar atrasadas podem ser processadas.

    O próprio processador é quem gere isto.


## <span style="background-color: red; color: #fff">Com tudo, isto pode gerar outro problema</span>

    Visto que iremos fazer saltar uma instrução para o fim e estamos a dar
    liberdade a outras, essas outras podiam precisar da que saltou ou não
    ser realmente necessárias de serem realizadas visto que a que saltou
    podia mostrar que já não era preciso realizar mais.


# Arquitetura híbrida (Aula 02/04/2020)

__CISC (Complex Instruction Set Computer) :__

    Consegue incorporar vários softwares(principalmente com a ideia dos mais
    antigos) no mesmo processador. Seria desnecessário utilizadores comprarem novo software.

    Contudo, os processos ficavam lentos porque a linguagem era muito mais
    pesada e com milhares de instruções.


__RISC (Complex Instruction Set Computer) :__

    Processador extremamente simples, operações feitas mais no processador,
    não snedo necessário ir tanto à memória.

    Portanto, grande rapidez na execução de tarefas.


O RISC é mais eficiente que o CISC - Pipeline também mais adaptado ao RISC

Estas tecnologias colidiam um pouco com o __Pipeline__,pois tinham muitas
instruções diversificadas, levando a que uma instrução grande atrasasse
todo o processo do pipeline.

## Junção das duas

    Como a Intel sempre se interessou em ter softwares antigos disponiveis, trouxe
    a arquitetura híbrida que traz um núcleo RISC e um descodificador CISC


# Microprocessador (Aula 07/06/2020)

__Microprocessador 80386__

    Traz o modo virtual, máquinas virtuais do 8086

__Microprocessador 80386 SX__

    Processador lowcost. Bus de dados de apenas 16bits.

__Microprocessador 80386 SL__

    Versão 80386 SX mas para portáteis.

__Microprocessador 80486__

* 80486 DX :

    * Parecido ao 8038X DX, mas com mais cache interna e tem pela primeira vez
    um __co-processador matemático.__

    * __Co-Processador (em hardware)__ recebe operandos e calcula-os de forma
    muito mais rápida do que fosse feito em software.

    * Traz a ventilação.

* 80486 SX: lowcost (sem o processador matemático)

* 80486 SL: portáteis, de 5v para 3.3v de tensão.
