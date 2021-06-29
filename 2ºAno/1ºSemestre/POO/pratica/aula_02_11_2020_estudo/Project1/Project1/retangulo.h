#ifndef RETANGULO_H
#define RETANGULO_H

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "ponto.h"
using namespace std;

class Retangulo
{
	Ponto cse;
	double largura;
	double altura;
public:
	Retangulo(Ponto p, double l, double a);
	~Retangulo();

	string getAsString()const;
	Ponto getCSE()const { return cse; }
	double getAltura()const { return altura; }
	double getLargura()const { return largura; }
	double getArea()const { return altura*largura; }
	double getInterseta(const Retangulo &r)const { return false; }



	void setCanto(Ponto c);

};

#endif // !RETANGULO_H


