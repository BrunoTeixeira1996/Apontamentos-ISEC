#ifndef GUARDA_H
#define GUARDA_H

#include "logica.h"
using namespace std;

class Guarda
{
	string nome;
	Logica lo;

public:
	Guarda(string no, Logica &l) : nome(no), lo(l) {}

	string getNome()const { return nome; }
	Logica getLogica() { return lo; }
};

#endif /*GUARDA_H*/
