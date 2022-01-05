using Ficha8.Models;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha8.Controllers
{
    public class RolesController : Controller
    {
        RoleManager<IdentityRole> roleManager;
        UserManager<ApplicationUser> userManager;

        public RolesController(RoleManager<IdentityRole> roleManager, UserManager<ApplicationUser> userManager)
        {
            this.roleManager = roleManager;
            this.userManager = userManager;
        }

        public IActionResult Index()
        {
            return View(roleManager.Roles.ToList());
        }

        public IActionResult Create()
        {
            return View();
        }

        [HttpPost]
        public async Task<IActionResult> Create(IdentityRole role)
        {
            await roleManager.CreateAsync(role);

            return RedirectToAction(nameof(Index));
        }

        public async Task<IActionResult> Detalhes(string id)
        {
            var role = roleManager.FindByIdAsync(id);
            if (role != null)
            {
                // vai buscar todos os users que estao numa determinada role
                var listaDeUtilizadores = await userManager.GetUsersInRoleAsync(role.Result.Name);

                // cria o novo object
                RoleViewModel rvm = new RoleViewModel
                {
                    Id = role.Result.Id,
                    Nome = role.Result.Name,
                    Utilizadores = listaDeUtilizadores
                };
                return View(role);
            }
                
            else
                return RedirectToAction(nameof(Index));
        }
    }
}
