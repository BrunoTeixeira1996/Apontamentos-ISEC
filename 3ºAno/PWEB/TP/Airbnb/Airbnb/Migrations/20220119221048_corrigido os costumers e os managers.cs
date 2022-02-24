using Microsoft.EntityFrameworkCore.Migrations;

namespace Airbnb.Migrations
{
    public partial class corrigidooscostumerseosmanagers : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Customers_Admins_AdminId",
                table: "Customers");

            migrationBuilder.DropForeignKey(
                name: "FK_Managers_Admins_AdminId",
                table: "Managers");

            migrationBuilder.DropIndex(
                name: "IX_Managers_AdminId",
                table: "Managers");

            migrationBuilder.DropIndex(
                name: "IX_Customers_AdminId",
                table: "Customers");

            migrationBuilder.DropColumn(
                name: "AdminId",
                table: "Managers");

            migrationBuilder.DropColumn(
                name: "AdminId",
                table: "Customers");
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "AdminId",
                table: "Managers",
                type: "int",
                nullable: true);

            migrationBuilder.AddColumn<int>(
                name: "AdminId",
                table: "Customers",
                type: "int",
                nullable: true);

            migrationBuilder.CreateIndex(
                name: "IX_Managers_AdminId",
                table: "Managers",
                column: "AdminId");

            migrationBuilder.CreateIndex(
                name: "IX_Customers_AdminId",
                table: "Customers",
                column: "AdminId");

            migrationBuilder.AddForeignKey(
                name: "FK_Customers_Admins_AdminId",
                table: "Customers",
                column: "AdminId",
                principalTable: "Admins",
                principalColumn: "AdminId",
                onDelete: ReferentialAction.Restrict);

            migrationBuilder.AddForeignKey(
                name: "FK_Managers_Admins_AdminId",
                table: "Managers",
                column: "AdminId",
                principalTable: "Admins",
                principalColumn: "AdminId",
                onDelete: ReferentialAction.Restrict);
        }
    }
}
