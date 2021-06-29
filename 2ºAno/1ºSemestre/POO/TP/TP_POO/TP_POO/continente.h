#ifndef CONTINENTE_H
#define CONTINENTE_H
#include "territorio.h"

using namespace std;

class Continente :
	public Territorio
{
public:

	Continente();
	virtual ~Continente(){}
};



#endif // !CONTINENTE_H