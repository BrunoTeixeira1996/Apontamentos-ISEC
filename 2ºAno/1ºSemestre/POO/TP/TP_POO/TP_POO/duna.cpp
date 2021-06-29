#include "duna.h"


int Duna::numT = 1;

const string Duna::nome_princ = "Duna";

Duna::Duna()
{
	setNome(nome_princ);
	setResistencia(4);
	setOuro(1);
	setProduto(1);
	setNumObj(numT++);
}


void Duna::recolher(int ano, int turno, int *ouro, int *prod) {
	(*prod)++;
	
}

string Duna::getAsString()const {
	ostringstream os;
	

	os << Territorio::getAsString();

	return os.str();
}