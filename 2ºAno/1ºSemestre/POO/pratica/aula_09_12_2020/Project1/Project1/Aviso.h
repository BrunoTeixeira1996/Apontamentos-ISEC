#ifndef AVISO_H
#define AVISO_H
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "Prego.h"


class Aviso
{
	string texto;
	Prego* a = nullptr;


public:
	Aviso(const string t, Prego* p);
	Aviso(const Aviso& o);
	~Aviso();

	string getAsString()const;
	string getLocal()const;

	bool saiDoPrego(Prego *p);

	Aviso& operator=(const Aviso& o);
};

#endif

