#include "Imovel.h"

int Imovel::conta = 1;


string Imovel::getAsString()const {
	ostringstream os;

	os << "Codigo: " << codigo << " Preco: " << preco << " Area: " << area << " Andar: " << andar;

	return os.str();
}

ostream& operator<<(ostream& os, const Imovel& i) {
	os << i.getAsString();

	return os;
}