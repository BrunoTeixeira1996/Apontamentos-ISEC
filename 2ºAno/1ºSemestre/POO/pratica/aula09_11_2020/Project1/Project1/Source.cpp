#include "prego.h"
#include "aviso.h"


int main()
{
	
	Prego p(3, 4);

	//Aviso a("Aviso A", p);	
	//Aviso b("Aviso B",p);

	Aviso a("Aviso A", &p);
	Aviso b("Aviso B", &p);

	cout << a.getAsString() << endl;
	cout << b.getAsString() << endl;

	p.mudaDeSitio(6, 6);

	cout << a.getAsString() << endl;
	cout << b.getAsString() << endl;


	return 0;
}