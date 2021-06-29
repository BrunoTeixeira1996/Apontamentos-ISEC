#ifndef  CASTELO_H
#define CASTELO_H
#include <string>
#include <sstream>
#include "continente.h"

using namespace std;


class Castelo:
	public Continente
{
	static int numT;

public:
	static const string nome_princ;
	void recolher(int ano, int turno, int *ouro, int *prod);
	string getAsString()const;
	Castelo* clone() { return new Castelo(*this); }


	string getNomePrinc()const { return nome_princ; }
	
	Castelo();
	virtual ~Castelo(){}
};



#endif // ! CASTELO_H
