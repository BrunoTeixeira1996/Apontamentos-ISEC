using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha8.Models
{
    public class Categoria
    {
        public int CategoriaId { get; set; }

        [Required]
        [StringLength(250, MinimumLength = 3, ErrorMessage = "Introduza no máximo 250 caracteres e no minimo 3")]
        public string Nome { get; set; }

        /*
         * Uma categoria tem vários produtos
         */
        public virtual ICollection<Produto> Produtos { get; set; }
    }
}
