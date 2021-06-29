#ifndef PESCARIA_H
#define PESCARIA_H
#include <string>
#include <sstream>
#include "ilha.h"

class Pescaria:
	public Ilha
{
	static int numT;
public:
	void recolher(int ano, int turno, int *ouro, int *prod);
	string getAsString()const;
	Pescaria* clone() { return new Pescaria(*this); }

	static const string nome_princ;
	string getNomePrinc()const { return nome_princ; }


	Pescaria();
	virtual ~Pescaria(){}
};


#endif // !PESCARIA_H


