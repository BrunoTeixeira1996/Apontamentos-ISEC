using Microsoft.AspNetCore.Http;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Threading.Tasks;

namespace Airbnb.Models
{
    public class Accomodation
    {
        public int AccomodationId { get; set; }

        [Required]
        [Display(Name="Accomodation Name")]
        [StringLength(250, MinimumLength = 3, ErrorMessage = "Max 250 chars min 3")]
        public string Name { get; set; }

        [Required]
        [Display(Name = "Accomodation Description")]
        [StringLength(5000, MinimumLength = 10, ErrorMessage = "Max 5000 chars min 10")]
        public string Description { get; set; }

        [Required]
        [DataType(DataType.Date)]
        [Display(Name="Available From")]
        public DateTime AvailableFrom { get; set; }

        [Required]
        [DataType(DataType.Date)]
        [Display(Name = "Available Until")]
        public DateTime AvailableUntil { get; set; }

        [Required]
        [Display(Name = "Location")]
        [StringLength(5000, MinimumLength = 5, ErrorMessage = "Max 5000 chars min 5")]
        public string Location { get; set; }

        [Required]
        [Display(Name = "Price per night")]
        public double PricePerNight { get; set; }

        /*
         * Um accomodation pode ter varias propertyimages
        */
        public virtual ICollection<AccomodationImage> AccomodationImages { get; set; }

        /*
         * Um accomodation tem uma categoria
        */
        [Required]
        [Display(Name = "Category")]
        public int CategoryId { get; set; }
        public Category Category { get; set; }

        /*
         * Um accomodation tem varias avaliações
         */
        public virtual ICollection<AccomodationRating> AccomodationRatings { get; set; }

        /*
         * um accomodation pode ter varios bookings
         */
        public virtual ICollection<Booking> Bookings { get; set; }


        /*
         * Um accomodation tem um manager
        */
        [Required]
        public int ManagerId { get; set; }
        public Manager Manager { get; set; }

        /*
         * um alojamento é gerido por um empregado
         */
        public int? EmployeeId { get; set; }
        public Employee Employee { get; set; }
    }
}
