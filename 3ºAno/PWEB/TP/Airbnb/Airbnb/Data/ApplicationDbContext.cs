using Airbnb.Models;
using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Text;

namespace Airbnb.Data
{
    public class ApplicationDbContext : IdentityDbContext<ApplicationUser>
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options)
        {
        }
        public DbSet<Admin> Admins { get; set; }
        public DbSet<Accomodation> Accomodations { get; set; }
        public DbSet<AccomodationImage> AccomodationImages { get; set; }
        public DbSet<Category> Categories { get; set; }
        public DbSet<AccomodationRating> AccomodationRatings { get; set; }
        public DbSet<Booking> Bookings { get; set; }
        public DbSet<Manager> Managers { get; set; }
        public DbSet<Customer> Customers { get; set; }
        public DbSet<Employee> Employees { get; set; }       
    }
}
