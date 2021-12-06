using CalculadoraSimples;
using Maquina_de_Calcular_Avancada.Models;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;

namespace Maquina_de_Calcular_Avancada.Controllers
{
    public class CalculadoraAvancadaController : Controller
    {
        public IActionResult Index()
        {
            return View(new CalculadoraAvancadaViewModel());
        }

        
        [HttpPost]
        [ValidateAntiForgeryToken]
        // no Bind colocamos os inputs que estão no Index.cshtml
        // Podiamos tambem usar um FormCollection, o Bind é apenas uma alternativa

        // Quando carregamos no botao de operação, o que vai ser enviado para o servidor é o "value"
        // como definimos "Operacao" no nome dos botoes de operação, usamos string Operacao
        public IActionResult Index([Bind(include: "OperandoEsq,OperandoDir,NDigitos")] CalculadoraAvancadaViewModel calculadora, string Operacao)
        {
            calculadora.Resultado = MaquinaCalcular.Calcular(
                calculadora.OperandoEsq,
                AppCode.Operadores.GetOperador(Operacao),
                calculadora.OperandoDir,
                calculadora.NDigitos);

            Debug.WriteLine(calculadora.OperandoEsq);
            Debug.WriteLine(calculadora.OperandoDir);
            Debug.WriteLine(calculadora.NDigitos);
            Debug.WriteLine(Operacao);
            Debug.WriteLine(calculadora.Resultado);

            return View(calculadora);
        }
    }
}
