#include "ponto.h"

string Ponto::getAsString()const {
	ostringstream os;

	os << "(" << x << "/" << y << ")" << endl;

	return os.str();
}

Ponto operator+(const Ponto& p, const Ponto& pa) {
	Ponto novo(p.getX() + pa.getX() , p.getY() + pa.getY());

	return novo;
}


bool operator==(const Ponto& p, const Ponto& pa) {
	if (p.getX() == pa.getX() && p.getY() == pa.getY()) {
		return true;
	}
	return false;
}

bool operator!=(const Ponto& p, const Ponto& pa) {
	return !(p == pa);
}

ostream& operator<<(ostream& os, const Ponto& p) {
	os << p.getAsString();

	return os;
}


Ponto& Ponto::operator++() {
	++x;
	++y;
	return *this;
}

Ponto Ponto::operator++(int) {
	Ponto copia = *this; //guardo o *this

	++(*this); // incremento o *this

	return copia; // retorno a copia
}

Ponto& Ponto::operator+=(const Ponto& p) {
	*this = *this + p;
	return *this;
}

istream& operator>>(istream& is, Ponto& p) {
	int xx, yy;

	is >> xx >> yy;

	if (is.fail() == true) {
		xx = 0;
		yy = 0;
	}
	p.setX(xx);
	p.setY(xx);

	return is;
}



