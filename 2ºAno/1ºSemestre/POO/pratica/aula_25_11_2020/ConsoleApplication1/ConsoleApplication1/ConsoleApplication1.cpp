#include <iostream>
#include <vector>
#include "clube.h"
#include "pessooa.h"

using namespace std;


int main()
{
	vector<Pessooa*> populacao;
	cout << "vou acrescentar a Maria:\n";
	populacao.push_back(new Pessooa("Maria", 10));
	cout << "Maria adicionada ao vector:\n";
/*
	Pessooa a("Maria", 10), b("Jose", 20);
	Clube c(50);

	c.setMembroDoClube(&a);
	c.setMembroDoClube(&b);

	cout << "Clube c: " << c << endl;


	Clube filatelia(10);
	filatelia = c;
	Pessooa d("Jaime", 30);
	filatelia.setMembroDoClube(&d);
	cout << "Clube filatelia: " << filatelia << endl;

	Clube pesca(filatelia);
	cout << "Clube pesca: " << pesca << endl;
	*/
}

