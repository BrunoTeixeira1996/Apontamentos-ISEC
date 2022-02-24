using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Airbnb.Models
{
    public class Employee
    {
        public int EmployeeId { get; set; }

        public string Name { get; set; }
        

        public ApplicationUser ApplicationUser { get; set; }

        // tem um Manager
        public int ManagerId { get; set; }
        public Manager Manager { get; set; }


        // gere reservas
        public ICollection<Booking> Bookings { get; set; }

        /*
         * um empregado pode gerir vários alojamentos
         */
        public ICollection<Accomodation> Accomodations { get; set; }

    }
}
