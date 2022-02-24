using Airbnb.Data;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Airbnb.Controllers
{
    [Authorize(Roles = "Admin")]
    public class AdminController : Controller
    {
        private readonly ApplicationDbContext _context;

        public AdminController(ApplicationDbContext context)
        {
            _context = context;
        }
        public async Task<IActionResult> Index()
        {
            var accomodation = _context.Accomodations.Include(x => x.AccomodationImages);
            return View(await accomodation.ToListAsync());
        }

        public async Task<IActionResult> ListManagers()
        {
            var managers = _context.Managers.Include(x => x.ApplicationUser);

            return View(await managers.ToListAsync());
        }

        public async Task<IActionResult> ManagerDetails(int? id)
        {
            
            if (id == null)
            {
                return NotFound();
            }

                var manager = await _context.Managers
                    .Include(e => e.ApplicationUser)
                    .Include(a => a.Accomodations)
                    .Include(a => a.Employees)
                    .FirstOrDefaultAsync(m => m.ManagerId == id);
                if (manager == null)
                {
                    return NotFound();
                }

                return View(manager);
        }

        public async Task<IActionResult> ListCustomers()
        {
            var customers = _context.Customers.Include(x => x.ApplicationUser);

            return View(await customers.ToListAsync());
        }
    }
}