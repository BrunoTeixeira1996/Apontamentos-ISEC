#ifndef PONTO_H
#define PONTO_H
#include <iostream>
#include <string>
#include <sstream>
#include "ponto3D.h"

using namespace std;

class Ponto
{
	int x, y;
public:
	Ponto(int xx = 0, int yy = 0) : x(xx), y(yy){}

	int getX()const { return x; }
	int getY()const { return y; }
	string getAsString()const;

	void setX(int a) { x = a; }
	void setY(int a) { y = a; }

	Ponto &operator+=(const Ponto &a);


	Ponto &operator++(); // versão prefixa
	Ponto operator++(int); // versao pós-fixa

	operator Ponto3D()const { return Ponto3D(x, y, 0); }

};

Ponto operator+(const Ponto& a, const Ponto &b);
bool operator==(const Ponto& a, const Ponto &b);
bool operator!=(const Ponto& a, const Ponto &b);
ostream &operator<<(ostream& os, const Ponto &p);
istream &operator>>(istream& is,Ponto &p);


#endif

