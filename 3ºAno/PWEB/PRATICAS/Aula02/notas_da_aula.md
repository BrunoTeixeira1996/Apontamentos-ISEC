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

- Integrando o **Where** com o **Select**

```csharp
// linq com extensions methods
            var solucao = ListaUm.Where(s => s.Contains("C#"))
                 .Select(s => new
                 {
                     frase = s.Trim(), // remove espacos a mais
                     primeira = s.Trim().Split(" ").First(), // vai buscar a primeira palavra
                     // se tiver apenas uma palavra escreve "NAO TEM" caso contrario escreve a ultima palvra
                     ultima = (s.Trim().Split(" ")).Count() == 1 ? "NAO TEM" : s.Trim().Split(" ").Last()
                 });

            foreach(var x in solucao)
                Console.WriteLine("Frase: " + x.frase + "\n\tPrimeira Palavra: " + x.primeira + "\n\tUltima Palavra: " + x.ultima);
```

## Referências

- https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/concepts/linq/query-syntax-and-method-syntax-in-linq

- https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/classes-and-structs/extension-methods
