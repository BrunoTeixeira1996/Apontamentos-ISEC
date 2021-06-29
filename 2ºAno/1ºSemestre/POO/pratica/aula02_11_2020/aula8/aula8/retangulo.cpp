#include "retangulo.h"


Retangulo::Retangulo(Ponto canto, double a, double l) : cse(canto), altura(a), largura(l) {
	if (altura < 0) {
		altura = -altura;
	}
	if (largura < 0) {
		largura = -largura;
	}
}

string Retangulo::getAsString()const {
	ostringstream os;
	os << "Retangulo de canto sup. esq. " << cse.getAsString() << "altura: " << altura << ", largura: " << largura << "\n\n";

	return os.str();
}