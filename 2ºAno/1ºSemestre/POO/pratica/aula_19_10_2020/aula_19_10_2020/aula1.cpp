#include <iostream>
#include <string>
#include <sstream>


using namespace std;
#define N 15

struct Tabela {
	int mat[N];
};

void preenches(Tabela &t, int n) {
	for (int i = 0; i < N; i++) {
		t.mat[i] = n;
	}
}

void mostras(Tabela t) {
	for (int i = 0; i < N; i++) {
		cout << t.mat[i] << endl;
	}
}

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
/*
int main() {

	Tabela t;
	
	preenches(t, 10);
	*/

	//mostras(t);
	
	
	//cout << elementoAt(t, 3) << endl;
	
	/*
	if (mudaElemento(t, 3, 3)) {
		cout << elementoAt(t, 3) << endl;
	}
	else {
		cout << "Não mudou" << endl;
	}
	*/
	/*
	string a = "Bruno Teixeira";
	string b = "bom dia";
	cout << maisCurta(a,b) << endl;
	maisCurta(a, b) = "vou mudar";
	cout << maisCurta(a, b) << endl;
	*/
/*
	
	cout << elementoEm(t, 10) << endl;;
	elementoEm(t, 10) = 15;
	cout << elementoEm(t, 10) << endl;

	return 0;
}
*/
