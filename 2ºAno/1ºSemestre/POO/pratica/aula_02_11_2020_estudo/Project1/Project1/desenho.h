#ifndef DESENHO_H
#define DESENHO_H
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "retangulo.h"

class Desenho
{
	string nome;
	vector<Retangulo> ret;
public:
	Desenho(string n) : nome(n) {};
	string getAsString()const;
	bool setRetangulo(const Retangulo &r);
	bool setRetOrd(const Retangulo &r);
	void remArea(double valor);
};


#endif