#ifndef AQUARIO_H
#define AQUARIO_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "Peixe.h"

using namespace std;

class Aquario
{
	vector<Peixe*> peixes;

public:
	Aquario() = default;

	string getAsString()const;

	bool addPeixe(Peixe* p);
	void alimentaPeixes(unsigned int q);
	void selfClean();
};

ostream& operator<<(ostream& os, const Aquario& a);


#endif