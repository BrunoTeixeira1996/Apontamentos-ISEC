#ifndef CADERNO_H
#define CADERNO_H
#include <string>
#include <iostream>

using namespace std;


class Caderno {
	const string marca;
	const string cor;
	const double altura;
	const double largura;
	int nPag;
	string local;
	string conteudo;
	bool aberto = false;
	int pagAtual = 1;

public:
	// construtor
	Caderno(string m, string c, double a, double l, int n);

	// acessores (get)
	string getMarca() const;
	string getCor() const;
	double getAltura() const;
	double getLargura() const;
	int getnPag() const;
	string getLocal() const;
	string getConteudo() const;
	int getnPalavras() const;

	// modificadores (set)
	void setAbrir();
	void setFechar();
	bool setEscreve(string texto);
	bool setViraPagina();


};



#endif