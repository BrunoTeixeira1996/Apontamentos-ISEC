using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Ficha3_ex4.Data;
using Ficha3_ex4.Models;

namespace Ficha3_ex4.Controllers
{
    public class UCsController : Controller
    {
        private readonly ApplicationDbContext _context;

        public UCsController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: UCs
        public async Task<IActionResult> Index()
        {
            return View(await _context.UCs.ToListAsync());
        }

        // GET: UCs/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var uCs = await _context.UCs
                .FirstOrDefaultAsync(m => m.Id == id);
            if (uCs == null)
            {
                return NotFound();
            }

            return View(uCs);
        }

        // GET: UCs/Create
        public IActionResult Create()
        {
            return View();
        }

        // POST: UCs/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Id,Nome,ECTS,Licenciatura,Ramo,Semestre")] UCs uCs)
        {
            if (ModelState.IsValid)
            {
                _context.Add(uCs);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            return View(uCs);
        }

        // GET: UCs/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var uCs = await _context.UCs.FindAsync(id);
            if (uCs == null)
            {
                return NotFound();
            }
            return View(uCs);
        }

        // POST: UCs/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Id,Nome,ECTS,Licenciatura,Ramo,Semestre")] UCs uCs)
        {
            if (id != uCs.Id)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(uCs);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!UCsExists(uCs.Id))
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
            return View(uCs);
        }

        // GET: UCs/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var uCs = await _context.UCs
                .FirstOrDefaultAsync(m => m.Id == id);
            if (uCs == null)
            {
                return NotFound();
            }

            return View(uCs);
        }

        // POST: UCs/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var uCs = await _context.UCs.FindAsync(id);
            _context.UCs.Remove(uCs);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool UCsExists(int id)
        {
            return _context.UCs.Any(e => e.Id == id);
        }
    }
}
