using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercicio2
{
    class Funcionario
    {
        public string Nome { get; set; }
        public string Apelido { get; set; }

        public int NIF { get; set; }

        public float TotalVendas { get; set; }

        public Funcionario(string nome, string apelido, float valorvendas)
        {
            Nome = nome;
            Apelido = apelido;
            TotalVendas = valorvendas;
        }

        public string MostraSalario()
        {
            return string.Format("{0:F2}", 0.2 * TotalVendas);
        }

    }
}
