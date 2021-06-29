#ifndef PONTO_3D
#define PONTO_3D

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Ponto3D
{
	int x, y, z;

public:
	Ponto3D(int xx, int yy, int zz) : x(xx), y(yy), z(zz){}

	int getX()const { return x; }
	int getY()const { return y; }
	int getZ()const { return z; }


};

ostream& operator<<(ostream& os, const Ponto3D& p);

#endif