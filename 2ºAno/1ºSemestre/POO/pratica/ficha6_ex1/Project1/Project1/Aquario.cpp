#include "Aquario.h"


string Aquario::getAsString()const {
	ostringstream os;
	if (peixes.size() == 0) {
		os << "Aquario vazio" << endl;
	}
	else {
		os << "Peixes no aquario " << endl;
		for (auto p : peixes)
			os <<  " " << *p << endl;
	}

	return os.str();

}



ostream& operator<<(ostream& os, const Aquario& a) {
	os << a.getAsString();

	return os;
}

bool Aquario::addPeixe(Peixe* p) {
	if (p == nullptr) // ve se o p é null
		return false;

	if (p->ligaAquario(this) == false) // ve se o peixe conseguiu ligar-se ao aquario
		return false;

	peixes.push_back(p); // se conseguir ligar-se, insere-se o peixe no aquario
	
	return true;
}


void Aquario::alimentaPeixes(unsigned int q) {
	vector <Peixe*> copia = peixes;

	for (auto p : copia) {
		p->come(q);
	}
}

void Aquario::selfClean() {
	vector <Peixe*> copia = peixes;

	auto it = peixes.begin();

	while (it < peixes.end()) {
		if ((*it)->isVivo()) {
			++it;
		}
		else {
			delete (*it);
			it = peixes.erase(it);
		}
	}
}

