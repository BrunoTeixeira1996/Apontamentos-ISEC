#include "Imobiliaria.h"


bool Imobiliaria::addImovel(Imovel* i) {
	if (i == nullptr)
		return false;

	for (auto p : imoveis) {
		if (p == i || p->getCodigo() == i->getCodigo()) // nao se pode ter as duas vezes o mesmo imovel
			return false;
	}


	imoveis.push_back(i);

	return true;
}

string Imobiliaria::getAsString()const {
	ostringstream os;

	os << "Nome: " << nome << endl;

	//Da de ambas as maneiras
	//for (int i = 0; i < imoveis.size(); i++) {
	//	os << " " << imoveis[i]->getAsString() << endl;
	//}

	for (auto p : imoveis)
		os << " " << p->getAsString() << endl;

	return os.str();
}

ostream& operator<<(ostream& os, const Imobiliaria& i) {
	os << i.getAsString();

	return os;
}