using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Text;


namespace Ficha3.Controllers
{
    public class UCsController : Controller
    {
        public IActionResult Index()
        {
            return Content("<ul>" +
                   "<li>Estratégia Organizacional</li>" +
                   "<li>Arquiteruras Móveis</li>" +
                   "<li>Programação Distribuida</li>" +
                   "<li>Inteligência Computacional</li>" +
                   "</ul>", "text/html", Encoding.UTF8);
        }
    }
}
