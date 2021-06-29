#ifndef CONTACTO_H
#define CONTACTO_H
#include <string>

using namespace std;


class Contacto
{
	string nome;
	unsigned int tel;

public:
	Contacto(const string n, unsigned int t) : nome(n), tel(t){}
	string getNome()const { return nome; }
	int getTel()const { return tel; }


	void setNome(const string s) { nome = s; }
	void setTel(unsigned int t) { tel = t; }
};

#endif