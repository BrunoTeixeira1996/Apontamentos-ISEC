using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha6.Models
{
    public class CategoriaComContagem
    {
        public int IdCategoria { get; set; }
        public string Nome { get; set; }
        public int QuantProdutos { get; set; }

        public string NomeComQuantidade
        {
            get { return $"{Nome} ({QuantProdutos.ToString()})"; }
        }
    }
}
