using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha8.Models
{
    public class RoleViewModel
    {
        public string Id { get; set; }
        public string Nome { get; set; }
        public IEnumerable<ApplicationUser> Utilizadores { get; set; }
    }
}
