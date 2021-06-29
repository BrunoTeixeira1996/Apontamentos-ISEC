#include "agenda.h"


string Agenda::getAsString()const {
	ostringstream os;

	for (auto i : lista)
		os << "Nome: " << i->getNome() << " Tel: " << i->getTel() << endl;

	return os.str();
}

Agenda &Agenda::operator=(const Agenda &a) {
	if (this == &a)
		return *this;

	for (auto i : lista)
		delete i;
	lista.clear();

	for (auto i : a.lista) {
		Contacto* c = new Contacto(i->getNome(), i->getTel());
		lista.push_back(c);
	}

	return *this;
}

bool Agenda::gravaAgenda(const string& nomeFich) {
	ofstream os(nomeFich);

	if (!os)
		return false;

	for (auto c : lista)
		os << c->getTel() << " " << c->getNome() << endl;

	os.close();
	return true;
}

Agenda Agenda::leAgenda(const string& nomeFich) {
	ifstream ifs(nomeFich);

	if (!ifs)
		return Agenda(); // se nao consegui abrir o ficheiro, crio uma Agenda vazia
	
	Agenda lida;
	unsigned int num;
	string nome;

	while (ifs >> num && getline(ifs, nome)) { // enquanto conseguir ler do ficheiro
		lida.lista.push_back(new Contacto(nome, num)); // preenche uma Agenda com Contactos
	}

	ifs.close();

	return lida;
}