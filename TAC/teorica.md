# Memória Virtual (Aula 18/03/2020)

Envolve obrigatoriamente a existência de um disco, HDD por exemplo

O que está na memória virtual, tem de estar presente em algum lado na memória fisica tambem.

Normalmente a memória virtual é maior que a física então, em certos momentos, a virtual pode estar a receber algo que a física não esteja. __(desenho 1)__

__Solução encontrada__

    Uma das regras para este problema, diz que sai da memória física o programa
    que já não é utilizado há mais tempo e vai para o HDD (ganhando um espaço
    para receber a nova instrução que está à espera). 
    (desenho 2)
    

__Nota__

    O conceito swap existe quando estamos a enviar as partes dos programas que estão a ser utilizadas para a memória e outras partes para o HDD


A memória virtual tambem pode apontar diretamente para o HDD, por intermédio do __memory map__ . __(desenho 3)__

![image](https://user-images.githubusercontent.com/12052283/84324804-d8c59f80-ab68-11ea-9024-0146a96d1d82.png)

__Nota__

    O Disco é 1000x mais lento que a RAM
    O Endereço virtual têm mais bits que o endereço real
    Endereços virtuais(lógicos) são gerados pela CPU
    Endereços fisicos são visiveis pela unidade de memória

__MMU(Memory Management Unit)__

    Periférico de hardware, tem a responsabilidade de traduzir endereços lógicos em endereços físicos.


## Microprocessador 80286


Traz o __modo real__ e o __modo protegido__

__Modo Protegido__

    Programas estão separados e protegidos uns dos outros por barreiras para que
    não colidam entre si.
    O 8086 não tinha este modo.


# Microprocessador 80386 DX (Aula 19/03/2020)

Apresenta uma pre-tech cache memory : com a tecnologia __SRAM__ armazena os mesmos programas que a __DRAM__, mas 100x mais rápido, então o processador consegue aceder a eles mais facilmente sem ter de ir à __DRAM__.

Assim a __SRAM__ trabalha em conjunto com a __DRAM__ para rapidamente fornecer os dados ao processador porque guardamos na cache coisas que poderemos precisar em breve.

![image](https://user-images.githubusercontent.com/12052283/84325386-2abaf500-ab6a-11ea-9b96-76f7247a41c2.png)

## Inclusão

    A cache irá conter instruções, no entanto essas instruções são uma réplica de um pedaço da memória central.

    A própria memoria central é uma réplica da memória virtual.


# <span style="background-color: #FFFF00; color: #000"> Pergunta de exame</span>

__Para que é necessária a cache?__

    Como explicado anteriormente, a cache tem o objetivo de melhorar a velocidade
    de execução do processador e consequentemente da máquina.

    A memória principal é mais lenta que a cache, portanto ao existirem alguns
    programas na cache, conseguimos ir lá buscá-los e processá-los muito mais
    rápidamente tendo melhor performance de execução de programas.


# <span style="background-color: red; color: #000"> Errado</span>

    Não responder que serve para aumentar o armazenamento. Aliás, a cache
    até tem pouco espaço de armazenamento.

## Principio da proximidade

    Exibido pela maior parte dos programas no acesso à memória, que permite acelerar os acessos à mesma com a hierarquia

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

* __Considere uma máquina com um espaço de endereçamento (RAM) de 32 bits, uma cache de 64kbytes e com os blocos
    de 1byte cada__

    * Quantos bits são necessários para a TAG?
    * Capacidade total da cache?


![image](https://user-images.githubusercontent.com/12052283/84326693-16c4c280-ab6d-11ea-89e2-812668320829.png)

![image](https://user-images.githubusercontent.com/12052283/85707727-fd765700-b6d2-11ea-94b1-2686e06bfb49.png)


## Caso nos pedissem para calcular o espaço de endereçamento da RAM 

![image](https://user-images.githubusercontent.com/12052283/85708073-547c2c00-b6d3-11ea-8ed6-b313c6598b4e.png)


# Tecnologia Superescalar (Aula 01/04/2020)

Inicialmente o processador tratava de um programa de cada vez e outros tinham de ficar à espera - elevado tempo de execução.

## <span style="background-color: green; color: #fff"> Solução (pipeline)</span>

    Fazer uma instrução de um programa e quando essa instrução acabar, fazer a
    mesma instrução do programa seguinte e ao mesmo tempo o primeiro programa
    continua para a instrução seguinte, repetindo-se este processo.

    Espécie de produção em série.

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

    Antes de acabar o fetch(ir buscar à memória) da primeira instrução, começa o
     fetch da segunda instrução e assim sucessivamente.

__Super-Escalaridade__

    Aqui temos 2 ou mais instruções a começar ao mesmo tempo.
    
    Isto devido à elevada capacidade do CPU.

    Parecido ao anterior mas com mais capacidade de processamento.

Nas super, o microprocessador é quem determina quantas e quais instruções se fazem ao mesmo tempo.


![image](https://user-images.githubusercontent.com/12052283/84327235-5cce5600-ab6e-11ea-9c42-117c439f6a16.png)


## Limitações das super

* As intruções podem ocorrer sem outras anteriores terem sido finalizadas
* Essas instruções podem precisar de dados das anteriores, gerando aí um problema, pois precisam de esperar por elas, __travando todo o processo.__


## <span style="background-color: green; color: #fff"> Solução </span>

    Colocar essas instruções, que necessitam de outras, para último e assim as que
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
    antigos) no mesmo processador.
    Seria desnecessário os utilizadores comprarem um novo software.

    Contudo, os processos ficavam lentos porque a linguagem era muito mais
    pesada e com milhares de instruções.

    Instruções efetuadas sobre a memória, retirando pouco partido da sua
    localização espacial.


__RISC (Complex Instruction Set Computer) :__

    Processador extremamente simples, operações feitas mais no processador,
    não sendo necessário ir tanto à memória.

    Portanto, grande rapidez na execução de tarefas.

    Instruções de formato fixo, cujo o código tem sempre o mesmo tamanho, o que
    lhe permite a descodificação da instrução e trabalhar em piplining.

__NOTA__
    
    Os processadores INTEL ainda usam o CISC

    No entanto o RISC é usado em telemoveis, consolas de jogos ...

O RISC é mais eficiente que o CISC - Pipeline também mais adaptado ao RISC

Estas tecnologias colidiam um pouco com o __Pipeline__,pois tinham muitas
instruções diversificadas, levando a que uma instrução grande atrasasse
todo o processo do pipeline.

## Junção das duas

    Como a Intel sempre se interessou em ter softwares antigos disponiveis, trouxe
    a arquitetura híbrida que traz um núcleo RISC e um descodificador CISC


# Microprocessador (Aula 07/04/2020)

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

# (Aula 15/04/2020)

__Diferença entre cache de nível 1 e de nível 2__

    A cache de nível 1 está sempre dentro do processador.
    A cache de nível 2 pode estar dentro do processador.

    A cache de nível 1 é mais rápida que a de nivel 2.

    Pode existir mais um nível de cache ainda.
    Quanto mais nos afastamos do CPU, a cache é mais lenta, no entanto contém
    mais capacidade de armazenamento.

    Basicamente o processador começa por procurar o programa na cache 1 e se o
    encontrar, obtém-no muito rapidamente.
    A partir do momento que parte para outras caches(ou até mesmo chegar até 
    RAM ou disco), a rapized diminui.

    Optam por fazer várias caches em vez de uma grande entro do CPU, porque iriam
    ocupar muito espaço lá dentro.


![image](https://user-images.githubusercontent.com/12052283/84779817-5f003c80-afd4-11ea-8922-8f4f62b55f42.png)


## Barramentos

__Arquitetura com diferentes níveis de velocidade__

![image](https://user-images.githubusercontent.com/12052283/84780014-9a9b0680-afd4-11ea-8d1b-b97aed965134.png)


* 1

    * Devido ao investimento na multimédia(mmx) que exige transferências rápidas
    de informação.

* 2

    * No início existia um bus que fazia a ligação entre o CPU e os vários
    elementos. Com a evolução dos diferentes dispositivos, e consequentemente
    com a discrepância de velocidades entre eles, foi necessário um dispositivo
    que ajudasse a dividir o bus de dados pelas respetivas velocidades. Entregava
    assim as velocidades corretas a cada elemento com a ajuda de outros barramentos.

* 3

    * Em conjunto com a northbridge, gere o bus de dados para os dispositivos
    mais lentos(os que vemos em baixo).