#include "territorio.h"


void Territorio::setNome(string n) {
	nome = n;
	if (numObj != 0) {
		nome += to_string(numObj);
	}
}

void Territorio::setNumObj(int num) {
	numObj = num; 
	if (nome.empty()) {

		nome = getNomePrinc() + to_string(numObj);
	}
	else {
		nome += to_string(numObj);
	}
}

Territorio::Territorio()
{
}

string Territorio::getAsString()const {
	ostringstream os;

	os << "  " << nome << " Resistencia: "<< resistencia 
	<< " Ouro: " << ouro << " Produto: " << produto << endl;

	return os.str();
}