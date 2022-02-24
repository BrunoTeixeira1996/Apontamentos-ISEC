using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Airbnb.Models
{
    public class Manager
    {
        public int ManagerId { get; set; }

        public ApplicationUser ApplicationUser { get; set; }


        // tem uma lista de empregados
        public ICollection<Employee> Employees { get; set; }

        // tem uma lista de alojamentos
        public ICollection<Accomodation> Accomodations { get; set; }
    }
}
