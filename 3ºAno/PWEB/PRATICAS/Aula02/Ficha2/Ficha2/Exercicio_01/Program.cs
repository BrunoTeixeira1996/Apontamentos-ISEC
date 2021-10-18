using System;
using System.Linq;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Text;

namespace Exercicio_01
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] Lista = {"C#", "Aprender C#", "ASP.NET Core com C#", "Entity Framework", "Bootstrap", "Identity", "Lambda","Delegates","Linq","POO com  C#"};

            var ListA = new List<string>();
            foreach (var x in Lista) if (x.Contains("C#")) ListA.Add(x);

            var ListB = from s in Lista where s.Contains("C#") select s;

            var ListC = Lista.Where(l => l.Contains("C#"));
        }
    }
}
