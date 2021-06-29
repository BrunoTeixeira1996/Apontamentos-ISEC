#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Pessoa
{
	string nome;
	string cc;
	int nif;
public:
	Pessoa(const string &nom, const string &cartaoc,int nf);
	bool setNome(const string &n);
	string getCC()const;
	int getNIF()const;
	string getAsString()const;
};

#endif
