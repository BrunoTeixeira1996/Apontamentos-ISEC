using System;
using Microsoft.EntityFrameworkCore.Migrations;

namespace Ficha8.Data.Migrations
{
    public partial class Adicionadodatadeembalamentoedatadevalidadenosprodutos : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<DateTime>(
                name: "DataEmbalamento",
                table: "Produtos",
                type: "datetime2",
                nullable: false,
                defaultValue: new DateTime(1, 1, 1, 0, 0, 0, 0, DateTimeKind.Unspecified));

            migrationBuilder.AddColumn<DateTime>(
                name: "DataValidade",
                table: "Produtos",
                type: "datetime2",
                nullable: false,
                defaultValue: new DateTime(1, 1, 1, 0, 0, 0, 0, DateTimeKind.Unspecified));
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "DataEmbalamento",
                table: "Produtos");

            migrationBuilder.DropColumn(
                name: "DataValidade",
                table: "Produtos");
        }
    }
}
