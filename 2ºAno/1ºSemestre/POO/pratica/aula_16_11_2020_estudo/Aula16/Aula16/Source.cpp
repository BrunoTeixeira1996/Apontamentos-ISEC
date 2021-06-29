#include <iostream>
#include "ponto.h"
#include "fracao.h"
#include "ponto3D.h"

void tralala(Ponto3D p) {
	cout << "tralala" << endl;

	cout << p;
}


void func(int n) {
	cout << n;  // aparece 2
}
int main() {

	Fracao alo(1, 2);
	Fracao blo(1, 2);
	Fracao lol(1,2);
	Fracao ax;
	
	alo += blo;

	cout << alo;

	//if (alo == blo)
	//	cout << "ya";
	//else
	//	cout << "nope";

	//const Fracao f(7, 3);

	//func(f);

	//Ponto p(1,2);
	//Ponto pa(2, 3);
	//Ponto a;
	
	//tralala(static_cast<Ponto3D>(a)); // coomo o operator esta marcado como explicito, temos de fazer cast para um Ponto3D aqui


	//cin >> a;
	//if (cin.fail())
	//	cout << "leitura falhou" << endl;
	//else
	//	cout << a << endl;

	/*p += pa;
	cout << p;*/
	


	/*==================================================================================================================*/

	/*O porquê do operador + poder ser global, por causa das conversões implicidas*/
	/*Se colocarmos "explicit" atrás do construtor isto já não funciona*/
	/*Para funcionar com o explicit teriamos de fazer assim : Ponto e = b + Ponto(2); */ 
	/*
	*Ponto novo = p + pa;
	Ponto e = p + 2; // conversão implicita
	Ponto a = 2 + p; // conversão implicita

	cout << e.getAsString();
	cout << a.getAsString();
	*/

	/*==================================================================================================================*/

	/*operador de == e != */
	/*
	if (p == pa)
		cout << "P igual a PA";

	if (p != pa)
		cout << "P diferente de PA";

	*/


	/*==================================================================================================================*/
	/*
	cout << pa;
	*/


	/*==================================================================================================================*/
	/*
	Ponto a(1, 1);
	cout << "Ponto a: " << ++a;
	*/

	//Fracao a(1,2);
	//Fracao b(3);
	//const Fracao c(3,4);



	//a *= b *= c; // a *= ( b *= c)
	//cout << a;

	//a = b * 4;
	//cout << a;


	Fracao a(1, 2), b(2, 3), c(3, 4);

	/*(a *= b) *= c;*/
	//a++;
	//cout << a;
	
}