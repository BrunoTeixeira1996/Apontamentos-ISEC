using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Airbnb.Models
{
    public class AccomodationRating
    {
        public int AccomodationRatingId { get; set; }

        [Required]
        [Display(Name = "Comment about Accomodation")]
        [StringLength(5000, MinimumLength = 10, ErrorMessage = "Max 5000 chars min 10")]
        public string Comment { get; set; }

        /*
         * Uma avaliação pertence a uma accomodation
         */
        public int AccomodationId { get; set; }
        public Accomodation Accomodation { get; set; }

        /*
         * uma avaliação é dada por um utilizador
        */
        public int CustomerId { get; set; }
        public Customer Customer { get; set; }
    }
}
