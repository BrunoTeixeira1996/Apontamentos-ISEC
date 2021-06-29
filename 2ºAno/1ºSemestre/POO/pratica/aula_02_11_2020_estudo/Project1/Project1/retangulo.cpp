#include "retangulo.h"



Retangulo::Retangulo(Ponto p, double l, double a): cse(p), largura(l), altura(a)
{
	if (altura < 0)
		altura = -altura;

	if (largura < 0)
		largura = -largura;

	cout << "Construindo " << getAsString() << endl;
}

Retangulo::~Retangulo() {
	//cout << "Destruindo " << getAsString() << endl;
}

string Retangulo::getAsString()const {
	ostringstream os;

	os << "Retangulo de canto sup esq: " << cse.getAsString() << ", altura: " << altura << ", largura: " << largura << endl;
	
	return os.str();
}

void Retangulo::setCanto(Ponto c) {
	cse.setX(c.getX());
	cse.setY(c.getY());
}