# Aula 11/10/2021

- Feito o exercicio 1,2 e 3 da Ficha 1

- Classe abstrata é uma especie de esqueleto que serve apenas para apresentar ao utilizador
	- Esta classe nunca se instancia e os metodos normalmente são todos `public abstract [tipo] [nome do metodo]`
	- O método especial `ToString()` tem de ser `public abstract override string ToString()` porque este método herda de um Objeto e como não vai ser instanciado nenhum temos de dar `override`
	- A classe `FiguraPlana` é uma classe abstrata

- Nos métodos das classes que derivam da classe abstrata usamos `public override [tipo] [nome do metodo]`
	- As classes `Circulo`, `Triangulo` e `Retangulo` são classes derivadas


## Referências

* https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/override

* https://www.damirscorner.com/blog/posts/20131028-UsingAbstractOverrideInC.html

* https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/abstract