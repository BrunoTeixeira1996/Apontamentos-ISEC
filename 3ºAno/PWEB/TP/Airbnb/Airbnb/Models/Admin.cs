using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Airbnb.Models
{
    public class Admin
    {
        public int AdminId { get; set; }

        public ApplicationUser ApplicationUser { get; set; }

    }
}
