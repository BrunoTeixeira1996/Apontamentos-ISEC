#ifndef ILHA_H
#define ILHA_H
#include <string>
#include <sstream>
#include "territorio.h"
using namespace std;




class Ilha :
	public Territorio
{
public:
	Ilha();
	virtual ~Ilha(){}
};


#endif // !ILHA_H


