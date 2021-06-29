#ifndef PLANICIE_H
#define PLANICIE_H
#include <string>
#include <sstream>
#include "continente.h"

using namespace std;

class Planicie:
	public Continente
{
	static int numT;
public:
	void recolher(int ano, int turno, int *ouro, int *prod);
	string getAsString()const;
	Planicie* clone() { return new Planicie(*this); }

	static const string nome_princ;
	string getNomePrinc()const { return nome_princ; }

	Planicie();
	virtual ~Planicie(){}
};

#endif // !PLANICIE_H

