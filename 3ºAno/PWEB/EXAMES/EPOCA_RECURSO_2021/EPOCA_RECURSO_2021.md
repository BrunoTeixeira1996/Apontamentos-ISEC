# Epoca Recurso 2020/2021

## Pergunta 1

### a)

- São tipos que permitem fazer referência a métodos
- Podem ser usados para passar métodos como argumentos a outros métodos
- Pode ser usado para encapsular um método com nome ou anónimo

### b)


Como o delegate é parecido a um ponteiro para função o mesmo é usado para permitir fazer referência a métodos, sendo assim são tipos que fazem referência a métodos e estas referências podem sempre ser passados como argumentos de outros métodos

Outra vantagem do delegate é que conseguimos "mascarar" um método com um nome ou até mesmo anónimo


## Pergunta 2


A afirmação nao faz qualquer sentido uma vez que um site construido seja em que framework for é sempre possível ser acedido pelo cliente e o mesmo não precisa de ter nada instalado, apenas um browser para aceder ao mesmo. Então a afirmação é falsa uma vez que se um cliente quiser aceder a um site ASP .Net MVC 5.0 apenas precisa de um browser uma vez que o servidor responsável pelo site é que irá conter a base de dados e todo o software necessário para o bom funcionamento do site.


## Pergunta 3

### a)


Se tivermos a falar do Html.DisplayName e do Html.DisplayNameFor existem algumas diferenças sendo que o que utiliza o For representa uma label que apenas mostra o titulo de um certo campo e o outro mostra o valor em si.


### b)


A view é a interface do utilizador para a apresentação dos dados, ou seja, a mesma representa a UI da aplicação. Esta não deve executar qualquer lógica de negócio, ou interagir com a base de dados diretamente, deve trabalhar somente com os dados que lhe são fornecidos pelo controlador e de seguida apresentar esses dados ao utilizador.


### c)


Esta afirmação é falsa uma vez que é possível utilizarmos o framework ASP.Net MVC 5.0 para desenvolver sites sem dar uso aos HTML Helpers e ao Razor. Podemos por exemplo utilizar views em aspx e assim já não precisariamos do Razor nem dos HTML Helpers, no entanto estes dois são uma vantagem enorme e é aconselhado ser usado.


## Pergunta 4

### a)


A imagem representa uma estrutura de LINQ to Entities ou seja, como o SQL Server apenas entende SQL Querys, a Query LINQ tem de ser traduzido para SQL e para isso é usado o LINQ em que este faz a transformação de Query LINQ para SQL Query.
O LINQ é então usado para fazer pesquisas em base de dados SQL.


### b)


Sim é indiferente uma vez que ambos produzem o mesmo resultado no entanto os Extension Methods são mais recentes e contêm muito mais vantagens e facilidade no que toca a manipulação e pesquisa de dados na base de dados.


## Pergunta 5

### a)


A última intrução está a percorrer a lista de alunos, agarra no Nome do objeto, divide por espaços, vai pegar no último elemento da divisão e vai ver se a primeira letra é um T maisculo, se assim for é guardado na variavel alunosF tornando-se esta depois uma lista de alunos que têm o ultimo nome com um T maisculo.


### b)


Como estamos a usar o Where numa lista de alunos do tipo Aluno estamos a usar um IEnumerable<T>, caso estivessemos a usar um contexto da base de dados estariamos a usar uma IQueryable logo o tipo de alunosF é uma IEnumerable<T>.

Este tipo é usado para guardar dados da base de dados numa lista de objetos e é bastante útil para depois ser passado para uma vista como um IEnumerable e na vista utilizar o Razor para poder ser mostrado ao utilizador os dados da tal lista de objetos.


### c)


O => é o operador lambda e é usado nesta instrução para ser possível acedermos ao atributo do objeto (Nome) sem termos de definir o objeto em si ou seja, fazemos isto de maneira anónima podendo depois ser usado o Split de maneira mais fácil.
Podemos utilizar a expressão lambda como parâmetro de um método por exemplo

