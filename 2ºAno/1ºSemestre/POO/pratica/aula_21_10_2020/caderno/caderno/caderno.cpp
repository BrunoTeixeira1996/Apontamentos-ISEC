#include <iostream>
#include <string>
using namespace std;

class Caderno {
	// os que estao a const não podem ser alterados
	// se nao usarmos os : no construtor temos de tirar o const daqui
	const string marca;
	const string cor;
	const double altura; // em cm
	const double largura; // em cm
	int nPag;
	string local;
	string conteudo;
	bool aberto = false; // para ver se o caderno está aberto
	int pagAtual = 1; // quando crio um ojeto a pagina atual será a 1


public:
	//construtor
	Caderno(string m, string c, double a, double l, int n);

	//acessores
	string getMarca() const;
	string getCor() const;
	double getAltura() const;
	double getLargura() const;
	int getNumPag() const;
	string getLocal() const;
	string getConteudo() const;

	//modifcadores
	void setAbrir();
	void setFechar();
	bool setEscreve(string texto);
	bool setViraPagina();

};

Caderno::Caderno(string m, string c, double a, double l, int n) :
	marca(m), cor(c), altura(a), largura(1), nPag(n) {
	if (nPag < 1)
		nPag = 1;

	conteudo = "Pag. 1: ";
}

//acessores
string Caderno::getMarca() const { return marca; }
string Caderno::getCor() const { return cor; }
double Caderno::getAltura() const { return altura; }
double Caderno::getLargura() const { return largura; }
int Caderno::getNumPag() const { return nPag; }
string Caderno::getLocal() const { return local; }
string Caderno::getConteudo() const { return conteudo; }

//modificadores
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
	if (aberto && pagAtual != nPag) {
		pagAtual++;
		conteudo += "\nPag. " + to_string(pagAtual) + ": ";
		return true;
	}
	return false;

}

int main() {
	Caderno c("Oxford","verde",50,30,2);
	c.setAbrir();
	c.setEscreve("Era uma noite escura de tempestade.\n");
	if (c.setViraPagina()) {
		c.setEscreve("E no dia seguinte voltou a chover\n");
		cout << "Conteudo do caderno: " << c.getConteudo() << "\n";
	}
	else {
		cout << "Nao consegui virar + escrever no caderno\n";
	}



/*	if (c.setEscreve("Era uma noite escura de tempestade.\n"))
		cout << c.getConteudo();
	else
		cout << "Não consegui escrever no caderno\n";
	//cout << "Conteudo do caderno: " << c.getConteudo() << "\n";
	//cout << "numero de paginas: " << c.getNumPag() << "\n";
	*/
}

// TPC dividir o ficheiro em 3 ficheiros