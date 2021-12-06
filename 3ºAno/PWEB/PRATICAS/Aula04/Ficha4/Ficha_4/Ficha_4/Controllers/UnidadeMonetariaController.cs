using Ficha_4.App_Data;
using Ficha_4.Models;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Ficha_4.Controllers
{
    public class UnidadeMonetariaController : Controller
    {

        public IActionResult Index()
        {

            /*
            if (ListaDeUnidadesMonetarias.Count == 0)
            {
                ListaDeUnidadesMonetarias.Add(
                new UnidadeMonetaria { Codigo = "EUR", ValorPorEuro = 1, Id = 0 , Data=DateTime.Now}
                );
                ListaDeUnidadesMonetarias.Add(
                    new UnidadeMonetaria { Codigo = "USD", ValorPorEuro = 0.89, Id = 1, Data = DateTime.Now }
                    );
                ListaDeUnidadesMonetarias.Add(
                    new UnidadeMonetaria { Codigo = "JPY", ValorPorEuro = 0.077, Id = 2, Data = DateTime.Now }
                );
            }
            */

            /* esta vista está à espera de uma ListaDeUnidadesMonetarias que é
             * um enumerable que está no Index.cshtml
             */
            //return View("Listar",ListaDeUnidadesMonetarias);
            return View("Listar", DadosExemplo.UnidadesMonetarias);
        }

        //GET
        public IActionResult Create()
        {
            return View();
        }

        //POST
        [HttpPost]
        public IActionResult Create(IFormCollection collection)
        {
            UnidadeMonetaria um = new UnidadeMonetaria
            {
                Codigo = collection["Codigo"],
                ValorPorEuro = Double.Parse(collection["ValorPorEuro"]),
                Data = DateTime.Now,
                Id = DadosExemplo.GetId()
        };
            DadosExemplo.UnidadesMonetarias.Add(um);

            return View("Listar", DadosExemplo.UnidadesMonetarias);
        }

        //GET
        public IActionResult Details(int? id)
        {
            if (id == null)
                return RedirectToAction("Index"); // O método Index é que redireciona para a vista que eu quero

            var um = DadosExemplo.UnidadesMonetarias.FirstOrDefault(u => u.Id == id);

            return View(um);
        }
        
        //GET
        public IActionResult Edit(int? id)
        {
            if (id == null)
                return RedirectToAction("Index"); // O método Index é que redireciona para a vista que eu quero

            var um = DadosExemplo.UnidadesMonetarias.FirstOrDefault(u => u.Id == id);

            return View(um);
        }

        //POST
        [HttpPost]
        public IActionResult Edit(int? id, IFormCollection collection)
        {
            // verificamos se o Id existe
            if (id == null)
                return RedirectToAction("Index"); // O método Index é que redireciona para a vista que eu quero

            // tentamos encontrar o objeto da lista que queremos editar
            var um = DadosExemplo.UnidadesMonetarias.FirstOrDefault(u => u.Id == id);

            // se "um" for nulo entao nao existe o objeto
            if (um == null)
                return RedirectToAction("Index");

            // se existir alteramos o código e o valor por euro
            um.Codigo = collection["Codigo"];
            um.ValorPorEuro = Double.Parse(collection["ValorPorEuro"]);

            return View("Listar", DadosExemplo.UnidadesMonetarias);
        }

        //GET
        public IActionResult Delete(int? id)
        {
            // verificamos se o Id existe
            if (id == null)
                return RedirectToAction("Index"); // O método Index é que redireciona para a vista que eu quero

            var um = DadosExemplo.UnidadesMonetarias.FirstOrDefault(u => u.Id == id);

            return View(um);
        }

        //POST
        [HttpPost]
        public IActionResult Delete(int? id, IFormCollection collection)
        {
            // verificamos se o Id existe
            if (id == null)
                return RedirectToAction("Index"); // O método Index é que redireciona para a vista que eu quero

            // tentamos encontrar o objeto da lista que queremos eliminar
            var um = DadosExemplo.UnidadesMonetarias.FirstOrDefault(u => u.Id == id);

            // se "um" nao for nulo entao removemos
            if (um != null)
                DadosExemplo.UnidadesMonetarias.Remove(um);

            return RedirectToAction("Index");
        }

    }
}
