#include"dadosVenda.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

DadosVenda::DadosVenda(std::string isbn, double rec, int uv = 1) :
	numLivro(isbn), unidadesVendidas(uv), receita(rec) {}

string DadosVenda::getISBN() const { return numLivro; }

int main()
{
	DadosVenda v1("0-321-71411-3", 45);
	cout << v1.getISBN();


}