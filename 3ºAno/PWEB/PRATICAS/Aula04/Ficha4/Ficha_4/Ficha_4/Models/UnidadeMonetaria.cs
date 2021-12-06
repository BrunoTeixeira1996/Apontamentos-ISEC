using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

/* O DataAnotations (Display(Name=) permite alterar atributos
 * Permite tambem definir valores, ou seja validações
 */

namespace Ficha_4.Models
{
    public class UnidadeMonetaria
    {
        public int Id { get; set; }
        public string Codigo { get; set; }

        [Display(Name="Valor por Euro")]
        public double ValorPorEuro { get; set; }
        public DateTime Data { get; set; }
    }
}
