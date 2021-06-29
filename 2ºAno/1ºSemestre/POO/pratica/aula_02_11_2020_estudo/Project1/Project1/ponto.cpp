#include "ponto.h"



Ponto::Ponto(int a, int b): x(a), y(b)
{
	//cout << "Construindo o ponto " << getAsString() << endl;
}

Ponto::~Ponto() {
	//cout << "Destruindo o ponto " << getAsString() << endl;
}

Ponto::Ponto() {
	x = 0;
	y = 0;

}


string Ponto::getAsString() const {
	ostringstream os;

	os << "(" << x << "/" << y << ")";

	return os.str();
}

/*o this vai servir para acedermos ao atributo do Ponto que está a executar a função getDist()*/
double Ponto::getDist(const Ponto &p)const {
	return sqrt(pow((this->x - p.getX()),2) + pow((this->y - p.getY()),2));
}