using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Text;

namespace Ficha3.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            
                return Content("<ul>" +
                    "<li>Nome: Programação WEB</li>" +
                    "<li>ECTS: 6</li>" +
                    "<li>Curso: Engenharia Informática</li>" +
                    "<li>Semestre: 5</li>" +
                    "</ul>", "text/html", Encoding.UTF8);
            
        }
    }
}
