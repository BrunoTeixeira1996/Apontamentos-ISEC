#include "conta.h"

Conta::Conta(Pessoa* a): p(a) {
	saldo = 0;
}


bool Conta::deposita(int valor) {
	saldo += valor;

	return true;
}
bool Conta::levanta(int valor) {
	if (saldo > 0 && saldo > valor) {
		saldo -= valor;
		return true;
	}

	return false;
}

string Conta::getAsString()const {
	ostringstream os;
	os << p->getAsString() << " saldo: " << saldo;
	return os.str();

}