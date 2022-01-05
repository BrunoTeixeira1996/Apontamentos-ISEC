using System;
using System.Collections.Generic;

#nullable disable

namespace Ficha6.Models
{
    public partial class Categoria
    {
        public Categoria()
        {
            Produtos = new HashSet<Produto>();
        }

        public int IdCategoria { get; set; }
        public string NomeCategoria { get; set; }

        public virtual ICollection<Produto> Produtos { get; set; }
    }
}
