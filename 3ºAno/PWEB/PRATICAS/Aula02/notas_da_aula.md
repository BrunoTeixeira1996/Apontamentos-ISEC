# Aula 18/10/2021

- Ler a ficha2 na parte do Linq

- Existem duas formas para usar o Linq
  - extension methods
  - query syntax

- Com o linq extension methods temos de pegar na lista e vermos os métodos que temos , por exemplo o OrderBy

- Contar o numero de palavras numa lista de strings

```csharp
// linq extension method
var resultado = ListaUm.Select(e => e.Split(" ").Lenght);

// linq query method
var resultado2 = from e in ListaUm select e.Split(" ").Lenght);
```

- O `.Split()` cria uma lista com as palavras usando o espaço como delimitador e usando o `Lenght` conseguimos saber o tamanho dessa lista sabendo assim o numero de palavras por string


- Quando quero filtrar os dados utilizo o `Where`

- Quando quero filtrar e transformar os dados utilizado o `Select`

## Referências
