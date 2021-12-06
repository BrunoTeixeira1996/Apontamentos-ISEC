using Ficha_4.App_Data;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha_4.Controllers
{
    public class ConversorController : Controller
    {
        public IActionResult Index()
        {
            var xxxx = DadosExemplo.UnidadesMonetarias.Select(u => new SelectListItem { Value = u.Id.ToString(), Text = u.Codigo }).ToList();
            ViewBag.ListaDeMoedas = new SelectList(xxxx);

            return View();
        }
    }
}
