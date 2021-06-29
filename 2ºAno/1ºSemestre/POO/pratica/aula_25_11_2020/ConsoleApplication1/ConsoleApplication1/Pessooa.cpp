#include "pessooa.h"

string Pessooa::getAsString()const {
	ostringstream os;
	os << "Nome: " << nome << " Idade: " << idade;

	return os.str();
}

ostream& operator<<(ostream& os, const Pessooa& p) {
	os << p.getAsString();
	return os;
}