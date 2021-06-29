#include "fortaleza.h"


int Fortaleza::numT = 1;

const string Fortaleza::nome_princ = "Fortaleza";

Fortaleza::Fortaleza()
{
	setNome(nome_princ);
	setResistencia(8);
	setOuro(1);
	setProduto(1);
	setNumObj(numT++);

}

void Fortaleza::recolher(int ano, int turno, int *ouro, int *prod) {
	return;
}

string Fortaleza::getAsString()const {
	ostringstream os;


	os << Territorio::getAsString();

	return os.str();
}