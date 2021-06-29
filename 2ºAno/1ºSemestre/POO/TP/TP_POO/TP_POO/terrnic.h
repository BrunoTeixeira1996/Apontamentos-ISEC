#ifndef TERRITORIO_INICIAL
#define TERRITORIO_INICIAL
#include <string>
#include <sstream>
#include "territorio.h"
using namespace std;

class TerrInic :
	public Territorio 
{
public:
	void recolher(int ano, int turno, int *ouro, int *prod);

	string getAsString()const;
	string getNomePrinc()const { return ""; }
	TerrInic* clone() { return new TerrInic(*this); }
	

	TerrInic();
	virtual ~TerrInic(){}
};

#endif // !TERRITORIO_INICIAL


