using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Airbnb.Models
{
    public class Booking
    {
        public int BookingId { get; set; }

        [Required]
        [DataType(DataType.Date)]
        [Display(Name = "Booking From" )]
        public DateTime BookingFrom { get; set; }


        [Required]
        [DataType(DataType.Date)]
        [Display(Name = "Booking Until")]
        public DateTime BookingUntil { get; set; }

        [Display(Name = "Booking Status")]
        public string Status { get; set; } = "Pending";

        /*
         * Um booking tem apenas um accomodation
         */
        public int AccomodationId { get; set; }
        public Accomodation Accomodation { get; set; }

        /*
         * uma reserva é feita por um cliente
         */
        public int CustomerId { get; set; }
        public Customer Customer { get; set; }

        /*
         * uma reserva é gerida por um empregado
         */
        public int? EmployeeId { get; set; }
        public Employee Employee { get; set; }
    }
}
