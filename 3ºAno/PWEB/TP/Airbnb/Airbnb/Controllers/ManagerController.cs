using Airbnb.Data;
using Airbnb.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Claims;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc.Rendering;

namespace Airbnb.Controllers
{
    [Authorize(Roles = "Admin,Manager,Employee")]
    public class ManagerController : Controller
    {
        private readonly ApplicationDbContext _context;
        private readonly UserManager<ApplicationUser> _userManager;


        public ManagerController(ApplicationDbContext context, UserManager<ApplicationUser> userManager)
        {
            _context = context;
            _userManager = userManager;
        }

        public async Task<IActionResult> ListAccomodations()
        {
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);
            var manager = _context.Managers.Where(x => x.ApplicationUser.Id == applicationUserId).First();

            
            var accomodations = _context.Accomodations.Where(p => p.ManagerId == manager.ManagerId)
                                .Include(x => x.AccomodationImages);

            return View(await accomodations.ToListAsync());
        }
       
        public async Task<IActionResult> ListEmployees()
        {
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);
            var manager = _context.Managers.Where(x => x.ApplicationUser.Id == applicationUserId).First();

            var employees = _context.Employees.Where(p => p.ManagerId == manager.ManagerId)
                            .Include(x => x.ApplicationUser);

            return View(await employees.ToListAsync());
        }

        public IActionResult EmployeeToAccomodation()
        {
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);
            var manager = _context.Managers.Where(x => x.ApplicationUser.Id == applicationUserId).First();
            var accomodations = _context.Accomodations.Where(p => p.ManagerId == manager.ManagerId).ToList();

            ViewData["AccomodationId"] = new SelectList(accomodations, "AccomodationId", "Name");


            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> EmployeeToAccomodation(int? id,[Bind("AccomodationId")] Accomodation accomodation)
        {

            // se o id nao for passado
            if (id == null)
                return RedirectToAction(nameof(ListEmployees));

            var acc = _context.Accomodations.Where(i => i.AccomodationId == accomodation.AccomodationId).First();

            // se nao existir alojamentos com um certo id
            if(acc == null)
                return RedirectToAction(nameof(ListEmployees));

            // caso contrario, damos update ao EmployeeId do Accomodations
            acc.EmployeeId = (int)id;

            // ver se este alojamento tem algum booking e se tiver e o booking.employeeId estiver a nulo
            // usa-se o employee que esta a ser atribuido
            var booking = _context.Bookings.Where(b => b.AccomodationId == accomodation.AccomodationId);
            foreach(var i in booking)
            {
                if (i.EmployeeId == null)
                    i.EmployeeId = acc.EmployeeId;
            }

            await _context.SaveChangesAsync();

            return RedirectToAction(nameof(ListEmployees));
        }


        public IActionResult RemoveAccomodationFromEmployee()
        {
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);
            var manager = _context.Managers.Where(x => x.ApplicationUser.Id == applicationUserId).First();
            var accomodations = _context.Accomodations.Where(p => p.ManagerId == manager.ManagerId);

            ViewData["AccomodationId"] = new SelectList(accomodations, "AccomodationId", "Name");


            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> RemoveAccomodationFromEmployee(int? id,[Bind("AccomodationId")] Accomodation accomodation)
        {

            // se o id nao for passado
            if (id == null)
                return RedirectToAction(nameof(ListEmployees));

            var acc = _context.Accomodations.Where(i => i.AccomodationId == id).First();

            // se nao existir alojamentos com um certo id
            if(acc == null)
                return RedirectToAction(nameof(ListEmployees));

            // caso contrario, metemos o EmployeeId a null
            acc.EmployeeId = null;
            
            await _context.SaveChangesAsync();

            return RedirectToAction(nameof(ListEmployees));
        }

        // GET: Managers/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var manager = await _context.Managers
                .FirstOrDefaultAsync(m => m.ManagerId == id);
            if (manager == null)
            {
                return NotFound();
            }

            return View(manager);
        }

        // POST: Managers/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            // pesquisar na tabela de Managers o ApplicationUserId e remove esse manager
            var app = _context.Managers.Where(x => x.ManagerId == id).Include(x => x.ApplicationUser).First();
            var appuser = app.ApplicationUser;
            await _userManager.DeleteAsync(appuser);

            var manager = await _context.Managers.FindAsync(id);
            _context.Managers.Remove(manager);
            await _context.SaveChangesAsync();
            return RedirectToAction("ListManagers", "Admin");
        }
    }
}
