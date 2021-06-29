#ifndef FORTALEZA_H
#define FORTALEZA_H
#include <string>
#include <sstream>
#include "continente.h"


using namespace std;

class Fortaleza:
	public Continente
{
	static int numT;
public:
	void recolher(int ano, int turno, int *ouro, int *prod);
	string getAsString()const;
	Fortaleza* clone() { return new Fortaleza(*this); }


	static const string nome_princ;
	string getNomePrinc()const { return nome_princ; }

	Fortaleza();
	virtual ~Fortaleza(){}
};



#endif // !FORTALEZA_H
