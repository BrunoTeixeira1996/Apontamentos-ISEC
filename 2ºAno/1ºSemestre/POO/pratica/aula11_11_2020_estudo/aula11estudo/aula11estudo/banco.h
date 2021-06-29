#ifndef BANCO_H
#define BANCO_H
#include <sstream>
#include <vector>
#include <string>
#include "conta.h"

using namespace std;

class Banco
{
	string nome;
	vector<Conta> contass;

public:
	Banco(string n) : nome(n){}

	string getAsString()const;

	bool deposita(const string& bi, int quantia);
	bool addConta(Conta c);
	bool delConta(const string&bi);
};


#endif
