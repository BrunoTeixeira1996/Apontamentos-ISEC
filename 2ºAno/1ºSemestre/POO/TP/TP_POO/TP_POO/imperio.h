#ifndef IMPERIO_H
#define IMPERIO_H
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "territorio.h"
#include "terrnic.h"

using namespace std;
class Imperio
{
	int cofre = 1;
	int armazem = 1;
	int forca_militar = 3;
	int pontos_vitoria = 0;
	int sorte = 0;
	int num_tecnologia = 0;

	// Tecnologias
	bool drones_militares = false;
	bool misseis_teleguiados = false;
	bool defesas_territoriais = false;
	bool bolsa_valores = false;
	bool banco_central = false;

	vector<Territorio*> territorios;
public:
	Imperio();
	Imperio(const Imperio& imp); // construtor por copia
	~Imperio();

	Imperio& operator=(const Imperio& imp); // operador de atribuicao


	vector<Territorio*> getImperio() { return territorios ;}

	//sets
	bool insereTerritorio(Territorio* t);
	void decMilitar() {--forca_militar; }
	void setPontosVitoria(Territorio* t);
	void setOuroDebug(int n) { cofre = n; }
	void setProdDebug(int n) { armazem = n; }
	bool setRecolher(int ano, int turno);
	void setContaTecnologia();
	bool conqIlha();

	//maisouro e maisprod
	bool setMaisOuro();
	bool setMaisProd();

	//maismilitar
	bool setMaisMilitar();

	//gets
	int getCofre()const { return cofre; }
	int getArmazem()const { return armazem; }
	int getMilitar()const { return forca_militar; }
	int getFSorte(); // devolve o fator sorte entre 1-6 + forca_militar
	int getPontosVitoria()const { return pontos_vitoria; }
	int getSorte()const { return sorte; }
	string getAsString()const;
	int getContaTecnologia()const { return num_tecnologia; }
	int getBonusCientifico() { return num_tecnologia == 5 ? 1 : 0; }

	string getTerritorios()const;
	string getTecnologias()const;


	//gets das Tecnologias
	bool getDronesMilitares()const { return drones_militares; }
	bool getMisseisTeleguiados()const { return misseis_teleguiados; }
	bool getDefesasTerritoriais()const { return defesas_territoriais; }
	bool getBolsaValores()const { return bolsa_valores; }
	bool getBancoCentral()const { return banco_central; }
	string getInfoTecnologias()const;

	//sets das Tecnologias
	bool setDronesMilitares();
	bool setMisseisTeleguiados();
	bool setDefesasTerritoriais();
	bool setBolsaValores();
	bool setBancoCentral();

	//sets das Tecnologias DEBUG
	void setDEBUGDronesMilitares() { drones_militares = true; }
	void setDEBUGMisseisTeleguiados() { misseis_teleguiados = true; }
	void setDEBUGDefesasTerritoriais() { defesas_territoriais = true; }
	void setDEBUGBolsaValores() { bolsa_valores = true; }
	void setDEBUGBancoCentral() { banco_central = true; }

	//eventos
	bool recAbandonado(int ano); // Recurso Abandonado
	int evenInvasao(int ano); // Invasão
	bool aliDiplomatica(); // Aliança Diplomatica


	
};

#endif // !1

