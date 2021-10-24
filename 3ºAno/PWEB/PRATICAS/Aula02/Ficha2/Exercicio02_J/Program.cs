using System;
using System.Linq;
using System.Collections.Generic;

// usando query syntax ou extension methods

namespace Exercicio02_J
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

            // linq extension methods
            var resultado = Numeros.GroupBy(e => e % 2);
            foreach (var grupo in resultado)
            {
                Console.Write(grupo.Key == 0 ? "\n Grupo dos Numeros Pares: " : "\n Grupo dos Numeros Impares");
                foreach (var x in grupo) Console.Write($"{x} ");
                ;
            }



            // ----------------------------------------------------------------------------//

            Console.Write("\n");

            // linq query method
            var resultado2 = from x in Numeros group x by (x % 2);
            foreach (var grupo in resultado2)
            {
                Console.Write(grupo.Key == 0 ? "\n Grupo dos Numeros Pares: " : "\n Grupo dos Numeros Impares");
                foreach (var x in grupo) Console.Write($"{x} ");
;            }

        }
    }
}
