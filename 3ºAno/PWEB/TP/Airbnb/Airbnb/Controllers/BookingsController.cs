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
    [Authorize(Roles = "Admin,Customer,Employee")]
    public class BookingsController : Controller
    {
        private readonly ApplicationDbContext _context;

        public BookingsController(ApplicationDbContext context)
        {
            _context = context;
        }


        // GET: Bookings
        public async Task<IActionResult> Index()
        {
            var applicationDbContext = _context.Bookings.Include(b => b.Accomodation);
            return View(await applicationDbContext.ToListAsync());
        }



        // GET: Bookings/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var booking = await _context.Bookings
                .Include(b => b.Accomodation)
                .FirstOrDefaultAsync(m => m.BookingId == id);
            if (booking == null)
            {
                return NotFound();
            }

            return View(booking);
        }

        // GET: Bookings/Create
        public IActionResult Create()
        {
            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Description");
            return View();
        }

        // POST: Bookings/Create
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("BookingId,BookingFrom,BookingUntil,AccomodationId")] Booking booking)
        {
            if (ModelState.IsValid)
            {

                _context.Add(booking);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Description", booking.AccomodationId);
            return View(booking);
        }

        // GET: Bookings/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var booking = await _context.Bookings.FindAsync(id);
            if (booking == null)
            {
                return NotFound();
            }
            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Name", booking.AccomodationId);
            return View(booking);
        }

        // POST: Bookings/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("BookingId,BookingFrom,BookingUntil,AccomodationId")] Booking booking)
        {
            if (id != booking.BookingId)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(booking);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!BookingExists(booking.BookingId))
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
            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Name", booking.AccomodationId);
            return View(booking);
        }

        [Authorize(Roles = "Admin,Employee,Customer")]
        // GET: Bookings/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var booking = await _context.Bookings
                .Include(b => b.Accomodation)
                .FirstOrDefaultAsync(m => m.BookingId == id);
            if (booking == null)
            {
                return NotFound();
            }

            return View(booking);
        }

        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        [Authorize(Roles = "Admin,Employee,Customer")]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);
            var customer = _context.Customers.Where(x => x.ApplicationUser.Id == applicationUserId).FirstOrDefault();

            var booking = await _context.Bookings.FindAsync(id);
            _context.Bookings.Remove(booking);
            await _context.SaveChangesAsync();

            if (customer != null)
                return RedirectToAction("ListBookings", "Customer");
            else
                return RedirectToAction("ManageBookings","Employees");
        }

        private bool BookingExists(int id)
        {
            return _context.Bookings.Any(e => e.BookingId == id);
        }


        [Authorize(Roles = "Customer")]
        public IActionResult CreateFromDetails()
        {
            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Description");
            return View();
        }

        [Authorize(Roles = "Customer")]
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> CreateFromDetails(int id, [Bind("BookingId,BookingFrom,BookingUntil,AccomodationId")] Booking booking)
        {
            

            ViewData["AccomodationId"] = new SelectList(_context.Accomodations, "AccomodationId", "Description", booking.AccomodationId);

            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);
            var customer = _context.Customers.Where(x => x.ApplicationUser.Id == applicationUserId).First();
            

            booking.AccomodationId = id;
            booking.CustomerId = customer.CustomerId;

            // ver qual é o empregado responsavel pelo alojamento e atribuir esse id ao booking.EmployeeId
            // se nao for nenhum fica a null, se existir, o booking.Employee.EmployeeId = acc.EmployeeId
            var acc = _context.Accomodations.Where(p => p.AccomodationId == booking.AccomodationId).FirstOrDefault();
            if (acc.EmployeeId != null)
                booking.EmployeeId = (int)acc.EmployeeId;


            // verifica se a reserva é ou nao válida
            if (IsValidReservation(booking))
            {
                _context.Add(booking);
                await _context.SaveChangesAsync();
                return RedirectToAction("ListBookings","Customer");
            }

            return View("ErrorTest");
            
        }


        private bool IsValidReservation(Booking booking)
        {

            var accomodation_result = _context.Accomodations.Where(x => x.AccomodationId == booking.AccomodationId).First();
            var list_of_reservations = _context.Bookings.Where(x => x.AccomodationId == booking.AccomodationId);
            int counter = 0;


            var from = DateTime.Compare(accomodation_result.AvailableFrom,booking.BookingFrom);
            var until = DateTime.Compare(accomodation_result.AvailableUntil, booking.BookingUntil);

            /*Está dentro dos limites*/
            if (from <= 0 && until >= 0)
            {
                /*Verificar se já existe essa reserva e se reserva é valida*/

                foreach (var last_checkout in list_of_reservations)
                {
                    /*Verifica se a data escolhida "até" é superior à data escolhida "desde"*/
                    if (DateTime.Compare(booking.BookingUntil, booking.BookingFrom) > 0)
                    {
                        /*Se data escolhida "desde"  < data da reserva atual "até" e data escolhida "até" > data da reserva atual "desde" é porque não é válida*/
                        if (DateTime.Compare(booking.BookingFrom, last_checkout.BookingUntil) < 0 && DateTime.Compare(booking.BookingUntil, last_checkout.BookingFrom) > 0)
                        {
                            /* 
                             * caso de erro 
                             */
                            break;
                        }
                        counter++;
                    }
                }
            }

            if (list_of_reservations.Count() == counter)
                return true;

            return false;
        }
    }
}
