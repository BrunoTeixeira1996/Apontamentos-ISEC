#include "fracao.h"


bool Fracao::setDenominador(int de) {
	if (de == 0)
		return false;
	denominador = de;
	if (denominador < 0) {
		denominador = -denominador;
		numerador = -numerador;
	}
	return true;

}

string Fracao::getAsString()const {
	ostringstream os;

	os << "(" << numerador << "/" << denominador << ")" << endl;

	return os.str();
}

Fracao operator*(const Fracao& a, const Fracao& b) {
	Fracao x(a.getNumerador()*b.getNumerador(), a.getDenominador()*b.getDenominador());

	return x;
}

Fracao Fracao::operator*(const Fracao& a) {
	return Fracao(numerador*a.getNumerador(), denominador*a.getDenominador());
}

ostream& operator<<(ostream& os, const Fracao& a) {
	os << a.getAsString();

	return os;
}

Fracao &Fracao::operator*=(const Fracao& a) {

	*this = *this * a;

	return *this;
}

Fracao operator*=(const Fracao& a, const Fracao& b){
	Fracao aux(a.getNumerador()*b.getNumerador(), a.getDenominador()*b.getDenominador());

	return aux;
}


Fracao& Fracao::operator++() {
	++numerador;
	++denominador;

	return *this;
}

Fracao Fracao::operator++(int) {
	Fracao aux = *this;

	++numerador;
	++denominador;

	return aux;
}

bool operator==(const Fracao& a, const Fracao& b) {
	if (a.getNumerador() == b.getNumerador() && a.getDenominador() == b.getDenominador())
		return true;

	return false;
}

istream& operator>>(istream& is, Fracao& a) {
	int num, deno;

	is >> num >> deno;

	if (is.fail()) {
		a.setNumerador(0);
		a.setDenominador(1);
	}
	else {
		a.setNumerador(num);
		a.setDenominador(deno);
	}
	return is;
}


Fracao operator+(const Fracao& a, const Fracao& b) {
	Fracao aux(a.getNumerador() + b.getNumerador(), a.getDenominador() + b.getDenominador());

	return aux;
}

Fracao Fracao::operator+(const Fracao& a) {
	return Fracao(numerador + a.getNumerador(), denominador + a.getDenominador());
}


Fracao& Fracao::operator+=(const Fracao& a) {
	numerador += a.getNumerador();
	denominador += a.getDenominador();

	return *this;

}
