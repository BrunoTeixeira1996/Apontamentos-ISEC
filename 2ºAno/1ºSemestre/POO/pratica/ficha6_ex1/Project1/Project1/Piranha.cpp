#include "Piranha.h"


ostream& operator<<(ostream& os, const Piranha& p) {
	os << p.getAsString() << "comprimento: " << p.getComprimento();

	return os;
}

Piranha &Piranha::operator=(const Piranha& p) {
	Peixe::operator=(p);
	comprimento = p.comprimento;

	return *this;
}

string Piranha::getAsString()const {
	ostringstream os;

	os << Peixe::getAsString() << ", comprimento: " << comprimento;

	return os.str();
}