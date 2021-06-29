#pragma once
#ifndef PREGO_H
#define PREGO_H
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

class Aviso; // forward declaration ou iria dar erro porque na classe Aviso já está a ser included 

using namespace std;

class Prego {
	int x, y;
	vector<Aviso*> avisos;
public:
	Prego(int a, int b) { x = a; y = b;}

	Prego(const Prego&) = delete; // copia entre pregos nao faz sentido, porque nao ha pregos em cima de outros
	~Prego();

	Prego& operator=(const Prego&) = delete;// copia entre pregos nao faz sentido, porque nao ha pregos em cima de outros

	void mudaDeSitio(int a, int b) { x = a; y = b; }
	string getAsString()const;
	string getLocal()const;


	bool addAviso(Aviso *a);
	string listaAvisos()const;

	bool retiraAviso(Aviso* a);
};



#endif // !PREGO_H


