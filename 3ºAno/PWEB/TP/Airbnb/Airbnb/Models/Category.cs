using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Airbnb.Models
{
    public class Category
    {
        public int CategoryId { get; set; }

        [Required]
        [Display(Name = "Category Name")]
        [StringLength(250, MinimumLength = 3, ErrorMessage = "Max 250 chars min 3")]
        public string Name { get; set; }

        /*
         * Uma categoria tem vários accomodations
         */
        public virtual ICollection<Accomodation> Accomodations { get; set; }
    }
}
