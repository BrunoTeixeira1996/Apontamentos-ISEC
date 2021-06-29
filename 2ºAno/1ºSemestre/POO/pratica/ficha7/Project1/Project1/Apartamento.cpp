#include "Apartamento.h"


string Apartamento::getAsString()const {
	ostringstream os;

	os << "apartamento: " <<  Imovel::getAsString() << ", assoalhadas: " << assoalhadas << endl;

	return os.str();
}