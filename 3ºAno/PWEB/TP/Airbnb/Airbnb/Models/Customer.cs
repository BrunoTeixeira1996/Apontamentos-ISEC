using Microsoft.AspNetCore.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Airbnb.Models
{
    public class Customer
    {
        public int CustomerId {get; set;}

        public string Name { get; set; }
        public ICollection<AccomodationRating> AccomodationRatings { get; set; }
        public ICollection<Booking> Bookings { get; set; }
        public ApplicationUser ApplicationUser { get; set; }
    }
}
