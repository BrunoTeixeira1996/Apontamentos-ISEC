#ifndef PONTO_H
#define PONTO_H
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Ponto
{
	int x;
	int y;


public:
	Ponto(int a, int b);
	Ponto();
	~Ponto();

	string getAsString() const;
	int getX() const { return x; }
	int getY() const { return y; }
	double getDist(const Ponto &p) const;

	void setX(int xx) { x = xx; }
	void setY(int yy) { y = yy; }
};

#endif // !PONTO_H

