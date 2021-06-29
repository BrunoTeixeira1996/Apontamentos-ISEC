#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "logica.h"
#include "Guarda.h"

using namespace std;


class Interface
{
	Logica logica;
	int flag_jogando = 0;		//para controlar quando estamos no modoJogo
	int flag_inicio = 0;  //para confirmar que user começou por criar territorio
	int flag_infoJogo = 0;  //para controlar quando se mostra a info do modo jogo

	bool flag_fase1 = false;  //para controlar o cout na fase1
	bool flag_conquista = false;   //para comando conquista
	bool flag_passa = false;    //para comando passa
	bool flag_mOuro = false;		//para comando maisouro
	bool flag_mProd = false;		//para comando maisprod
	bool flag_Maisvez = false;			//para controlar o uso do maisouro e maisprod
	bool flag_mMilitar = false;		//para mais militar
	
	bool flag_sair = false; // para terminar

	vector<Guarda*>armazenamentos;

public:
	Interface();
	~Interface();

	/*Preparacao*/
	int comeca(); // função que inicia o programa
	void veComando(string comando, string linha); //funcao que recebe comando e decide o modo
	void modoConfig(string linha); //funcao que recebe os comandos de config do jogo
	void modoJogo(string linha); // funcao que recebe os comandos de jogo

	/*Jogo*/
	void conquista(string tipo);
	void lista(); // informacao 
	void menuComandos();  //lista os comandos          
	void infoFase(int fase);  //print da fase atual
	void grava(string nome); // grava o estado do jogo em memoria
	void ativa(string nome); // recupera um dado estado do jogo em memoria
	void apaga(string nome); // apaga da memoria um dado estado do jogo
	void mostraJogos()const; // mostra saveGames
	void modifica(string tipo, int n);

	void modJFase1(string comando,string tipo , int *fase, string nome, int contaArg);
	void modJFase2(string comando, int *fase, string nome, string tipo, int contaArg);
	void modJFase3(string comando, string tipo,  int *fase, string nome, int *ano, int *turno, int contaArg);


	void resetFlags();

};

#endif
