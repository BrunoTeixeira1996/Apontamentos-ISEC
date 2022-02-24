using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Airbnb.Models
{
    public class CustomerViewModel
    {
        public IQueryable<Booking> Bookings { get; set; }
        public IQueryable<AccomodationRating> AccomodationRatings { get; set; }
        public Customer Customer { get; set; }
    }
}
