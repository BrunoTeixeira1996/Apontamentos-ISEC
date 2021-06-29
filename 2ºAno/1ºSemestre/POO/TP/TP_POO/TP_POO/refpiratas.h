#ifndef REFPIRATAS_H
#define REFPIRATAS_H
#include <string>
#include <sstream>
#include "ilha.h"

using namespace std;

class RefPiratas:
	public Ilha
{

	static int numT;
public:
	void recolher(int ano, int turno, int *ouro, int *prod);
	string getAsString()const;

	static const string nome_princ;
	string getNomePrinc()const { return nome_princ; }
	RefPiratas* clone() { return new RefPiratas(*this); }


	RefPiratas();
	virtual ~RefPiratas(){}
};



#endif // !REFPIRADAS_H

