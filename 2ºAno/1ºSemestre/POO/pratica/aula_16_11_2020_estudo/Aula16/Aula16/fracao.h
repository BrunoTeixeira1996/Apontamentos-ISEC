#ifndef FRACAO_H
#define FRACAO_H
#include <string>
#include <sstream>

using namespace std;

class Fracao
{
	int numerador;
	int denominador;

public:
	Fracao(int n = 0, int d = 1) : numerador(n), denominador(d){
		if (denominador == 0)
			denominador = 1;
		if (denominador < 0) {
			denominador = -denominador;
			numerador= -numerador;
		}
	}

	int getNumerador()const { return numerador; }
	int getDenominador()const { return denominador; }
	string getAsString()const;


	void setNumerador(int nu) { numerador = nu; }
	bool setDenominador(int de);

	operator int() const { return numerador / denominador; }


	Fracao operator*(const Fracao& a); // a * b
	Fracao &operator*=(const Fracao& a); // a *= b

	Fracao &operator++(); // ++a;
	Fracao operator++(int);// a++;

	Fracao operator+(const Fracao& a);
	Fracao &operator+=(const Fracao& a);


};

Fracao operator+(const Fracao& a, const Fracao& b);

Fracao operator*(const Fracao &a, const Fracao &b); // a = b * c;

ostream& operator<<(ostream& os, const Fracao& a);

Fracao operator*=(const Fracao& a,const Fracao &b);

bool operator==(const Fracao& a, const Fracao& b);

istream& operator>>(istream& is,Fracao& a);

#endif // !FRACAO_H

