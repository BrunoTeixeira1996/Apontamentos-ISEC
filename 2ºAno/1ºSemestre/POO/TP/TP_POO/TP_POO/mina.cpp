#include "mina.h"

int Mina::numT = 1;

const string Mina::nome_princ = "Mina";

Mina::Mina()
{
	setNome(nome_princ);
	setResistencia(5);
	setOuro(1);
	setProduto(1);
	setNumObj(numT++);
}

void Mina::recolher(int ano, int turno, int *ouro, int *prod) {
	if (ano == 1 && turno <= 3 || ano == 2 && turno <= 3)
		(*ouro)++;
	else if (ano == 2 && turno <= 6 || ano == 2 && turno >= 3)
		(*ouro) = (*ouro) + 2;
}

string Mina::getAsString()const {
	ostringstream os;


	os << Territorio::getAsString();

	return os.str();
}