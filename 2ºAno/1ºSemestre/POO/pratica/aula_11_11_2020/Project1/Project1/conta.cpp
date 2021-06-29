#include "conta.h"



Conta::Conta(Pessoa *p) : saldo(0), pe(p)
{
}

int Conta::getSaldo()const {
	return saldo;
}

const Pessoa *Conta::getTitular()const { // referencia para Pessoa constante
	return pe;
}

bool Conta::deposita(int val) {
	if (val > 0) {
		saldo += val;
		return true;
	}
	return false;
}

bool Conta::levanta(int val) {
	if (val > 0 && saldo >= val) {
		saldo -= val;
		return true;
	}
	return false;
}

string Conta::getAsString()const {
	ostringstream os;
	os << "Saldo: " << saldo << " Pessoa: " << pe->getAsString() << endl;

	return os.str();
}