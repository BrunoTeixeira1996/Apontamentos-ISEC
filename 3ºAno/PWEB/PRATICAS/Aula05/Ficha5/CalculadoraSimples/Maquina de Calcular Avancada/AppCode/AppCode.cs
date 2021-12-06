using CalculadoraSimples;
using Microsoft.AspNetCore.Mvc.Rendering;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Maquina_de_Calcular_Avancada.AppCode
{
    public static class Operadores
    {
        static public TipoOperador GetOperador(string op)
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

    // preenche lista de digitos decimais
    public static class DigitosDecimais
    {
        static public SelectList ListaDigitosDecimais(int ndd = 6)
        {
            List<SelectListItem> ListaNumDig = new List<SelectListItem>();

            for (int i = 0; i <= ndd; i++)
                ListaNumDig.Add(new SelectListItem
                {
                    Text = $"Digitos Decimais [{i.ToString()}]",
                    Value = i.ToString()
                });

            return new SelectList(ListaNumDig, "Value", "Text");
        }
    }
}
