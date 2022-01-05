using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Text;
using Ficha8.Models;

namespace Ficha8.Data
{
    public class ApplicationDbContext : IdentityDbContext<ApplicationUser>
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options)
        {
        }

        public DbSet<Categoria> Categorias { get; set; }
        public DbSet<Produto> Produtos { get; set; }

        public DbSet<FilesOnDatabase> FilesOnDatabases { get; set; }
        public DbSet<FilesOnFileSystem> FilesOnFileSystems { get; set; }
        public object FilesOnDatabase { get; internal set; }
    }
}
