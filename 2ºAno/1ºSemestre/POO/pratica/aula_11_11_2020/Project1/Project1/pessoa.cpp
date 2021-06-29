#include "pessoa.h"



Pessoa::Pessoa(const string &nom, const string &cartaoc, int nf)
{
	nome = nom;
	cc = cartaoc;
	nif = nf ;
}

// Falta : verificar se o nome é válido
bool Pessoa::setNome(const string &name) {
	nome = name;
	return true;
}

string Pessoa::getCC()const {
	return cc;
}

int Pessoa::getNIF() const {
	return nif;
}

string Pessoa::getAsString()const {
	ostringstream os;
	os << "Nome: " << nome << " " << "CC: " << cc << " " << "NIF: " << nif;
	return os.str();
}
