#ifndef CLUBE_H
#define CLUBE_H
#include "pessooa.h"


class Clube {
	Pessooa** socios;
	unsigned int tam;
	unsigned int nSocios = 0;
public:
	Clube(unsigned int t);
	~Clube();

	string getAsString()const;

	bool setMembroDoClube(Pessooa* p);
};
#endif // !CLUBE_H

ostream& operator<<(ostream& os, const Clube& p);