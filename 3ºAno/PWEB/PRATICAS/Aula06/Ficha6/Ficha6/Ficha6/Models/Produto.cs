using System;
using System.Collections.Generic;

#nullable disable

namespace Ficha6.Models
{
    public partial class Produto
    {
        public int IdProduto { get; set; }
        public string NomeProduto { get; set; }
        public int IdCategoria { get; set; }

        public virtual Categoria IdCategoriaNavigation { get; set; }
    }
}
