#include "castelo.h"

int Castelo::numT = 1;

const string Castelo::nome_princ = "Castelo";

Castelo::Castelo()
{

	setNome(nome_princ);
	setResistencia(7);
	setOuro(1);
	setProduto(1);
	setNumObj(numT++);
}

void Castelo::recolher(int ano, int turno, int *ouro, int *prod) {
	

	if (ano == 1 && turno <= 2) {
		(*prod) = (*prod) + 3;
		(*ouro)++;
	}
	else if (ano == 1 && turno > 2 && turno < 7) {
		(*ouro)++;
	}
	else if (ano == 2 && turno >= 7 && turno <= 8) {
		(*prod) = (*prod) + 3;
		(*ouro)++;
	}
	else if (ano == 2 && turno >= 9)
		(*ouro)++;
}

string Castelo::getAsString()const {
	ostringstream os;


	os << Territorio::getAsString();

	return os.str();
}