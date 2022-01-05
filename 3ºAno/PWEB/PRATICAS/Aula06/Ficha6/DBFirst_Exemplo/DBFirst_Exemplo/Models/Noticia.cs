using System;
using System.Collections.Generic;

#nullable disable

namespace DBFirst_Exemplo.Models
{
    public partial class Noticia
    {
        public int Id { get; set; }
        public string Titulo { get; set; }
        public string Descricao { get; set; }
        public DateTime Data { get; set; }
    }
}
