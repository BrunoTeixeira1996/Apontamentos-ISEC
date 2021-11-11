using Microsoft.EntityFrameworkCore.Migrations;

namespace Ficha3_ex4.Data.Migrations
{
    public partial class UCsddd : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "UCs",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Nome = table.Column<string>(type: "nvarchar(max)", nullable: true),
                    ECTS = table.Column<string>(type: "nvarchar(max)", nullable: true),
                    Licenciatura = table.Column<string>(type: "nvarchar(max)", nullable: true),
                    Ramo = table.Column<string>(type: "nvarchar(max)", nullable: true),
                    Semestre = table.Column<string>(type: "nvarchar(max)", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_UCs", x => x.Id);
                });
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "UCs");
        }
    }
}
