#include "planicie.h"

int Planicie::numT = 1;

const string Planicie::nome_princ = "Planicie";

Planicie::Planicie()
{
	setNome(nome_princ);
	setResistencia(5);
	setOuro(1);
	setProduto(1);
	setNumObj(numT++);
}

void Planicie::recolher(int ano, int turno, int *ouro, int *prod) {
	if (ano == 1) {
		(*ouro)++;
		(*prod)++;
	}
	else if (ano == 2) {
		(*ouro)++;
		(*prod) = (*prod) + 2;
	}
}

string Planicie::getAsString()const {
	ostringstream os;


	os << Territorio::getAsString();

	return os.str();
}