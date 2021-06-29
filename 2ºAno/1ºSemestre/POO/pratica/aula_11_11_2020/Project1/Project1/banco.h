#ifndef BANCO_H
#define BANCO_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "conta.h"
class Banco
{
	string nome;
	vector<Conta>contas;
public:
	Banco(string no);

	bool addConta(const Conta &c);
	bool delConta(const string &bi);
	bool deposita(const string &bi, int valor);
	string getAsString()const;

};


#endif // !BANCO_H


