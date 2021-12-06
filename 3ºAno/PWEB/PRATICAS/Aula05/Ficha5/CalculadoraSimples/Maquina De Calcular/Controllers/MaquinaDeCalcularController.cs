using CalculadoraSimples;
using Maquina_De_Calcular.Models;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Maquina_De_Calcular.Controllers
{
    public class MaquinaDeCalcularController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        // quando carregamos nalgum botao
        [HttpPost]
        [ValidateAntiForgeryToken]
        // no Bind colocamos os inputs que estão no Index.cshtml
        // Podiamos tambem usar um FormCollection, o Bind é apenas uma alternativa

        // Quando carregamos no botao de operação, o que vai ser enviado para o servidor é o "value"
        // como definimos "Operacao" no nome dos botoes de operação, usamos string Operacao
        public ActionResult Index([Bind(include:"op1,op2")] CalculadoraViewModel calculadora, string Operacao)
        {
            calculadora.resultado = MaquinaCalcular.Calcular(
                calculadora.op1,
                GetOperador(Operacao),
                calculadora.op2);

            return View(calculadora);
        }

        // Aqui com este NonAction estamos a dizer que este método nao pode ser invocado pelo user diretamente
        [NonAction]
        private TipoOperador GetOperador(string op)
        {
            TipoOperador operacao = TipoOperador.divisao;

            switch (op)
            {
                case "Adição":
                    operacao = TipoOperador.adicao;
                    break;
                case "Multiplicação":
                    operacao = TipoOperador.multiplicacao;
                    break;
                case "Subtração":
                    operacao = TipoOperador.subtracao;
                    break;
            }
            return operacao;
        }
    }
}
