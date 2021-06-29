#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "pessoa.h"

class Conta
{
	int saldo;
	Pessoa *pe;
public:
	Conta(Pessoa *p);

	int getSaldo()const;
	const Pessoa *getTitular()const;

	bool deposita(int val);
	bool levanta(int val);
	string getAsString()const;
};

#endif
