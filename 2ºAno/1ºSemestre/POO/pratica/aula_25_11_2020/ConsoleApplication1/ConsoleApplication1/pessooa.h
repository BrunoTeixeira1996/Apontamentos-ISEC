#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <sstream>
using namespace std;


class Pessooa
{
	string nome;
	unsigned int idade;

public:
	Pessooa(string n, int i) : nome(n), idade(i) {
		if (i > 150)
			i = 0;
	}

	string getAsString()const;
};

ostream& operator<<(ostream& os, const Pessooa& p);

#endif
