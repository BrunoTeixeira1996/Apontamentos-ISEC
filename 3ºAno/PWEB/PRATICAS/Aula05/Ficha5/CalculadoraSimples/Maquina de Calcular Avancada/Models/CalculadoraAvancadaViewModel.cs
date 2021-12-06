using Microsoft.AspNetCore.Mvc.Rendering;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Maquina_de_Calcular_Avancada.Models
{
    public class CalculadoraAvancadaViewModel
    {
        [Display(Name = "Primeiro operado")]
        public string OperandoEsq { get; set; }

        [Display(Name = "Segundo operado")]
        public string OperandoDir { get; set; }

        [Display(Name = "Resultado")]
        public string Resultado { get; set; }

        [Display(Name = "Número de Digitos")]
        public int NDigitos { get; set; }

        // dropdown list
        public SelectList Digitos { get; set; }

        // construtor visto que agora queremos que o objeto inice ja com uma lista preenchida
        public CalculadoraAvancadaViewModel()
        {
            Digitos = AppCode.DigitosDecimais.ListaDigitosDecimais();
        }
    }
}
