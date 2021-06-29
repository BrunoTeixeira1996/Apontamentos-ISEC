#include "Peixe.h"
#include "Aquario.h"

unsigned int Peixe::conta = 500;


Peixe::Peixe(const Peixe& p) {

	*this = p;
}

Peixe &Peixe::operator=(const Peixe& p) {
	if (this == &p || p.aquario != nullptr) // so atribui se peixe  destino fora de aquario
		return *this;

	this->conta = p.conta;
	this->cor = p.cor;
	this->especie = p.especie;
	this->indigestao = p.indigestao;
	this->nSerie = p.nSerie;
	this->peso = p.peso;
	this->resta = p.resta;

	if (p.aquario != nullptr)
		p.aquario->addPeixe(this);
	else
		this->aquario = nullptr;


	return *this;
}

string Peixe::getAsString()const {
	ostringstream os;
	os << "Numero de serie: " << nSerie << ", cor: " << cor << ", especie: " << especie;
	os << ", peso: " << peso;

	return os.str();

}



ostream& operator<<(ostream &os, const Peixe& p) {
	os << p.getAsString();

	return os;
}


bool Peixe::ligaAquario(Aquario* a) {
	if (a == nullptr || aquario != nullptr) // se o aquario que ele recebeu for invalido ou o aquario onde ele ja esta for válido
		return false;


	aquario = a;

	return true;
}

double getRealUniform();
void Peixe::come(unsigned int c) {
	if (indigestao) {
		if (resta > 0)
			--resta;
		return;
	}

	peso += c;

	if (peso > 50) {
		if (getRealUniform() > 0.5) {
			indigestao = true;
			peso /= 2;
		}
		else {
			peso = 40;
			Peixe* peixinho = new Peixe(especie+"D",cor);
			aquario->addPeixe(peixinho);
		}
	}
}