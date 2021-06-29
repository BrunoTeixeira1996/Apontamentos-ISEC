#ifndef LOGICA_H
#define LOGICA_H
#include <cctype>         
#include <sstream>
#include "mundo.h"
#include "terrnic.h"
#include "territorio.h"
#include "planicie.h"
#include "castelo.h"
#include "duna.h"
#include "fortaleza.h"
#include "mina.h"
#include "montanha.h"
#include "refpiratas.h"
#include "pescaria.h"
#include "imperio.h"
using namespace std;

class Logica
{
	
	Mundo mundo;
	Imperio imperio;

public:
	bool addTerritorio(string tipo, int quantidade); // add Territorios ao mundo (com os comandos "cria" e "carrega")
	string conqTerritorio(string nome); // conqTerritorios serve para conquistar Territorios(com o comando "conquista")
	bool modificaDados(string tipo, int quantidade);  //modifica a quantidade de ouro ou produtos [DEBUG]
	bool recolheRecursos(); // recolhe recursos
	string comandoMais(string comando); // "maisouro" e "maisprod"
	string comandoMaisMilitar(); // "maismilitar"
	string comandoAdquire(string tipo); // "adquire"
	string faseEvento(bool *flag_exit); // fase de eventos

	string comandoToma(string qual, string nome); // "toma"
	string comandoFEvento(string nome);	//"fevento"

	void passaTurno(int* ano, int* turno);
	string terminaJogo(); 



	string infoTerrImp(); // informacao do imperio
	string infoTerrMundo(); // informacao do mundo
	string infoTerritorio(string nome);	// informação de um territorio
	string infoAnoTurno(); // informação sobre o ano e turno
	string infoTecnologias();

	Logica();
	~Logica();
};

#endif