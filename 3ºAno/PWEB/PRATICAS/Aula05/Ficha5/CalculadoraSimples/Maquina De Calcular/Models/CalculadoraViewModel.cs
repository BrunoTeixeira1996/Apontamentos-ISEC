using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Maquina_De_Calcular.Models
{
    public class CalculadoraViewModel
    {
        [Display(Name = "Primeiro Operando")]
        [Required]
        public string op1 { get; set; }


        [Display(Name = "Segundo Operando")]
        [Required]
        public string op2 { get; set; }

        [Display(Name = "Resultado")]
        [Editable(false)]
        public string resultado { get; set; }
    }
}
