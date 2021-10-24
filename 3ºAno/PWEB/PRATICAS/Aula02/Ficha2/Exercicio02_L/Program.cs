using System;
using System.Linq;
using System.Collections.Generic;

// usando query syntax ou extension methods

namespace Exercicio02_L
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] ListaUm = {  "C#", "Aprender C#","ASP.NET Core com C#",
                "Entity Framework", "Bootstrap", "Identity", "Lambda", "Delegates",
                "Linq", "POO com C# "};
            string[] ListaDois = { "C#", "ASP.NET Core", "Linq", "Lambda e C#" };
            int[] Numeros = { 10, 23, 54, 77, 85, 12, 1, 4, 53 };

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

        }
    }
}
