# Aula 20/10/2021

## LDAP

- É uma base de dados especializada definida de forma hierárquica, otimizado para leitura suportando sofisticados métodos de pesquisa, com o objetivo de proporcionar uma resposta rápida a um enorme volume de consultas e onde são armazenadas informações estáticas de objetos de rede

### Distinguished Name (DN)

- Identifica univocamente o objeto no diretório

- Não podem existir objetos com DN iguais no serviço de diretório

- Contém informação suficiente para encontrar o objeto

![image](https://user-images.githubusercontent.com/12052283/138733637-b2a2bcb7-408a-4ce4-8fd4-9701e16b1365.png)

![image](https://user-images.githubusercontent.com/12052283/138733680-76e2f4c7-bd61-4241-a038-339f49fecd83.png)

## Active Directory

- É uma base de dados centralizada e estruturada que guarda informação sobre utilizadores e recursos de uma organização

- Utiliza o protocolo LDAP para suporte às comunicações

- **Devemos ter sempre mais do que 1 controlador de domínio(Domain Controler)**

### Procedimento

- Um cliente faz um pedido a um servidor AD (Domain Controler) através de um protocolo do LDAP e recebe deste a resposta à sua soliticação

- Utiliza uma ligação e partilha de informação com o **DNS**

- Para autenticação é utilizado o **Kerberos**

### Características

- Armazenamento centralizado de informação

- Integração com o DNS

- Replicação de informação

- Gestão da configuração de clientes

- Definição de pliticas de gestão

### Estruturas lógicas

![image](https://user-images.githubusercontent.com/12052283/138735661-119addc2-bd0a-4ed6-bc46-a8251a214e9d.png)


- Esquemas
  - **Define não só os tipos de objetos como também os tipos dos atributos**
  - **Deve fazer-se raramente alterações neste esquema**

- Florestas
  - **Uma floresta é um agrupamento de árvores**
  - **Uma das razões de serem criadas florestas é por exemplo na separação da administração em grupos autónomos que provavelmente não podem estabelecer relações de confiança**

![image](https://user-images.githubusercontent.com/12052283/138735483-464e497c-d819-4ae3-a2d0-10028984f9c4.png)

- Árvores
  - **Os domínios quando são agrupados numa estrutura hierarquica formam uma árvore**
  - **Resulta por exemplo da adição de subdomínios a um domínio base**
  
![image](https://user-images.githubusercontent.com/12052283/138735398-3a0bed64-d46a-426e-991e-71dd71db4240.png)

- Domínios
  - **Conjunto de objetos definidos de forma administrativa que partilham a mesma base de dados de diretório comum, as diretivas de segurança e as relações de confiança**
  - **Uma AD pode ser constituida por um ou mais domínios**

- Unidades de organização
  - **É um contentor para guardar os diversos objetos existentes num domínio em grupos lógicos de administração e permitir um método de endereçamento da AD através do LDAP**
  - **Normalmente são pastas que de dividem por ramos, por exemplo para os RH, para a Administração, para a IT...**

![image](https://user-images.githubusercontent.com/12052283/138736384-78f59960-ca13-48c8-a7dc-adec0efabf0b.png)


### Explicação de Dominios Arvores e Florestas

![image](https://img.portalgsti.com.br/hfz-gs6tBAYyklrAQQZsrsntkbk=/480x250/https://www.portalgsti.com.br/media/uploads/article/526/2017/08/28/floresta-arvore-e-dominio_rZAFf6V.png)

- Normalmente temos apenas 1 floresta com 1 domínio

- **O nome da floresta é o nome do primeiro domínio que existir lá**

### Estruturas físicas

- Sites
  - **É um conjunto de controladores de domínio, ligados por uma ligação de alto desempenho**

- Controladores de Domínio
  - **Computador que tem armazenada uma cópia da informação do domínio**
  - **Sendo que um domíniio pode conter mais do que um controlador de dominio**

![image](https://user-images.githubusercontent.com/12052283/138736709-97a950f4-c8d9-4652-8bf7-bf0b4476f9dc.png)

![image](https://user-images.githubusercontent.com/12052283/138736736-62199f65-6eca-4a05-bc4f-5c29e51e49df.png)

## Read-Only Domain Controller (RODC)

- Controlador de dominio apenas de leitura

- Com este DC, as organizações podem implantar um controlador de domínio em locais onde a segurança fisica não pode ser garantida

- **O primeiro DC na floresta ou domínio não poder ser um RODC**

- Este DC guarda partições somente para leitura dos dados

- Uma grande vantagem é usar este DC como autenticação. Ou seja, odemos ter um RODC e em vez de ir ao DC autenticar, autenticamos no RODC porque é mais rápido

- Uma desvantagem é poder demorar a replicar a informação do DC para o RODC

## Onde são guardados os ficheiros?

- A BD do AD fica na pasta `%SystemRoot%\NTDS`

- O sysvol é a pasta onde são armazenados os ficheiros públicos do domínio
  É uma boa pasta para colocar software para replicar para mais PCs

- É aconselhavel que estes ficheiros sejam guardados num disco diferente do sistema


## Planeamento para o desenvolvimento de uma AD

- Conceção

- Implementação

- Operação
