using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Airbnb.Data;
using Airbnb.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using System.Security.Claims;

namespace Airbnb.Controllers
{
    [Authorize(Roles = "Admin, Manager,Employee")]
    public class EmployeesController : Controller
    {
        private readonly ApplicationDbContext _context;
        private readonly UserManager<ApplicationUser> _userManager;


        public EmployeesController(ApplicationDbContext context, UserManager<ApplicationUser> userManager)
        {
            _context = context;
            _userManager = userManager;

        }


        // GET: Employees/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var employee = await _context.Employees
                .Include(e => e.Manager.ApplicationUser)
                .Include(a => a.Bookings).ThenInclude(a => a.Accomodation)
                .Include(a => a.ApplicationUser)
                .Include(a => a.Accomodations)
                .FirstOrDefaultAsync(m => m.EmployeeId == id);
            if (employee == null)
            {
                return NotFound();
            }

            return View(employee);
        }


        // GET: Employees/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var employee = await _context.Employees
                .Include(e => e.ApplicationUser)
                .FirstOrDefaultAsync(m => m.EmployeeId == id);
            if (employee == null)
            {
                return NotFound();
            }

            return View(employee);
        }

        // POST: Employees/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            // coloca o EmployeesFK a nulo no Accomodation
            var acc = await _context.Accomodations.Where(x => x.EmployeeId == id).ToListAsync();
            if (acc.Count != 0)
            {
                foreach (var x in acc)
                    x.EmployeeId = null;
            }

            // pesquisar na tabela de Employees o ApplicationUserId e remove esse empregado
            var app = _context.Employees.Where(x => x.EmployeeId == id).Include(x => x.ApplicationUser).First();
            var appuser = app.ApplicationUser;
            await _userManager.DeleteAsync(appuser);

            // removo o empregado da tabela Employee
            var employee = await _context.Employees.FindAsync(id);
            _context.Employees.Remove(employee);

            await _context.SaveChangesAsync();

            return RedirectToAction("ListEmployees", "Manager");
        }

        private bool EmployeeExists(int id)
        {
            return _context.Employees.Any(e => e.EmployeeId == id);
        }

       [Authorize(Roles = "Employee")]
        public async Task<IActionResult> ManageBookings()
        {
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);

            var employee = _context.Employees.Where(x => x.ApplicationUser.Id == applicationUserId).FirstOrDefault();

            var acc = _context.Accomodations.Where(x => x.EmployeeId == employee.EmployeeId).FirstOrDefault();

            bool flag = true;

            if (acc == null)
            {
                ViewData["flag"] = false;
                return View();
            }
            else
            {
                ViewData["flag"] = flag;

                var bookings = _context.Bookings.Where(p => p.Employee.EmployeeId == employee.EmployeeId)
                                .Include(b => b.Accomodation)
                                .Include(b => b.Customer)
                                .Include(b => b.Customer.ApplicationUser);

                return View(await bookings.ToListAsync());
            }
                

            
        }

        [Authorize(Roles = "Employee")]
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> ManageBookingsAccept([Bind("BookingId,BookingFrom,BookingUntil,AccomodationId,CustomerId")] Booking booking)
        {
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);

            var employee = _context.Employees.Where(x => x.ApplicationUser.Id == applicationUserId).FirstOrDefault();

            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Description", booking.AccomodationId);

            if (String.Compare(booking.Status, "Booking Accepted") != 0)
            {
                booking.Status = "Booking Accepted";
                booking.EmployeeId = employee.EmployeeId;
                _context.Update(booking);
                await _context.SaveChangesAsync();
            }
            return RedirectToAction(nameof(ManageBookings));
        }

        [Authorize(Roles = "Employee")]
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> ManageBookingsRefuse([Bind("BookingId,BookingFrom,BookingUntil,AccomodationId,CustomerId")] Booking booking)
        {
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);

            var employee = _context.Employees.Where(x => x.ApplicationUser.Id == applicationUserId).FirstOrDefault();

            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Description", booking.AccomodationId);

            if (String.Compare(booking.Status, "Booking Declined") != 0)
            {
                booking.Status = "Booking Declined";
                booking.EmployeeId = employee.EmployeeId;
                _context.Update(booking);
                await _context.SaveChangesAsync();
            }

            return RedirectToAction(nameof(ManageBookings));
        }
    }
}
