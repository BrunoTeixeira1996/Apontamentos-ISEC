#ifndef PESSOA_H
#define PESSOA_H
#include <sstream>
#include <vector>
#include <string>

using namespace std;


class Pessoa
{
	string nome;
	string cc;
	int nif;

public:
	Pessoa(const string &nom, const  string &cartaocc, int nf);
	string getNome()const { return nome; }
	string getCC()const { return cc; }
	int getNIF()const { return nif; }
	string getAsString()const;


	bool setNome(string n);
};



#endif // !PESSOA_H


