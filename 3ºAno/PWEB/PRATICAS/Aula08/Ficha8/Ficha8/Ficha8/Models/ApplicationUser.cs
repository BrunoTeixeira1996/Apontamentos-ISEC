using Microsoft.AspNetCore.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha8.Models
{
    public class ApplicationUser: IdentityUser
    {
        [PersonalData]
        public string PrimeiroNome { get; set; }

        [PersonalData]
        public string UltimoNome { get; set; }
    }
}
