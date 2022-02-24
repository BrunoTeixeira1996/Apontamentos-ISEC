using Microsoft.EntityFrameworkCore.Migrations;

namespace Airbnb.Migrations
{
    public partial class criadomodelodoManager : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "ManagerId",
                table: "Accomodations",
                type: "int",
                nullable: true);

            migrationBuilder.CreateTable(
                name: "Managers",
                columns: table => new
                {
                    ManagerId = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    ApplicationUserId = table.Column<string>(type: "nvarchar(450)", nullable: true),
                    AdminId = table.Column<int>(type: "int", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Managers", x => x.ManagerId);
                    table.ForeignKey(
                        name: "FK_Managers_Admins_AdminId",
                        column: x => x.AdminId,
                        principalTable: "Admins",
                        principalColumn: "AdminId",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_Managers_AspNetUsers_ApplicationUserId",
                        column: x => x.ApplicationUserId,
                        principalTable: "AspNetUsers",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateIndex(
                name: "IX_Accomodations_ManagerId",
                table: "Accomodations",
                column: "ManagerId");

            migrationBuilder.CreateIndex(
                name: "IX_Managers_AdminId",
                table: "Managers",
                column: "AdminId");

            migrationBuilder.CreateIndex(
                name: "IX_Managers_ApplicationUserId",
                table: "Managers",
                column: "ApplicationUserId");

            migrationBuilder.AddForeignKey(
                name: "FK_Accomodations_Managers_ManagerId",
                table: "Accomodations",
                column: "ManagerId",
                principalTable: "Managers",
                principalColumn: "ManagerId",
                onDelete: ReferentialAction.Restrict);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Accomodations_Managers_ManagerId",
                table: "Accomodations");

            migrationBuilder.DropTable(
                name: "Managers");

            migrationBuilder.DropIndex(
                name: "IX_Accomodations_ManagerId",
                table: "Accomodations");

            migrationBuilder.DropColumn(
                name: "ManagerId",
                table: "Accomodations");
        }
    }
}
