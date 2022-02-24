using Airbnb.Data;
using Airbnb.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using System.Threading.Tasks;

namespace Airbnb.Controllers
{
    [Authorize(Roles = "Admin,Customer")]
    public class CustomerController : Controller
    {
        private readonly ApplicationDbContext _context;
        private readonly UserManager<ApplicationUser> _userManager;


        public CustomerController(ApplicationDbContext context, UserManager<ApplicationUser> userManager)
        {
            _context = context;
            _userManager = userManager;

        }

        public async Task<IActionResult> ListBookings()
        {
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);
            var customer = _context.Customers.Where(x => x.ApplicationUser.Id == applicationUserId).First();

            var bookings = _context.Bookings.Where(p => p.CustomerId == customer.CustomerId);

            return View(await bookings.ToListAsync());
        }

        public async Task<IActionResult> ListRatings()
        {
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);
            var customer = _context.Customers.Where(x => x.ApplicationUser.Id == applicationUserId).First();

            var ratings = _context.AccomodationRatings.Where(p => p.CustomerId == customer.CustomerId);

            return View(await ratings.ToListAsync());
        }

        // GET: Customers/Details/5
        public IActionResult Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }


            var customer = _context.Customers.Where(x => x.CustomerId == id).Include(a => a.ApplicationUser).First();
            var ratings = _context.AccomodationRatings.Where(p => p.CustomerId == customer.CustomerId);
            var bookings = _context.Bookings.Where(p => p.CustomerId == customer.CustomerId).Include(x => x.Accomodation);

            var viewmodel = new CustomerViewModel
            {
                AccomodationRatings = ratings,
                Customer = customer,
                Bookings = bookings
            };


            if (customer == null)
            {
                return NotFound();
            }

            return View(viewmodel);
        }

        // GET: Customers/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var customer = await _context.Customers
                .FirstOrDefaultAsync(m => m.CustomerId == id);
            if (customer == null)
            {
                return NotFound();
            }

            return View(customer);
        }

        // POST: Customers/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            // pesquisar na tabela de customers o ApplicationUserId e remove esse customer
            var app = _context.Customers.Where(x => x.CustomerId == id).Include(x => x.ApplicationUser).First();
            var appuser = app.ApplicationUser;
            await _userManager.DeleteAsync(appuser);

            var customer = await _context.Customers.FindAsync(id);
            _context.Customers.Remove(customer);
            await _context.SaveChangesAsync();
            return RedirectToAction("ListCustomers", "Admin");
        }

    }
}
