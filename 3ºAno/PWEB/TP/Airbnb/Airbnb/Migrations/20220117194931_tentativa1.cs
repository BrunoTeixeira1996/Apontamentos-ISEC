using Microsoft.EntityFrameworkCore.Migrations;

namespace Airbnb.Migrations
{
    public partial class tentativa1 : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "EmployeeId",
                table: "Accomodations",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.CreateIndex(
                name: "IX_Accomodations_EmployeeId",
                table: "Accomodations",
                column: "EmployeeId");

            migrationBuilder.AddForeignKey(
                name: "FK_Accomodations_Employees_EmployeeId",
                table: "Accomodations",
                column: "EmployeeId",
                principalTable: "Employees",
                principalColumn: "EmployeeId",
                onDelete: ReferentialAction.NoAction);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Accomodations_Employees_EmployeeId",
                table: "Accomodations");

            migrationBuilder.DropIndex(
                name: "IX_Accomodations_EmployeeId",
                table: "Accomodations");

            migrationBuilder.DropColumn(
                name: "EmployeeId",
                table: "Accomodations");
        }
    }
}
