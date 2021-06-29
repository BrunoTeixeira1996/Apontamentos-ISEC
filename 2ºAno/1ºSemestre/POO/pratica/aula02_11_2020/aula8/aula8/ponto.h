#ifndef PONTO_H
#define PONTO_H
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Ponto {
	int x;
	int y;
public:
	Ponto(int x = 0, int y = 0);
	string getAsString()const;
	int getX()const { return x; }
	int getY()const { return y; }
	double getDist(const Ponto &p)const; /*referencia constante para o Ponto, logo nao vamos
										 alterar o estado interno*/

	void setX(int xx) { x = xx; }
	void setY(int yy) { y = yy; }
};

#endif // !PONTO_H
