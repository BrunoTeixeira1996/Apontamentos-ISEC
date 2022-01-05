using Microsoft.EntityFrameworkCore.Migrations;

namespace Ficha8.Data.Migrations
{
    public partial class ModelsComFicheirosDone : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.RenameColumn(
                name: "CreatedData",
                table: "FilesOnFileSystems",
                newName: "CreatedOn");

            migrationBuilder.RenameColumn(
                name: "CreatedData",
                table: "FilesOnDatabases",
                newName: "CreatedOn");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.RenameColumn(
                name: "CreatedOn",
                table: "FilesOnFileSystems",
                newName: "CreatedData");

            migrationBuilder.RenameColumn(
                name: "CreatedOn",
                table: "FilesOnDatabases",
                newName: "CreatedData");
        }
    }
}
