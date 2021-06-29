#include <iostream>
#include <string>
#include <sstream>


using namespace std;

struct Tabela {
	// 4 linhas , 3 colunas
	int matriz[4][3];

};

void preenche(Tabela &t, int n) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			t.matriz[i][j] = n;
		}
	}
}

void mostra(Tabela t) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << t.matriz[i][j] << " ";
		}
		cout << "\n";
	}
}


/*
int main() {

	Tabela matriz;

	preenche(matriz, 10);
	mostra(matriz);



	return 0;
}

*/