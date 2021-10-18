using System;
using System.Linq;
using System.Collections.Generic;

// usando query syntax ou extension methods

namespace Exercicio02_A
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


            foreach (var x in ListaUm)
                Console.WriteLine(x);

            Console.WriteLine("...........\n");
            Console.WriteLine("Linq com query syntax");
            Console.WriteLine("...........\n");


            // Linq com query syntax
            var resultado = from x in ListaUm orderby x.ToString() select x;

            foreach(var x in resultado)
                Console.WriteLine(x);

            Console.WriteLine("...........\n");
            Console.WriteLine("Linq com extension method");
            Console.WriteLine("...........\n");


            // Linq com extension method
            var resultado2 = ListaUm.OrderBy(e => e.ToString());


            foreach (var x in resultado2)
                Console.WriteLine(x);
        }
    }
}
