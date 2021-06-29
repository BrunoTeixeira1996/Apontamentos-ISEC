#include "clube.h"


Clube::Clube(unsigned int t) : tam(t) {
	socios = new Pessooa * [tam];
	for (unsigned int i = 0; i < tam; i++)
		socios[i] = nullptr;
}
Clube::~Clube() {
	if (socios)
		delete[] socios;
}

bool Clube::setMembroDoClube(Pessooa* p) {
	if (nSocios == tam)
		return false;
	socios[nSocios] = p;
	++nSocios;
	return true;
}

string Clube::getAsString()const {
	ostringstream os;
	os << "capacidade: " << tam << " numero de socios: " << nSocios << endl;

	Pessooa* ptr;
	for (unsigned int i = 0; i < nSocios; i++) {
		ptr = socios[i];
		os << ptr->getAsString() << endl;
	}

	return os.str();
}


ostream& operator<<(ostream& os, const Clube& p) {
	os << p.getAsString();
	return os;
}