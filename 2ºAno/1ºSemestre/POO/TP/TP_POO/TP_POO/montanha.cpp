#include "montanha.h"

int Montanha::numT = 1;

const string Montanha::nome_princ = "Montanha";

Montanha::Montanha()
{
	setNome(nome_princ);
	setResistencia(6);
	setOuro(1);
	setProduto(1);
	setNumObj(numT++);
}

void Montanha::recolher(int ano, int turno, int *ouro, int *prod) {
	flag_conquista++;

	if (flag_conquista >= 2)
		(*prod)++;
}

string Montanha::getAsString()const {
	ostringstream os;


	os << Territorio::getAsString();

	return os.str();
}