#include <iostream>
#include "Imovel.h"
#include "Loja.h"
#include "Apartamento.h"
#include "Imobiliaria.h"

using namespace std;

int main() {

	Apartamento apartB(120, 2, 3);
	Loja lojaA(100);

	Imobiliaria x("ERA");
	x.addImovel(&apartB);
	x.addImovel(&lojaA);

	cout << x << endl;

	return 0;
}