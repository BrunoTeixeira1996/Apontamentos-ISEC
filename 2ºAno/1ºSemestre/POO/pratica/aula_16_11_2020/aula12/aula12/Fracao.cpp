#include "fracao.h"


Fracao::Fracao(int nu, int den) : numerador(nu), denominador(den) {
	if (denominador == 0)
		denominador = 1;

	if (denominador < 0) {
		denominador = -denominador;
		numerador = -numerador;
	}

}


string Fracao::getAsstring()const {
	ostringstream os;
	os << "(" << numerador << "/" << denominador << ")";

	return os.str();
}

bool Fracao::setDenominador(int d) {
	if (d <= 0) {
		return false;
	}
	denominador = d;
	if (denominador < 0) {
		denominador = -denominador;
		numerador = -numerador;
		
	}
	return true;
}

Fracao operator*(const Fracao& a, const Fracao& b) {
	Fracao mult(a.getNumerador() * b.getNumerador(), a.getDenominador() * b.getDenominador());

	return mult;
}

Fracao Fracao::operator*(const Fracao& a) {
	return Fracao(numerador * a.getNumerador(), denominador * a.getDenominador());
}


Fracao &Fracao::operator*=(const Fracao& a) {
	*this = *this * a;
	return *this;
}
