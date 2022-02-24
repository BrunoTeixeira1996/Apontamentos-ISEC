using Microsoft.EntityFrameworkCore.Migrations;

namespace Airbnb.Migrations
{
    public partial class aac : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Accomodations_Employees_EmployeeId",
                table: "Accomodations");

            migrationBuilder.AlterColumn<int>(
                name: "EmployeeId",
                table: "Accomodations",
                type: "int",
                nullable: true,
                oldClrType: typeof(int),
                oldType: "int");

            migrationBuilder.AddForeignKey(
                name: "FK_Accomodations_Employees_EmployeeId",
                table: "Accomodations",
                column: "EmployeeId",
                principalTable: "Employees",
                principalColumn: "EmployeeId",
                onDelete: ReferentialAction.Restrict);
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Accomodations_Employees_EmployeeId",
                table: "Accomodations");

            migrationBuilder.AlterColumn<int>(
                name: "EmployeeId",
                table: "Accomodations",
                type: "int",
                nullable: false,
                defaultValue: 0,
                oldClrType: typeof(int),
                oldType: "int",
                oldNullable: true);

            migrationBuilder.AddForeignKey(
                name: "FK_Accomodations_Employees_EmployeeId",
                table: "Accomodations",
                column: "EmployeeId",
                principalTable: "Employees",
                principalColumn: "EmployeeId",
                onDelete: ReferentialAction.Cascade);
        }
    }
}
