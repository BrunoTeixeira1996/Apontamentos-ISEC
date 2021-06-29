#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Imovel
{
	int area;
	int preco;
	int codigo;
	int andar;

	static int conta;

public:
	Imovel(int pr, int ar, int anda) : preco(pr), area(ar), andar(anda), codigo(conta++){}

	int getPrego()const { return preco; }
	int getCodigo()const { return codigo; }
	virtual string getAsString()const;

	virtual ~Imovel() {};
};

ostream& operator<<(ostream& os, const Imovel& i);

#endif
