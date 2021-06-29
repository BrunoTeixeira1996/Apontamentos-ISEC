#ifndef AGENDA_H
#define AGENDA_h
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "contacto.h"


class Agenda
{
	vector<Contacto*> lista;

public:
	Agenda() = default; // a vantagem é nao ter de redifinir o construtor mas nao permitir que ele seja redifinido
	Agenda(const Agenda& a) { *this = a; }

	~Agenda() {
		for (auto i : lista) {
			delete i;
		}
		lista.clear();
	}

	Agenda& operator=(const Agenda &a);

	void adicionaContacto(string nome, unsigned int tel) 
	{
		lista.push_back(new Contacto(nome, tel));
	}

	string getAsString()const;

	bool gravaAgenda(const string& nomeFich);

	static Agenda leAgenda(const string& nomeFich);
};

#endif

