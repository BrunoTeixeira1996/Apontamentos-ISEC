using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercicio2
{   
    // classe que deriva da classe Funcionario
    class FuncionarioComSalarioFixo : Funcionario
    {
        public float SalarioBase { get; set; }
        public FuncionarioComSalarioFixo(string nome, string apelido, float valorvendas, float salariobase):base(nome,apelido,valorvendas)
        {

            SalarioBase = salariobase;

        }

        public string MostraSalario()
        {
            return string.Format("{0:F2}", 0.2 * TotalVendas + SalarioBase);
        }
    }
}
