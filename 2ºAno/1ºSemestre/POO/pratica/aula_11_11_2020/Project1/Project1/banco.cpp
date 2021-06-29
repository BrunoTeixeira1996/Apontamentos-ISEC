#include "banco.h"



Banco::Banco(string no) : nome(no)
{
}

string Banco::getAsString()const {
	ostringstream os;

	os << nome << endl;

	for (auto c : contas)
		os << "Contas: " << c.getAsString() << " ";

	return os.str();
}

bool Banco::deposita(const string &bi, int valor) {
	for (Conta c : contas) {
		if (c.getTitular().getCC() == bi) {
			return c.deposita(valor);
		}
	}

	return false;
}

bool Banco::addConta(const Conta &c) {
	contas.push_back(c);

	return true;
}
/*os vectors não aceitam referencias porque as referencias nao sao erasable*/
bool Banco::delConta(const string &bi) {
	auto it = contas.begin();

	for (it = contas.begin(); it != contas.end(); it++) {
		if (it->getTitular().getCC() == bi) {
			it = contas.erase(it);
			return true;
		}
	}
	return false;

}