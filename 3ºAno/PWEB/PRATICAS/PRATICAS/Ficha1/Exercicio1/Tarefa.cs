using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercicio1
{   
    // enums são criadas sempre fora da classe pois podem vir a ser usadas
    // noutro sitio
    public enum Prioridade
    {
        Baixa,
        Normal,
        Alta
    }

    public enum Categoria
    {
        Pessoal,
        Trabalho
    }

    public enum Estado
    {
        Por_Executar,
        Em_Execucao,
        Concluida
    }

    class Tarefa
    {
        public string Nome { get; set; }
        public Prioridade Prioridade { get; set; }
        public Categoria Categoria { get; set; }
        public Estado Estado { get; set; }
        public DateTime DataRegisto { get; set; }
        public DateTime DataLimite { get; set; }

        // Isto é o construtor 
        public Tarefa(string Nome, Prioridade Prioridade, Categoria Categoria, Estado Estado, DateTime DataLimite)
        {
            // "this" é o objeto em si
            this.Nome = Nome;
            this.Prioridade = Prioridade;
            this.Categoria = Categoria;
            this.Estado = Estado;
            this.DataLimite = DataLimite;
            this.DataRegisto = DateTime.Now;
        }

        // metodo que faz o print de uma tarefa (o tipo é importante, representa o tipo que devolve)
        public string Imprime()
        {
            string resultado = "";
            resultado += "DADOS DA TAREFA: " + this.Nome + "\n";

            resultado += "DATA DE REGISTO: " + this.DataRegisto.ToString() + "\n";

            resultado += "DATA DE CONCLUSÃO: " + this.DataLimite.ToString() + "\n";


            return resultado;

        }

    }


}
