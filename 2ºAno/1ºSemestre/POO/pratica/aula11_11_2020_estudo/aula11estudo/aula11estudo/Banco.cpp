#include "banco.h"

string Banco::getAsString()const {
	ostringstream os;

	os << nome;
	for (auto i : contass) {
		os << " " << i.getAsString() << endl;
	}

	return os.str();
}

bool Banco::deposita(const string& bi, int quantia) {

	for (Conta& c : contass) {
		if (c.getTitular()->getCC() == bi) {
			return c.deposita(quantia);
		}
	}
	return false;
}

bool Banco::addConta(Conta c) {
	contass.push_back(c);

	return true;
}

bool delConta(const string& bi) {
	auto it = contass.begin();



	for (it = contass.begin(); it != contass.end(); it++) {
		if (it->getTitular()->getCC() == bi) {
			contass.erase(it);
			return true;
		}
	}
}
