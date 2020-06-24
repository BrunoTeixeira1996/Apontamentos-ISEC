# Exercicios da parte Teórica

# Época normal (1-07-2014)

![image](https://user-images.githubusercontent.com/12052283/85331647-09d99480-b4c6-11ea-906c-f6b74aa99d51.png)

## Resposta

__As arquiteturas superescalares fazem um reordenamento de instruções na tentativa de limitar efeitos de dependências.__

__Usam a execução de instruções para conseguirerem ser eficientes, no entanto requerem alguma capacidade da CPU.__

__Para despachar multiplas instruções por ciclo é necessário
minimizar as perdas por desvios. Nas arquiteturas superes-
calares, as perdas por desvios causam sérias consequências
no desempenho: 25% a 75% das perdas são devido a erros
de desvios__

![image](https://user-images.githubusercontent.com/12052283/85332487-9042a600-b4c7-11ea-9053-25147bf1239d.png)

## Resposta

## a)

__Caracterizam-se por utilizarem a tecnologia laser(intensos feixes luminosos) para a gravação e leitura da informação.__

__A informação é armazenada através de perfurações. Uma posição perfurada equivale ao estado "1" e o contrário é "0".__

__O leitor de CD tem a tarefa de
encontrar e ler os dados armazenados
no CD. O drive é constituído por 3
componentes fundamentais:__

        O motor, para fazer rodar o disco.
        Um laser e um sistema de lentes.
        Um mecanismo de posicionamento


## b)

__As pistas de um CD não são concêntricas, mas sim em espiral.__

__Cada bloco tem 2352 bytes.__

__Destes, 2048 ou 2336 (dependendo do modo) são destinados a dados do utilizador, os restantes servem para posicionamento, detecção e correcção de erros e informação sobre velocidade.__

## c)

__O mecanismo de "tracking" tem por objetivo manter o laser de leitura sobre a pista de dados. Esta é uma ação fundamental dado que a pista em espiral está em continuo movimento e a cabeça da leitura tem que acompanhar esse movimento para nao perder o fluxo de dados de leitura.__

__Os dados circulam do interior da espiral para o seu exterior.__

__Esta disposição apresenta vantagens no que respeita à produção de meios contínuos.__



![image](https://user-images.githubusercontent.com/12052283/85333448-20351f80-b4c9-11ea-955b-b31b5c5c170c.png)


## Resposta

__O modo real reproduz o esquema de operações do 8086, herdou todas as suas limitações (inclusive a barreira de 1Mb de memória).__

__O modo protegido tira maior partido da memória disponível embora não seja compativel com os programas para o 8086, o modo protegido permitia o uso de todos os 16MB de memória real, além de 1GB de memória virtual(Proteção de memória ao nível do hardware).__


# Época normal (25-06-2019)


![image](https://user-images.githubusercontent.com/12052283/85333930-f8928700-b4c9-11ea-8b26-c89813bd50a4.png)

## Resposta

__A secção de aquisição e descodificação é onde são recebidas as instruções provindas da memória para serem descodificadas de modo a que a CPU possa determinar quais as operações deve realizar.__

__A unidade de controlo controla ou determina as operações a efectuar em cada instante, enviando sinais apropriados aos outros componentes.
Extrai da memória, uma a uma as sucessivas instruções do programa, anexa essas instruções e gera sinais de comando que são enviados aos diversos componentes e permitem executar cada instrução analizada.__

__A unidade de aritmética lógica é resposável pela execução de operações aritméticas e lógicas.__


![image](https://user-images.githubusercontent.com/12052283/85334395-b7e73d80-b4ca-11ea-9280-873b44b68b11.png)

## Resposta

__Para gravar dados, é necessário apagar já existentes. A regravação só pode ser feita um nº finito de vezes. Para escrever na célula é criado um campo elétrico de forma a obter eletrões livres entre a n-source e o n-drain.__

__A célula é composta por transístores com uma fina camada de óxido de sílicio, pode armazenar cargas negativas.__

__Isso cria uma espécie de armadilha de eletrões que permite manter os dados por longos periodos de tempo.__


# Época Recurso (18-07-2018)


![image](https://user-images.githubusercontent.com/12052283/85335068-e6b1e380-b4cb-11ea-873c-3a450a92ed35.png)

## Resposta

__A memória virtual é uma técnologia que permite a execução de processos em que parte se encontra na memória principal e a outra parte em disco.__

__Esta consiste em usar duas noções de endereço, o endereço virtual (no contexto do espaço de endereçamento do processo que pode exceder o tamanho físico da memória) e o endereço real(no contexto de execução, apenas uma parte do espaço de endereçamento do processo é carregada na memória, situação virtual irá corresponder a um determinado endereço físico).__

__Como principal vantagem da memória virtual saliente-se o permitir um
uso mais eficiente da memória física.__

__A paginação de memória (páginas de memória) é um método de organizar a memória e que se adequa bem à implementação da memória virtual.__

__O espaço de endereçamento de um processo pode não ser contíguo (é um conjunto de
páginas). para executar um programa com tamanho de n páginas, é necessário
procurar n molduras livres e carregá-lo para essas molduras.__

# Época Recurso (18-07-2014)

![image](https://user-images.githubusercontent.com/12052283/85336651-7ce70900-b4ce-11ea-9c36-e8f2ed96c5eb.png)

## Resposta

__A memória ROM(Read Only Memory) é usada para armazenar instruções e/ou dados permanentes. A
informação geralmente é colocada no chip de armazenamento
quando ele é fabricado e o conteúdo da ROM.__

__A memória PROM pode ser programável, permite a escrita de informação através de dispositivos apropriados(dados gravados não são apagados) e comporta-se como a ROM.__

__A memória EPROM é uma memória de leitura, pode ser programável através de equipamente adequado.Pode ser apagada através de raios ultravioleta.__

__A memória EEPROM é uma memória de leitura e pode ser programável.A memória pode ser apagada eletronicamente (emite-se uma descarga de energia por uma das portas do circuito que apaga a informação).Comporta-se como a PROM.__

__Fisicamente a EEPROM distingue-se da anterior pela ausencia da "janela" onde se pode emitir o tal feixe de luz."__


![image](https://user-images.githubusercontent.com/12052283/85336927-0c8cb780-b4cf-11ea-8249-9235dcce8481.png)

## Resposta

__O refrescamento "transparente" aproveita o facto de muitos
processadores esperarem um determinado tempo depois de
extraírem uma instrução e enquanto procedem à sua
descodificação. Este tempo pode ser suficiente para efectuar um
refrescamento.Deste modo os refrescamentos não interferem com os ciclos de leitura e escrita e são "transparentes" para o processador.__

__No refrescamento por “burst” o refrescamento de todas as linhas é
efectuado sequencialmente e de uma só vez, ao fim de cada 2 ms
de intervalo. Este método tem o inconveniente de não ser possível
efectuar ciclos de leitura ou escrita da memória durante o
período, relativamente longo, do “burst” de refrescamento.__

__O refrescamento "distribuido" baseia-se no facto de não
ser importante o modo como se distribui o refrescamento das
diversas linhas dentro do período de refrescamento, desde que se
assegure que cada linha é refrescada com a periocidade exigida.
Este processo permite garantir a satisfação das exigências da
memória ao mesmo tempo que não afeta seriamente a leitura ou
a escrita na memória.__

![image](https://user-images.githubusercontent.com/12052283/85337452-06e3a180-b4d0-11ea-8bdb-52ee923c2791.png)

## Resposta

## a)

![image](https://user-images.githubusercontent.com/12052283/85338241-6a220380-b4d1-11ea-8b4f-4c538c163f7f.png)

![image](https://user-images.githubusercontent.com/12052283/85338587-16fc8080-b4d2-11ea-8834-d7d8a65b628b.png)


# Época Recurso (22/07/2015)

![image](https://user-images.githubusercontent.com/12052283/85338818-87a39d00-b4d2-11ea-9d31-529e926e29f6.png)

## Resposta

## a, b)

__A memória RAM Estática é mais conhecida por SRAM. O flip flop é o elemento básico de uma SRAM.__


![image](https://user-images.githubusercontent.com/12052283/85339194-28925800-b4d3-11ea-9c2c-92fc43ed3ec4.png)


![image](https://user-images.githubusercontent.com/12052283/85339256-4cee3480-b4d3-11ea-8fba-c74da2d6af25.png)

## a, b)

__A memória RAM Dinâmica é mais conhecida por DRAM. O condensador é o elemento básico de uma DRAM.__

__A Célula de memória DRAM tem apenas um
transístor de forma a optimizar os espaço.
Este elemento de mémoria não apresenta a
estabilidade de memória estática, dado que a
informação é agora armazenada apenas num
condensador Cs , (storage capacitor).__

![image](https://user-images.githubusercontent.com/12052283/85339415-9cccfb80-b4d3-11ea-988f-bd624f3a9c37.png)

![image](https://user-images.githubusercontent.com/12052283/85339464-ba9a6080-b4d3-11ea-961e-760398bbb99c.png)


![image](https://user-images.githubusercontent.com/12052283/85339563-f0d7e000-b4d3-11ea-8b16-db4dfac9a062.png)

## Resposta

__A tecnologia Hyper-Threading possibilita um único processador executar dois pedaços de código distintos(threads)simultaneamente.__

__Os processadores lógicos de um processador com tecnologia HT partilham os recursos de execução do processador que inclui o motor de execução, as caches, o bus e o firmware.__

__Essa tecnologia faz com que cada núcleo do processador possa executar mais de um thread de uma única vez, tornando o sistema mais rápido quando se usam vários programas ao mesmo tempo.__

![image](https://user-images.githubusercontent.com/12052283/85340638-f9311a80-b4d5-11ea-8ff3-f661f43ae5d3.png)

## Resposta

## a)

![image](https://user-images.githubusercontent.com/12052283/85341819-9f7e1f80-b4d8-11ea-9110-bb882456b522.png)

## b)

__A tag é usada para armazenar endereços. Quando um endereço armazenado corresponde a um endereço de entrada, é emitido um sinal para executar uma função. É usado na cache do CPU, para controlar quais endereços de memória estão armazenados na cache.__

## c)

![image](https://user-images.githubusercontent.com/12052283/85342233-9c376380-b4d9-11ea-8af5-5df05942b635.png)


![image](https://user-images.githubusercontent.com/12052283/85342323-d9035a80-b4d9-11ea-9693-e18725f37ab6.png)

## Resposta

__A CPU realiza as funções de processamento e cálculo, constituindo a peça mais importante de um computador.__

__A secção de aquisição e descodificação de instruções é onde são recebidas as instruções provindas de memórias para, em seguida, serem descodificadas de modo a que a CPU possa determinar quais as operações a realizar.__

__A secção de execução é constituida pela unidade de controlo, unidade aritmética e os registos.__

__A unidade de controlo controla ou determina as operações a efetuar em cada instante, enviando sinais para os outros componentes.__

__A unidade aritmética e lógica é responsável pela execução de operações e os registos são usados para armazenar resultados temporários e certas informações de controlo.__

__O barramento é um conjunto de linhas de comunicação que permitem a interligação entre dispositivos. Esta zona é conhecida por "DataPath".__

# Época Recurso (13/07/2013)

![image](https://user-images.githubusercontent.com/12052283/85601608-108b1780-b63e-11ea-910f-27d2d1fc7c3c.png)


## Resposta

## a)

![image](https://user-images.githubusercontent.com/12052283/85602707-28af6680-b63f-11ea-8554-d98de9cbdb46.png)

## b)

![image](https://user-images.githubusercontent.com/12052283/85606755-00296b80-b643-11ea-9e3f-532d870b4756.png)


![image](https://user-images.githubusercontent.com/12052283/85606881-1c2d0d00-b643-11ea-88b2-ef75cc559bd0.png)


__A gravação longitudinal trata-se de uma técnica antiga, mas que só começou a perder espaço com a popularização dos atuais discos rígidos SATA.__

__Ao passar por uma área já gravada para realizar a leitura de dados, a cabeça utiliza indução elétrica ou resistência para capturar o campo magnético existente ali, permitindo a obtenção dos dados.__

__Com a gravação longitudinal chegando ao seu limite, a indústria teve que procurar uma alternativa. É aí que entra em cena a gravação perpendicular, bastante utilizada nos dias de hoje.__

__Nesta técnica, as partículas são alinhadas de maneira perpendicular, ou seja, na vertical, como se as partículas ficassem em "pé" em vez de "deitadas". Uma camada extra existente logo abaixo ajuda a tornar o processo ainda mais efetivo.__

__A gravação perpendicular consegue não só aumentar expressivamente a capacidade de armazenamento, como protege o disco do mencionado risco de desmagnetização. Além disso, o alinhamento vertical torna a camada mais espessa, gerando campos mais fortes e, assim, facilitando o trabalho da cabeça de leitura e gravação.__

# Época Normal (02/07/2013)

![image](https://user-images.githubusercontent.com/12052283/85608935-189a8580-b645-11ea-980f-8fc6aff08602.png)

## Resposta

## a)

__Para gravar dados na célula, é necessário primeiro
apagar os já existentes. Isso é feito aplicando-se uma
corrente eléctrica que flui do “emissor” para o Control
Gate, essa corrente “limpa” o Floating Gate,
eliminando qualquer carga elétrica armazenada.
A regravação só pode ser feita um número finito de
vezes, de 10 a 100 mil vezes. Daí o mito de que os SSDs
têm uma vida útil curta. No entanto pode levar algum
tempo a alcançar o limite.__

## b)

__Existem dois tipos de memória Flash:__

__Flash NOR__

    lançada em 1988 tem um sistema de endereçamento
    muito semelhante à das tradicionais memórias RAM, que
    permite correr programas directamente adaptando-se para
    substituir as memórias ROM, até então usadas para gravar o
    BIOS.

__Flash NAND__

    usadas actualmente, são muito mais baratas que as
    NOR e muito mais rápidas a gravar dados. Usam um sistema de
    endereçamento de páginas de 4 KB que são acedidas de forma
    sequencial, da mesma forma que é feito em um HDD, não
    sendo possivel correr programas a partir de si mesmas.

![image](https://user-images.githubusercontent.com/12052283/85609386-8941a200-b645-11ea-8cf7-c0074a5c655f.png)


## c)

__Originalmente, os chips de memória utilizavam apenas
uma tecnologia chamada SLC (Single-Level Cell).__

__Recentemente foi criada a tecnologia MLC (Multi-
Level Cell), onde cada célula de memória armazena
dois ou três bits, ao invés de apenas um. Isso é
conseguido com a utilização de tensões diferentes,
em vez de apenas duas.__

__A variante MLC (Multi Level Cell) permite vários níveis
por célula mas está más sujeita a erros.__


![image](https://user-images.githubusercontent.com/12052283/85609594-c27a1200-b645-11ea-9ef3-9a17c8e59e0b.png)

## Resposta

![image](https://user-images.githubusercontent.com/12052283/85613248-3538bc80-b649-11ea-994a-b88971bcac16.png)
