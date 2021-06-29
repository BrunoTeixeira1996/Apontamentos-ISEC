#include "pescaria.h"

int Pescaria::numT = 1;

const string Pescaria::nome_princ = "Pescaria";

Pescaria::Pescaria()
{
	setNome(nome_princ);
	setTipo("Ilha");
	setResistencia(9);
	setOuro(1);
	setProduto(1);
	setNumObj(numT++);
}

void Pescaria::recolher(int ano, int turno, int *ouro, int *prod) {
	if (ano == 1)
		(*prod) = (*prod) + 2;
	else if (ano == 2)
		(*prod) = (*prod) + 4;
}

string Pescaria::getAsString()const {
	ostringstream os;


	os << Territorio::getAsString();

	return os.str();
}