#ifndef DUNA_H
#define DUNA_H
#include <string>
#include <sstream>
#include "continente.h"

using namespace std;


class Duna :
	public Continente
{
	static int numT;
public:
	void recolher(int ano, int turno, int *ouro, int *prod);
	string getAsString()const;
	Duna* clone() { return new Duna(*this); }



	static const string nome_princ;
	string getNomePrinc()const { return nome_princ; }


	Duna();
	virtual ~Duna(){}
};


#endif // !DUNA_H
