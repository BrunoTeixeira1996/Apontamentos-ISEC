#ifndef TERRITORIO_H
#define TERRITORIO_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;




class Territorio
{
	string nome ="";
	string tipo = "";
	int resistencia = 0;
	int ouro = 0;
	int produto = 0;
	int numObj = 0;

public:
	virtual void recolher(int ano, int turno, int *ouro, int *prod) = 0;

	//gets
	string getNome()const { return nome; }
	string getTipo()const { return tipo; }
	int getResistencia()const { return resistencia; }
	int getOuro()const { return ouro; }
	int getProduto()const { return produto; }
	int getNumObj()const { return numObj; }
	virtual string getAsString()const = 0;
	virtual string getNomePrinc()const = 0;
	virtual Territorio* clone() = 0;


	//sets
	void setNome(string n);
	void setTipo(string t) { tipo = t; }
	void setResistencia(int res) { resistencia = res; }
	void setOuro(int ou) { ouro = ou;}
	void setProduto(int prod) { produto = prod; }
	void setNumObj(int num);

	Territorio();

	virtual ~Territorio(){}
};


#endif // !TERRITORIO_H


