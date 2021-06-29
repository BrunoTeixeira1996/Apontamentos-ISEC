#ifndef LOJA_H
#define LOJA_H

#include "Imovel.h"

class Loja : public Imovel
{

public:
	Loja(int area) : Imovel(15 * area, area, 0){}
	
	string getAsString()const override;
};

#endif
