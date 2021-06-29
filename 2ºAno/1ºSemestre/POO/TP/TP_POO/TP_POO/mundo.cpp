#include "mundo.h"

int Mundo::ano = 1;
int Mundo::turno = 1;

Mundo::Mundo()
{
}

Mundo::Mundo(const Mundo& imp) {
	*this = imp;
}

Mundo& Mundo::operator=(const Mundo& imp) {

	// limpamos a memoria
	for (auto i : territorio) {
		delete i;
	}
	territorio.clear();

	for (size_t i = 0; i < imp.territorio.size(); i++) {
		territorio.push_back(imp.territorio[i]->clone());
	}
	return *this;
}

Mundo::~Mundo()
{
	// limpa os ponteiros do vector territorio
	for (auto i : territorio) {
		delete i;
	}
	territorio.clear();
}

bool Mundo::incTurnoAno() {

	if (ano == 1 && turno < 6) {
		turno++;
		return true;
	}
	else if (ano == 1 && turno >= 6) {
		ano++;
		turno++;
		return true;
	}
	else if (ano == 2 && turno <= 12) {
		turno++;
		return true;
	}

	return false;
}

bool Mundo::novoTerritorio(Territorio *t) {
	if (t == nullptr)
		return false;

	territorio.push_back(t);
	return true;
}


bool Mundo::veTerritorio(string nome) {

	for (Territorio* ie : territorio) {
		if (nome == ie->getNome())
		{
			return true;
		}
	}
	return false;
}

Territorio* Mundo::retornaTerritorio(string nome) {

	for (Territorio* ie : territorio) {
		if (nome == ie->getNome())
			return ie;
	}

	return nullptr;
}

bool Mundo::eliminaTerritorio(string nome) {

	vector<Territorio*>::iterator it;

	for (it = territorio.begin(); it != territorio.end(); it++) {
		if ((*it)->getNome() == nome) {
			it = territorio.erase(it);
			return true;
		}
	}

	return false;
}

string Mundo::getTerritorios()const {
	ostringstream os;

	os <<"\t==========================" << endl
		<< "\t|| Territorios do Mundo ||" << endl
		<< "\t==========================" << endl << "\n";


	for (auto imp : territorio)
		os << imp->getAsString();

	return os.str();

}

