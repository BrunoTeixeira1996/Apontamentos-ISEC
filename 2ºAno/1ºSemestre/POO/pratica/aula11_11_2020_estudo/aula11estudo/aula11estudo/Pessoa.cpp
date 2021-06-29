#include "pessoa.h"


Pessoa::Pessoa(const string &nom,const  string &cartaocc, int nf) {
	nome = nom;
	cc = cartaocc;
	nif = nf;
}

string Pessoa::getAsString()const {
	ostringstream os;

	os << "Nome: " << nome << " CC: " << cc << " NIF: " << nif;

	return os.str();
 }

bool Pessoa::setNome(string n) {
	nome = n;

	return true;
}