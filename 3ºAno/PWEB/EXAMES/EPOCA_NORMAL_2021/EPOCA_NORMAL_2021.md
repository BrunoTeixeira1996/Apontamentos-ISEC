# Epoca Normal 2020/2021

## Pergunta 1

### a)


De um modo geral não se devem apagar fisicamente registos de uma base de dados porque esses dados já estão a ser utilizados por utilizadores ou até mesmo pelo gestor da plataforma, logo uma alternativa que teriamos era usar um script que continha informação que queriamos apagar e para executarmos esse script faziamos uma migração.


### b)


A desnormalização é importante porque tenta otimizar o desempenho de leitura de uma base de dados, adicionando assim dados redundantes. Como normalmente as consultas requerem a utilização de JOINS entre tabelas para obter dados, isto acaba por compremeter o desempenho da base de dados, então para contornar este problema desnormaliza-se a base de dados juntando os dados apenas numa única tabela. Por exemplo na criação de uma view na base de dados em que essa view representa uma query com vários JOINS.


### c)


A razão desse procedimento é para facilitar aos clientes, uma vez que por exemplo, se a loja com o id 1 tiver o nome Zara, é muito mais conveninete o cliente saber que essa loja é a Zara do que saber o seu Id.


## Pergunta 2

### a)


Open authorization é um tipo de autenticação token-based que permite que as organizações partilhem informação através de terceiros (facebook,twitter,etc) sem expor os seus usernames e passwords.


### b)


Deve ser utilizada em situações em que a organização atual confie nos terceiros e esses terceiros sejam confiaveis de modo a existir uma autenticação externa sempre credivel e fiável.



## Pergunta 3

### a)


Quando falamos em autenticação estamos a falar no processo de login por exemplo em que existe um acesso ao website.
Quando falamos em autorização estamos a falar se existe ou não permissão para aquele utilizador que já está previamento autenticado de aceder a um certo recurso.

Não é necessario usar sempre as duas mas ao utilizar uma delas implica a utilização da outra na maioria dos casos


### b)


É uma afirmação falsa uma fez que podemos ter um formulario para o cliente submeter um email com alguns conselhos e para isso temos de ter alguns campos como o mail do mesmo, o seu numero de telemovel e afins e para validar esses campos não precisamos nem de autenticação nem de autorização, apenas precisamos de validar se o email introduzido é um email válido e se o numero de telemovel tambem é um numero válido.


### c)


Em sites desenvolvidos em ASP.Net MVC 5.0 o JavaScript é utilizado no Client-Side ou seja, sempre que queremos gerar alguma coisa que seja visual para o utilizador, neste caso se quisermos utilizar C# teriamos de fazer uso do Blazor que faz com que seja possível executar código C# em Client-Side.


## Pergunta 4

### a)


Temos dois tipos de workflows de utilização de base de dados relacionais. Temos então o DataBase First e o Code First.


### b)


O Database First é bastante útil quando já temos na nossa posse uma base de dados e esta base de dados já contem alguns dados e nós não queremos modificar esses dados. Se optarmos por este workflow, a partir da base de dados já existente podemos criar os nossos modelos de domínio usando o Entity Framework Core com a ajuda do Scaffolding que pega nas tabelas e transforma-as em modelos tendo então uma maneira de comunicar entre modelos e tabelas da base de dados.
O Code First é o workflow normalmente utilizado aquando do inicio da criação de uma aplicação web uma vez que partimos sem base de dados criada e a mesma é criada aplicando migrações (migrações que o Entity FrameWork Core fornece) usando os nosso modelos criados. Ou seja, neste caso a base de dados vai ser criada consoante os nossos modelos podendo as tabelas serem alteradas aplicando migrações à base de dados.

É importante existirem vários workflows porque como foi descrito um workflow é útil se já tivermos uma base de dados e o outro é mais util se nao tivermos base de dados, logo temos um workflow para cada caso.


### c)


Caso tivesse de construir um website ASP.Net MVC 5.0 usaria o Code First porque, como descrevi anteriormente, parto do principio que não tinha base de dados ainda criada e essa iria ser moldada consoante a criação dos meus modelos de domíniio, podendo sempre alterar quando achasse necessário aplicando as migrações que o Entity Framework fornece.


## Pergunta 5

### a)

- Poderão não serem necessários, mas são quase sempre usados !
- Por causa da sua utilização é gerado código HTML ! 
- A sua utilização implica a escrita de instruções mais compactas mas também mais complexas

### b)


Não é obrigatorio utilizar nem HTML Helpers nem Tag Helpers no entanto eles existem para nos dar uma maior facilidade de interagir entre Views e Controllers.

Ao utilizarmos HTML Helpers e Tag Helpers, estes ajudam a criar e a renderizar elementos de HTML em ficheiros Razor, logo geram código HTML.

Ao ser usado os HTML Helpers e os Tag Helpers ficamos com a possibilidade de criar instruções que geram mais do que uma tag em html por exemplo o que faz com que fiquemos com uma instrução contacta, no entanto se não percebermos o que a mesma faz ela pode tornar-se tambem complexa

