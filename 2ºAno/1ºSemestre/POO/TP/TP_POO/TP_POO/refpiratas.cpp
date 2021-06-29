#include "refpiratas.h"

int RefPiratas::numT = 1;

const string RefPiratas::nome_princ = "RefugioPiratas";

RefPiratas::RefPiratas()
{
	setNome(nome_princ);
	setTipo("Ilha");
	setResistencia(9);
	setOuro(1);
	setProduto(1);
	setNumObj(numT++);
}

void RefPiratas::recolher(int ano, int turno, int *ouro, int *prod) {
	(*ouro)++;
}

string RefPiratas::getAsString()const {
	ostringstream os;


	os << Territorio::getAsString();

	return os.str();
}