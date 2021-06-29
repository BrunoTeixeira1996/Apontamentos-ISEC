#ifndef  MUNDO_H
#define MUNDO_H
#include <vector>
#include <string>
#include <sstream>
#include "territorio.h"

using namespace std;

class Mundo
{
	vector<Territorio*>territorio;
public:
	Mundo();
	Mundo(const Mundo& imp); // construtor por copia
	~Mundo();

	Mundo& operator=(const Mundo& imp); // operador de atribuicao



	//get
	vector<Territorio*>getMundo() { return territorio; }
	bool veTerritorio(string nome); // verifica se um certo dado Territorio(nome) existe no vector territorio
	int getImpSupremo() { return territorio.size() == 0 ? 3 : 0; }
	Territorio* retornaTerritorio(string nome); // retorna um ponteiro do tipo Territorio 

	// set
	bool novoTerritorio(Territorio* t);
	bool eliminaTerritorio(string nome);

	static int ano;
	static int turno;

	static int getAno() { return ano; }
	static int getTurno() { return turno; }

	string getTerritorios()const;

	bool incTurnoAno();

};


#endif // ! MUNDO_H


