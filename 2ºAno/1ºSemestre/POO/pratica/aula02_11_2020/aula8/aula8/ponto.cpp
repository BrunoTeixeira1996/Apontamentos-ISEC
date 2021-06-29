#include "ponto.h"


Ponto::Ponto(int i, int j) : x(i), y(j)
{
}

string Ponto::getAsString()const {
	ostringstream os;
	os << x << "/" << y << "\n";

	return os.str();
}

double Ponto::getDist(const Ponto &p)const {/*"this" retrata o objeto onde é chamada a função*/
	return sqrt(pow((this->x - p.getX()), 2) + pow((this->y - p.getY()), 2));
}