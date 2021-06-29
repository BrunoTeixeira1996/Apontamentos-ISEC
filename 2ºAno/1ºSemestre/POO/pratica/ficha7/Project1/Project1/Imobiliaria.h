#ifndef IMOBILIARIA_H
#define IMOBILIARIA_H
#include <vector>
#include "Imovel.h"

class Imobiliaria
{
	string nome;
	vector <Imovel*> imoveis;
public:
	Imobiliaria(string n) : nome(n){}

	bool addImovel(Imovel* i);
	string getAsString()const;
};

ostream& operator<<(ostream& os, const Imobiliaria& i);

#endif
