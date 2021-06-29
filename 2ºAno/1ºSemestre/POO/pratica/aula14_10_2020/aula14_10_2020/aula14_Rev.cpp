#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void exempl321() {

	istringstream ss;
	istringstream s2("bruno bom dia tudo bem?");
	string palavra;

	while (s2 >> palavra) {
		cout << palavra << endl;
	}

	s2.str("ola pah, estamos bem?");

	cout << s2.str() << endl;
}

void pedeNome() {
	string nome; //crio a string nome

	cout << "Nome: "; // peço o nome
	getline(cin, nome); // uso o getline para ir buscar a linha completa

	istringstream palavra(nome); // coloco o nome numa istringstream

	string aux;
	bool flag = false;

	while (palavra >> aux) {
		cout << aux << endl;
		if (aux == "Silva") {
			flag = true;
		}
	}

	if (flag) {
		cout << "Encontrei um silva" << endl;
	}


	
}

/*
int main() {

	//exempl321();
	pedeNome();

	return 0;
}
*/