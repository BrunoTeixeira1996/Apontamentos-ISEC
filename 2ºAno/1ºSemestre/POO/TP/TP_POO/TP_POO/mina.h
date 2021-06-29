#ifndef MINA_H
#define MINA_H
#include <string>
#include <sstream>
#include "continente.h"

using namespace std;

#endif // !MINA_H

class Mina :
	public Continente
{
	static int numT;
public:
	void recolher(int ano, int turno, int *ouro, int *prod);
	string getAsString()const;
	Mina* clone() { return new Mina(*this); }


	static const string nome_princ;
	string getNomePrinc()const { return nome_princ; }


	Mina();
	virtual ~Mina(){}
};

