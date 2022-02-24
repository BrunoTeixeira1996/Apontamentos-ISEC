using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Airbnb.Data;
using Airbnb.Models;
using System.Security.Claims;
using Microsoft.AspNetCore.Authorization;

namespace Airbnb.Controllers
{
    public class AccomodationRatingsController : Controller
    {
        private readonly ApplicationDbContext _context;

        public AccomodationRatingsController(ApplicationDbContext context)
        {
            _context = context;
        }

        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> Index()
        {
            var applicationDbContext = _context.AccomodationRatings.Include(a => a.Accomodation).Include(a => a.Customer)
                .Include(a => a.Customer.ApplicationUser);
            return View(await applicationDbContext.ToListAsync());
        }

        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var accomodationRating = await _context.AccomodationRatings
                .Include(a => a.Accomodation)
                .Include(a => a.Customer.ApplicationUser)
                .FirstOrDefaultAsync(m => m.AccomodationRatingId == id);
            if (accomodationRating == null)
            {
                return NotFound();
            }

            return View(accomodationRating);
        }


        [Authorize(Roles = "Admin")]
        public IActionResult Create()
        {
            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Description");
            return View();
        }

        [Authorize(Roles = "Admin")]
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("AccomodationRatingId,Comment,AccomodationId")] AccomodationRating accomodationRating)
        {
            if (ModelState.IsValid)
            {
                _context.Add(accomodationRating);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Description", accomodationRating.AccomodationId);
            return View(accomodationRating);
        }

        [Authorize(Roles = "Customer")]
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> CreateFromDetails([Bind("AccomodationRatingId,Comment,AccomodationId")] AccomodationRating accomodationRating)
        {
            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Description", accomodationRating.AccomodationId);
            
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);
            var customer = _context.Customers.Where(x => x.ApplicationUser.Id == applicationUserId).First();

            accomodationRating.CustomerId = customer.CustomerId;
            _context.Add(accomodationRating);
            await _context.SaveChangesAsync();


            return RedirectToAction("Details", "Accomodation", new { id = accomodationRating.AccomodationId.ToString() });

        }

        [Authorize(Roles = "Admin")]
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var accomodationRating = await _context.AccomodationRatings.FindAsync(id);
            if (accomodationRating == null)
            {
                return NotFound();
            }
            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Description", accomodationRating.AccomodationId);
            return View(accomodationRating);
        }

        [Authorize(Roles = "Admin")]
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("AccomodationRatingId,Comment,AccomodationId")] AccomodationRating accomodationRating)
        {
            if (id != accomodationRating.AccomodationRatingId)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(accomodationRating);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!AccomodationRatingExists(accomodationRating.AccomodationRatingId))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Index));
            }
            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Description", accomodationRating.AccomodationId);
            return View(accomodationRating);
        }

        [Authorize(Roles = "Admin,Customer")]
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var accomodationRating = await _context.AccomodationRatings
                .Include(a => a.Accomodation)
                .FirstOrDefaultAsync(m => m.AccomodationRatingId == id);
            if (accomodationRating == null)
            {
                return NotFound();
            }

            return View(accomodationRating);
        }

        [Authorize(Roles = "Admin,Customer")]
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var accomodationRating = await _context.AccomodationRatings.FindAsync(id);
            _context.AccomodationRatings.Remove(accomodationRating);
            await _context.SaveChangesAsync();
            return RedirectToAction("ListRatings","Customer");
        }

        private bool AccomodationRatingExists(int id)
        {
            return _context.AccomodationRatings.Any(e => e.AccomodationRatingId == id);
        }
    }
}
