#include "Loja.h"


string Loja::getAsString()const {
	ostringstream os;

	os << "loja: " << Imovel::getAsString() << endl;

	return os.str();

}