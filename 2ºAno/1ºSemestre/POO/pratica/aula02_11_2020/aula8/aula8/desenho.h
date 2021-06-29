#ifndef DESENHO_H
#define DESENHO_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "retangulo.h"
using namespace std;

class desenho
{
	string nome;
	vector<Retangulo> ret;


public:
	desenho(string n) : nome(n) {};
	string getAsString()const;
	bool addRetangulo(const Retangulo &r);
	void elimRetangulo(double val);
};


#endif