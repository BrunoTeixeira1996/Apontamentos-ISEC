using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha7_Certo.Models
{
    public partial class Categoria
    {
        public int CategoriaId { get; set; }

        [Display(Name = "Nome da Categoria")]
        [MinLength(2), MaxLength(50)]
        [Required]
        public string Nome { get; set; }

        public virtual ICollection<Produto> Produtos { get; set; }
    }
}
