#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Tabela {
	static const int N = 15;
	int mat[N];

public:
	Tabela(int v);
	void mostras() const; // o mostras() não altera o conteudo, logo colocamos a palavra const a forçar isso
	int &elementoEm(int pos);
	int getTamanho() const { return N; }; // metodo inline
};

void Tabela::mostras() const {
	for (int i = 0; i < N; i++) {
		cout << mat[i] << endl;
	}
}

int &Tabela::elementoEm(int pos) {
	if (pos > 0 && pos < N) {
		return mat[pos];
	}
	else {
		return mat[0];
	}
}

Tabela::Tabela(int v) { // construtor
	for (int i = 0; i < N; i++) {
		mat[i] = v;
	}
}


/*



int elementoAt(Tabela t, int pos) {
	if (pos > 0 && pos < N) {
		return t.mat[pos];
	}
	else {
		return 0;
	}
}

bool mudaElemento(Tabela &t, int pos, int valor) {
	if (pos > 0 && pos < N) {
		t.mat[pos] = valor;
		return true;
	}
	else {
		return false;
	}
}

string &maisCurta(string &s1, string &s2) {
	if (s1.size() < s2.size()) {
		return s1;
	}
	else {
		return s2;
	}
}

int &elementoEm(Tabela &t, int pos) {
	if (pos > 0 && pos < N) {
		return t.mat[pos];
	}
	else {
		return t.mat[0];
	}
}
*/

/*
int main() {
	Tabela a(0);

	//a.mostras();
	//cout << a.elementoEm(10);
	a.elementoEm(10) = 23;
	//a.mostras();
	cout << a.getTamanho() << endl;


	
	return 0;
}
*/