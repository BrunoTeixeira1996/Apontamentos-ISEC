#include "Prego.h"
#include "Aviso.h"


int main()
{

	Prego *p = new Prego(3, 4);


	Aviso *a = new Aviso("Mensagem A", p);

	cout << p->listaAvisos();

	Aviso* c = new Aviso("Mensagem C", p);

	Aviso e(*a);
	*a = *c;



	//delete c;
	//c = nullptr;

	//cout << "depois de apagado: " << p->listaAvisos();

	//delete p;
	//p = nullptr;

	//cout << "aviso a: " << a.getAsString() << endl;

	return 0;
}