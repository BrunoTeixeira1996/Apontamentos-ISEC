#ifndef MONTANHA_H
#define MONTANHA_H
#include <string>
#include <sstream>
#include "continente.h"

using namespace std;


class Montanha:
	public Continente
{
	int flag_conquista = 0;
	static int numT;

public:
	void recolher(int ano, int turno, int *ouro, int *prod);
	string getAsString()const;
	Montanha* clone() { return new Montanha(*this); }


	static const string nome_princ;
	string getNomePrinc()const { return nome_princ; }

	Montanha();
	virtual ~Montanha(){}
};

#endif // !MONTANHA_H
