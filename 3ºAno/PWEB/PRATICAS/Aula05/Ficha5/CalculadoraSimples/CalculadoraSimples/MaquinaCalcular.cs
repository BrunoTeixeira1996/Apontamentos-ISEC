using System;
using System.Diagnostics;
using System.Globalization;

namespace CalculadoraSimples
{
    // enum para as operações algébricas
    public enum TipoOperador { adicao, subtracao, multiplicacao, divisao};
    // adssa
    public class MaquinaCalcular
    {
        public static string Calcular(string OpEsq, TipoOperador Op, string OpDir, int NumDigDec = 2)
        {
            // se valor inserido (no OpEsq ou OpDir) nao for numerico, retornar "Valor incorreto"
            bool isNumberOpEsq = double.TryParse(OpEsq, out double first);
            bool isNumberOpDir = double.TryParse(OpDir, out double second);


            if (!isNumberOpEsq || !isNumberOpDir)
            {
                return "Valor Incorreto";
            }
               

            
            double result;
            if (Op == TipoOperador.adicao)
            {
                result = first + second;
            }
            else if (Op == TipoOperador.subtracao)
            {
                result = first - second;
            }
            else if(Op == TipoOperador.multiplicacao)
            {
                result = first * second;
            }
            // se na divisao dê um valor por zero (OpDir = 0) , retornar "Indefinido"
            else if (Op == TipoOperador.divisao)
            {
                if (second == 0) { return "Indefinido"; }
                result = first / second;
            }
            else
            {
                return "Operação nao conhecida!";
            }
            return result.ToString();
        }
    }
}
