using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercicio3
{
    class Program
    {
        static void Main(string[] args)
        {
            Retangulo ret = new Retangulo(6.00f, 5.00f);
            Triangulo tri = new Triangulo(3.00f, 4.00f, 5.00f);
            Circulo circ = new Circulo(7.00f);

            Console.WriteLine(ret.ToString());
            Console.WriteLine(tri.ToString());
            Console.WriteLine(circ.ToString());

        }
    }
}
