using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace JustATest.Models
{
    public class FAQ
    {
        public int Id { get; set; }
        public string Pergunta { get; set; }       
        public string Resposta { get; set; }

        //construtor
        public FAQ()
        {

        }
    }
}
