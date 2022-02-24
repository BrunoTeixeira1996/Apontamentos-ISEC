using Airbnb.Data;
using Airbnb.Models;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Claims;
using System.Threading.Tasks;

namespace Airbnb.Controllers
{
    public class AccomodationController : Controller
    {
        private readonly ApplicationDbContext _context;

        public AccomodationController(ApplicationDbContext context)
        {
            _context = context;
        }

        [AllowAnonymous]
        public async Task<IActionResult> Index()
        {
            var accomodation = _context.Accomodations.Include(x => x.AccomodationImages);
            return View(await accomodation.ToListAsync());

        }

        [AllowAnonymous]
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var accomodation = await _context.Accomodations
                .Include(e => e.Category)
                .Include(x => x.AccomodationImages)
                .Include(y => y.AccomodationRatings).ThenInclude(c => c.Customer)
                .FirstOrDefaultAsync(m => m.AccomodationId == id);
            if (accomodation == null)
            {
                return NotFound();
            }

            return View(accomodation);
        }
        

        [Authorize(Roles = "Admin, Manager")]
        // GET: Accomodation/Create
        public IActionResult Create()
        {
            ViewData["CategoryId"] = new SelectList(_context.Categories, "CategoryId", "Name");
            return View();
        }

        // POST: Accomodation/Create
        [Authorize(Roles = "Admin, Manager")]
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("AccomodationId,Name,Description,Location,AvailableFrom,AvailableUntil,PricePerNight,CategoryId")] Accomodation accomodation, List<IFormFile> files)
        {
            // atribui alojamento a um manager
            var applicationUserId = User.FindFirstValue(ClaimTypes.NameIdentifier);
            var manager = _context.Managers.Where(x => x.ApplicationUser.Id == applicationUserId).First();
            accomodation.ManagerId = manager.ManagerId;


            if (ModelState.IsValid)
            {
                
                _context.Add(accomodation);

                foreach (var file in files)
                {
                    var fileName = Path.GetFileNameWithoutExtension(file.FileName);
                    var extension = Path.GetExtension(file.FileName);
                    var fileModel = new AccomodationImage
                    {
                        Accomodation = accomodation,
                        CreatedOn = DateTime.UtcNow,
                        FileType = file.ContentType,
                        Extension = extension,
                        Name = fileName,
                    };
                    using (var dataStream = new MemoryStream())
                    {
                        await file.CopyToAsync(dataStream);
                        fileModel.Data = dataStream.ToArray();
                    }
                    _context.AccomodationImages.Add(fileModel);
                }
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }



            ViewData["CategoryId"] = new SelectList(_context.Categories, "CategoryId", "Name", accomodation.CategoryId);

            return View(accomodation);
        }

        [Authorize(Roles = "Admin, Manager")]
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var accomodation = await _context.Accomodations.FindAsync(id);
            if (accomodation == null)
            {
                return NotFound();
            }
            ViewData["CategoryId"] = new SelectList(_context.Categories, "CategoryId", "Name", accomodation.CategoryId);
            return View(accomodation);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        [Authorize(Roles = "Admin, Manager")]
        public async Task<IActionResult> Edit(int id, [Bind("AccomodationId,Name,Description,Location,AvailableFrom,AvailableUntil,PricePerNight,CategoryId,ManagerId")] Accomodation accomodation, List<IFormFile> files)
        {
            if (id != accomodation.AccomodationId)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {

                    foreach (var file in files)
                    {
                        var fileName = Path.GetFileNameWithoutExtension(file.FileName);
                        var extension = Path.GetExtension(file.FileName);
                        var fileModel = new AccomodationImage
                        {
                            Accomodation = accomodation,
                            CreatedOn = DateTime.UtcNow,
                            FileType = file.ContentType,
                            Extension = extension,
                            Name = fileName,
                        };
                        using (var dataStream = new MemoryStream())
                        {
                            await file.CopyToAsync(dataStream);
                            fileModel.Data = dataStream.ToArray();
                        }
                        _context.AccomodationImages.Add(fileModel);
                    }

                    _context.Update(accomodation);
                    await _context.SaveChangesAsync();
                    
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!AccomodationExists(accomodation.AccomodationId))
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
            ViewData["CategoryId"] = new SelectList(_context.Categories, "CategoryId", "Name", accomodation.CategoryId);
            return View(accomodation);
        }


        [Authorize(Roles = "Admin, Manager")]
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var accomodation = await _context.Accomodations
                .Include(p => p.Category)
                .FirstOrDefaultAsync(m => m.AccomodationId == id);
            if (accomodation == null)
            {
                return NotFound();
            }

            return View(accomodation);
        }

        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        [Authorize(Roles = "Admin, Manager")]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var accomodation = await _context.Accomodations.FindAsync(id);
            _context.Accomodations.Remove(accomodation);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        // checks if accomodation exists in db
        private bool AccomodationExists(int id)
        {
            return _context.Accomodations.Any(e => e.AccomodationId == id);
        }

    }
}
