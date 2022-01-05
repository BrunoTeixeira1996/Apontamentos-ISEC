using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using Ficha6.Models;
using X.PagedList;

namespace Ficha6.Controllers
{
    public class ProdutoesController : Controller
    {
        private readonly MyDBContext _context;

        public ProdutoesController(MyDBContext context)
        {
            _context = context;
        }

        // GET: Produtoes
        /*COM ORDENACAO*/

        /*
        public async Task<IActionResult> Index(int? id, string ordenacao)
        {
            var lista_produtos = _context.Produtos.Include(p => p.IdCategoriaNavigation);

            var lista = lista_produtos.GroupBy(e => e.IdCategoria).
                        Select(x => new CategoriaComContagem() {
                            IdCategoria = x.Key, 
                            QuantProdutos = x.Count(), 
                            Nome = _context.Categorias.
                            FirstOrDefault(c => c.IdCategoria == x.Key).NomeCategoria
                        });


            ViewData["IdCategoria"] = new SelectList(lista, "IdCategoria", "NomeComQuantidade");

            var opcoesDeOrdenacao = new List<Ordenacao>() {
                new Ordenacao{Valor="ASC", Texto="Preco Ascendente" },
                new Ordenacao{Valor="DESC", Texto="Preco Descendente" }
            }

            ViewData["Ordenacao"] = new SelectList(opcoesDeOrdenacao, "Valor","Texto");

            //ViewData["IdCategoria"] = new SelectList(_context.Categorias, "IdCategoria", "NomeCategoria");

            // se o utilizador escolher uma categoria
            if (id != null){
                if (ordenacao == "desc")
                {
                    return View(await lista_produtos.Where(x => x.IdCategoria == id)
                        .OrderByDescending(p => p.Preco).
                        ToListAsync());
                }
                else
                {
                    return View(await lista_produtos.Where(x => x.IdCategoria == id)
                        .OrderBy(p => p.Preco).
                        ToListAsync());
                }

                return View(await lista_produtos.Where(x => x.IdCategoria == id).ToListAsync());
            }

            if (id == null) // se o utilizador não escolher uma categoria
            {
                if(ordenacao == "desc")
                {
                    return View(await lista_produtos.OrderByDescending(c => c.Preco).ToListAsync());
                }
                else
                {
                    return View(await lista_produtos.OrderBy(c => c.Preco).ToListAsync());

                }
                return View(await lista_produtos.ToListAsync());
            }
            
        }
        */

        /* SEM ORDENACAO*/
        /*
        public async Task<IActionResult> Index(int? id)
        {
            var lista_produtos = _context.Produtos.Include(p => p.IdCategoriaNavigation);

            var lista = lista_produtos.GroupBy(e => e.IdCategoria).
                        Select(x => new CategoriaComContagem()
                        {
                            IdCategoria = x.Key,
                            QuantProdutos = x.Count(),
                            Nome = _context.Categorias.FirstOrDefault(c => c.IdCategoria == x.Key).NomeCategoria
                        });


            ViewData["IdCategoria"] = new SelectList(lista, "IdCategoria", "NomeComQuantidade");


             
            // se o utilizador escolher uma categoria
            if (id != null)
            { 

                return View(await lista_produtos.Where(x => x.IdCategoria == id).ToListAsync());
            }


                return View(await lista_produtos.ToListAsync());

        }
        */
        public async Task<IActionResult> ProdutosPorPagina(int? id, int? pagina)
        {
            var lista_produtos = _context.Produtos.Include(p => p.IdCategoriaNavigation);

            var lista = lista_produtos.GroupBy(e => e.IdCategoria).
                        Select(x => new CategoriaComContagem()
                        {
                            IdCategoria = x.Key,
                            QuantProdutos = x.Count(),
                            Nome = _context.Categorias.FirstOrDefault(c => c.IdCategoria == x.Key).NomeCategoria
                        });

            if (pagina == null)
                pagina = 1;

            ViewData["IdCategoria"] = new SelectList(lista, "IdCategoria", "NomeComQuantidade");
            ViewData["TotalProdutos"] = lista_produtos.Count();

            // se o utilizador escolher uma categoria
            if (id != null)
            {

                return View(await lista_produtos.Where(x => x.IdCategoria == id).ToListAsync());
            }

            return View(await lista_produtos.ToPagedListAsync(pagina,2));

        }


        // GET: Produtoes/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var produto = await _context.Produtos
                .Include(p => p.IdCategoriaNavigation)
                .FirstOrDefaultAsync(m => m.IdProduto == id);
            if (produto == null)
            {
                return NotFound();
            }

            return View(produto);
        }

        // GET: Produtoes/Create
        public IActionResult Create()
        {
            ViewData["IdCategoria"] = new SelectList(_context.Categorias, "IdCategoria", "NomeCategoria");
            return View();
        }

        // POST: Produtoes/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("IdProduto,NomeProduto,IdCategoria")] Produto produto)
        {
            if (ModelState.IsValid)
            {
                _context.Add(produto);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            ViewData["IdCategoria"] = new SelectList(_context.Categorias, "IdCategoria", "NomeCategoria", produto.IdCategoria);
            return View(produto);
        }

        // GET: Produtoes/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var produto = await _context.Produtos.FindAsync(id);
            if (produto == null)
            {
                return NotFound();
            }
            ViewData["IdCategoria"] = new SelectList(_context.Categorias, "IdCategoria", "NomeCategoria", produto.IdCategoria);
            return View(produto);
        }

        // POST: Produtoes/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("IdProduto,NomeProduto,IdCategoria")] Produto produto)
        {
            if (id != produto.IdProduto)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(produto);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!ProdutoExists(produto.IdProduto))
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
            ViewData["IdCategoria"] = new SelectList(_context.Categorias, "IdCategoria", "NomeCategoria", produto.IdCategoria);
            return View(produto);
        }

        // GET: Produtoes/Delete/5
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var produto = await _context.Produtos
                .Include(p => p.IdCategoriaNavigation)
                .FirstOrDefaultAsync(m => m.IdProduto == id);
            if (produto == null)
            {
                return NotFound();
            }

            return View(produto);
        }

        // POST: Produtoes/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var produto = await _context.Produtos.FindAsync(id);
            _context.Produtos.Remove(produto);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        private bool ProdutoExists(int id)
        {
            return _context.Produtos.Any(e => e.IdProduto == id);
        }
    }
}
