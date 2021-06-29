#ifndef PEIXE_H
#define PEIXE_H
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


class Aquario;
class Peixe
{
	static unsigned int conta;
	string especie;
	string cor;
	unsigned int nSerie;
	Aquario* aquario = nullptr;
	bool indigestao = false;
	unsigned int resta = 4; // eventos de alimentação até morrer depois da indigestao

protected:
	unsigned int peso = 10; // protected para ficar acessível para a piranha

public:
	Peixe(string es, string co = "cinzento"):especie(es),cor(co), nSerie(conta++){}
	Peixe(const Peixe& p);
	Peixe& operator=(const Peixe& p);

	bool isVivo()const { return resta > 0; }
	virtual void come(unsigned int c);
	bool ligaAquario(Aquario* a);
	virtual string getAsString()const;
	unsigned int getNumeroSerie() const { return nSerie; }

	virtual ~Peixe(){
		cout << "Peixe a ser destruido" << endl;
	}
};

ostream &operator<<(ostream &os, const Peixe &p);

#endif