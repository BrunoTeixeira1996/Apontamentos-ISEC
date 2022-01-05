using System;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata;

#nullable disable

namespace DBFirst_Exemplo.Models
{
    public partial class MyDBContext : DbContext
    {
        public MyDBContext()
        {
        }

        public MyDBContext(DbContextOptions<MyDBContext> options)
            : base(options)
        {
        }

        public virtual DbSet<Noticia> Noticias { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see http://go.microsoft.com/fwlink/?LinkId=723263.
                optionsBuilder.UseSqlServer("Server=(localdb)\\MSSQLLocalDB;Database=C:\\USERS\\BRUN0\\DESKTOP\\PWEB\\PRATICAS\\FICHA6\\DBFIRST_EXEMPLO\\DBFIRST_EXEMPLO\\APP_DATA\\DBEXEMPLO.MDF");
            }
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.HasAnnotation("Relational:Collation", "SQL_Latin1_General_CP1_CI_AS");

            modelBuilder.Entity<Noticia>(entity =>
            {
                entity.Property(e => e.Data)
                    .HasColumnType("datetime")
                    .HasDefaultValueSql("(getdate())");

                entity.Property(e => e.Descricao)
                    .IsRequired()
                    .IsUnicode(false);

                entity.Property(e => e.Titulo)
                    .IsRequired()
                    .HasMaxLength(255)
                    .IsUnicode(false);
            });

            OnModelCreatingPartial(modelBuilder);
        }

        partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
    }
}
