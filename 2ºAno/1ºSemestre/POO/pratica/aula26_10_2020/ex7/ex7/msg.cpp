#include "msg.h"
using namespace std;

int MSG::prox = 1;

MSG::MSG(char l) : letra(l), numero(prox++) {
	cout << "Criado : letra : " << letra << " numero: " << numero << "\n";
}

MSG::MSG(const MSG &z) {
	letra = z.letra;
	numero = z.numero;
	cout << "Criado por copia: letra : " << letra << " numero: " << numero << "\n";
}

string MSG::getAsString() const {
	ostringstream os;
	os << "letra: " << letra << " numero " << numero;
	return os.str();
}

MSG::~MSG() {
	cout << "Terminado : letra : " << letra << " numero: " << numero << "\n";
}