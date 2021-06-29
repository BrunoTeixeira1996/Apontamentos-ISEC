#ifndef PIRANHA_H
#define PIRANHA_H
#include "Peixe.h"
#include <sstream>
#include <iostream>


class Piranha : public Peixe
{
	size_t comprimento; // size_t é usado normalmente para tamanhos
public:
	Piranha(string es, string co = "branco", size_t cp = 12) : 
		Peixe(es + "Piranha", co), comprimento(cp){}

	Piranha(const Piranha &p) : Peixe(p), comprimento(p.comprimento){}
	Piranha& operator=(const Piranha& p);

	void come(unsigned int c) override { peso *= 2; } // override é opcional, diz ao compilador que esta funcao é uma virtualizacao de uma funcao que ja existe
	string getAsString()const;
	size_t getComprimento()const { return comprimento; }

	virtual ~Piranha() {
		cout << "Piranha a ser destruido" << endl;
	}
};

ostream& operator<<(ostream& os, const Piranha& p);


#endif

