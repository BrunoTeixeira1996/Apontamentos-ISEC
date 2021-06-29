#include "aviso.h"



//Aviso::Aviso(string t, Prego &p) : texto(t), a(p)
//{
//	cout << "Construindo o Aviso... " << endl;
//}

Aviso::Aviso(string t, Prego *p) : texto(t), a(p)
{
	cout << "Construindo o Aviso... " << endl;
}


Aviso::~Aviso()
{
	cout << "Destruindo o Aviso ..." << endl;
}

string Aviso::getAsString()const {
	ostringstream os;
	//os << "Texto do Aviso: " << texto << " Coord. do Prego: " << a.getAsString();
	os << "Texto do Aviso: " << texto << " Coord. do Prego: " << a->getAsString();

	return os.str();
}

string Aviso::getLocal()const {
	//return a.getLocal();
	return a->getLocal();
}

