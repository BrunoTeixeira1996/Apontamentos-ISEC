#ifndef PONTO_H
#define PONTO_H
#include "ponto3D.h"
#include <string>
#include <sstream>

using namespace std;

class Ponto
{
	int x, y;

public:
	Ponto(int xx = 0, int yy = 0): x(xx), y(yy){}
	int getX()const { return x; }
	int getY()const { return y; }
	string getAsString()const;

	void setX(int a) { x = a; }
	void setY(int a) { y = a; }

	explicit operator Ponto3D() { return Ponto3D(x, y, 0); }

	Ponto &operator++(); // versao prefixa
	Ponto operator++(int); // versao posfixa

	Ponto& operator+=(const Ponto& p);

};

Ponto operator+(const Ponto& p, const Ponto& pa);
bool operator==(const Ponto& p, const Ponto& pa);
bool operator!=(const Ponto& p, const Ponto& pa);
ostream& operator<<(ostream& os, const Ponto& p);

istream& operator>>(istream& is, Ponto& p);



#endif
