using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercicio2
{
    class Program
    {
        static void Main(string[] args)
        {
            Funcionario func1 = new Funcionario("Bruno", "Teixeira", 100);
            FuncionarioComSalarioFixo func2 = new FuncionarioComSalarioFixo("Rafaela", "Mostardinha", 100,10);


            Console.WriteLine(func1.MostraSalario());
            Console.WriteLine(func2.MostraSalario());

        }
    }
}
