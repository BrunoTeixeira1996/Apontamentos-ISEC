using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha8.Models
{
    public class Produto
    {
        public int ProdutoId { get; set; }

        [Required]
        [StringLength(250,MinimumLength =3,ErrorMessage ="Introduza no máximo 250 chars e no minimo 3")]
        public string Nome { get; set; }

        [StringLength(5000,MinimumLength = 10,ErrorMessage ="Introduza no máximo 5000 chars e no minimo 10")]
        public string Descricao { get; set; }


        public double Preco { get; set; }

        // data de embalamento
        [DataType(DataType.Date)]
        public DateTime DataEmbalamento { get; set; }


        // data de validade
        [DataType(DataType.Date)]
        public DateTime DataValidade { get; set; }

        /*
         * Um produto tem uma categoria
         */
        public int CategoriaId { get; set; }
        public Categoria Categoria { get; set; }
    }
}
