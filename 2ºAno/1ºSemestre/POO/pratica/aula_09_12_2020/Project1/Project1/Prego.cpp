#include "Prego.h"
#include "Aviso.h"

Prego::~Prego() {
	for (auto a : avisos)
		a->saiDoPrego(this);
}

string Prego::getAsString() const {
	ostringstream os;
	os << "Prego: " << x << "/" << y << endl;

	return os.str();
}

string Prego::getLocal()const {
	ostringstream os;
	os << "(" << x << "," << y << ")" << endl;

	return os.str();
}

bool Prego::addAviso(Aviso *a) {
	if (a == nullptr) {
		return false;
	}

	avisos.push_back(a);
	return true;
}

string Prego::listaAvisos()const {
	ostringstream os;

	for (auto a : avisos)
		os << a->getAsString() << endl;

		return os.str();
}

bool Prego::retiraAviso(Aviso* a) {
	vector<Aviso*>::iterator it = avisos.begin();

	while (it < avisos.end()) {
		if (*it == a) {
			it = avisos.erase(it);
			return true;
		}
		it++;
	}
	return false;
}