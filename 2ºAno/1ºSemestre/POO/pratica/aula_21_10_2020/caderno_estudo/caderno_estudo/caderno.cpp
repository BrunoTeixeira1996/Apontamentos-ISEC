#include <iostream>
#include <string>
#include <sstream>
#include "caderno.h"
using namespace std;


Caderno::Caderno(string m, string c, double a, double l, int n) :
	marca(m), cor(c), altura(a), largura(l), nPag(n) {

	if (nPag < 1)
		nPag = 1;

	conteudo = "Pag. 1: ";
}

string Caderno::getMarca() const { return marca; }
string Caderno::getCor() const { return cor; }
double Caderno::getAltura() const { return altura; }
double Caderno::getLargura() const { return largura; }
int Caderno::getnPag() const { return nPag; }
string Caderno::getLocal() const { return local; }
string Caderno::getConteudo() const { return conteudo; }

int Caderno::getnPalavras() const {
	stringstream s(conteudo);
	string palavra;

	int conta = 0;
	while (s >> palavra) {
		if (palavra != "Pag.") {
		conta++;
		}
	}

	if (pagAtual >= 1) {
		return conta - pagAtual;
	}

	return conta;
};



void Caderno::setAbrir() { aberto = true; }
void Caderno::setFechar() { aberto = false; }
bool Caderno::setEscreve(string texto) {
	if (aberto) {
		conteudo += texto;
		return true;
	}
	
	return false;
}

bool Caderno::setViraPagina() {
	if (aberto && pagAtual < nPag) {
		++pagAtual;
		conteudo += "\nPag. " + to_string(pagAtual) + ": ";
		return true;
	}
	return false;
}


