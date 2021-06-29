#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Imovel.h"

class Apartamento : public Imovel
{
	int assoalhadas;

public:
	Apartamento(int area, int andar, int ass) : Imovel(10*area, area, andar), assoalhadas(ass) {}

	string getAsString()const override;
	int getNquartos()const { return assoalhadas; }
};

#endif