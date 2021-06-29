#ifndef CONTA_H
#define CONTA_H
#include <sstream>
#include <vector>
#include <string>
#include "pessoa.h"

class Conta
{
	int saldo;
	Pessoa *p;
	
public:
	Conta(Pessoa* a);
	const Pessoa* getTitular()const { return p; }
	int getSaldo() { return saldo; }

	bool deposita(int valor);
	bool levanta(int valor);

	string getAsString()const;
};


#endif
