using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha_4.Models
{
    public class Conversor
    {
        [Display(Name ="Converter de")]
        public int UnidadeInicial { get; set; }
        [Display(Name = "Para")]
        public int UnidadeFinal { get; set; }
        [Display(Name = "Valor a converter")]
        public double ValorInicial { get; set; }

        [Display(Name = "Valor após conversão")]
        public double ValorFinal { get; set; }

        [Display(Name = "Taxa de cambio")]
        public double TaxaDeCambio { get; set; }


    }
}
