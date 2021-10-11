using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercicio1
{
    class Program
    {
        static void Main(string[] args)
        {
            Tarefa t1 = new Tarefa("1a Tarefa",Prioridade.Normal, Categoria.Trabalho, Estado.Por_Executar, DateTime.Parse("2021/10/11 15:00"));
            Tarefa t2 = new Tarefa("2a Tarefa", Prioridade.Baixa, Categoria.Trabalho, Estado.Por_Executar, DateTime.Parse("2021/10/11 16:30"));
            Tarefa t3 = new Tarefa("3a Tarefa", Prioridade.Alta, Categoria.Trabalho, Estado.Por_Executar, DateTime.Parse("2021/10/11 16:30"));



            //Console.WriteLine(t1.Imprime());

            Utilizador bruno = new Utilizador("Bruno");

            bruno.AdicionaTarefa(t1);
            bruno.AdicionaTarefa(t2);
            bruno.AdicionaTarefa(t3);


            //bruno.ListaTarefas();

            //bruno.RemoveTarefa(t2);

            //bruno.ListaTarefas();

            bruno.ListaTarefasPrioridade("Baixa");
        }
    }
}
