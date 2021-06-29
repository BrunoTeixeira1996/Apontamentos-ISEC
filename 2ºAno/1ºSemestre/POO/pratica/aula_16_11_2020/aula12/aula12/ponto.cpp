#include "ponto.h"

string Ponto::getAsString()const {
	ostringstream os;
	os << "(" << x << "," << y << ")";

	return os.str();
}

Ponto operator+(const Ponto& a, const Ponto& b) {
	Ponto soma(a.getX() + b.getX(), a.getY() + b.getY());

	return soma;
}

bool operator==(const Ponto& a, const Ponto& b) {
	return (a.getX() == b.getX() && a.getY() == b.getY());
}

bool operator!=(const Ponto& a, const Ponto& b) {
	return !(a == b);
}


ostream& operator<<(ostream& os, const Ponto& p) {
	os << p.getAsString();
	return os;
}


Ponto& Ponto::operator++() { //versao pre-fixa
	++x;
	++y;

	return *this;
}

Ponto &Ponto::operator+=(const Ponto &a) {
	*this = *this + a;
	return *this;
}

Ponto Ponto::operator++(int) { // versao pos-fixa
	Ponto copia = *this;
	++(*this);
	return copia;
}

istream &operator>>(istream& is, Ponto& p) {
	int xx, yy;
	is >> xx >> yy;
	if (is.fail() == true) {
		xx = 0;
		yy = 0;
	}
	p.setX(xx);
	p.setY(yy);

	return is;
}
