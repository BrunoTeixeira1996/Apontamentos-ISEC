#include "terrnic.h"



TerrInic::TerrInic()
{
	setNome("TerritorioInicial");
	setResistencia(10);
	setOuro(1);
	setProduto(1);
}

void TerrInic::recolher(int ano, int turno, int *ouro, int *prod) {
	(*ouro)++;
	(*prod)++;
}
string TerrInic::getAsString()const {
	ostringstream os;

	os << Territorio::getAsString();

	return os.str();
}
