using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha3_ex3.Controllers
{
    public class UCsController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    }
}
