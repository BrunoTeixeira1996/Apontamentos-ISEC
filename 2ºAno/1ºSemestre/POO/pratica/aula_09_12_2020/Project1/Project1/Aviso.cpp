#include "Aviso.h"


Aviso::Aviso(const string t, Prego* p) : texto(t), a(p){
	a->addAviso(this);
}

Aviso::Aviso(const Aviso& o) {
	*this = o;
}



Aviso::~Aviso(){
	if (a)
		a->retiraAviso(this);
}

string Aviso::getAsString()const {
	ostringstream os;
	os << "Texto do Aviso: " << texto;
	if (a == nullptr)
		os << " na mesa";
	else
		os << " Coord. do Prego: " << a->getAsString();

	return os.str();
}

string Aviso::getLocal()const {
	return a->getLocal();
}


bool Aviso::saiDoPrego(Prego* p) {
	if (a != p) {
		return false;
	}
	a = nullptr;

	return true;
}


Aviso &Aviso::operator=(const Aviso& o) {
	if (this == &o) // se estou apontar para o mesmo endereço de memória, entao retorno -me a mim mesmo
		return *this;

	this->texto = o.texto; // copio o texto para o aviso

	if (this->a) // se tiver um prego
		a->retiraAviso(this); // elimino o aviso do prego

	a = o.a; // e o prego irá apontar para o prego do objeto "o"
	a->addAviso(this); // adiciono o aviso ao vector de avisos do Prego

	return *this;

}

