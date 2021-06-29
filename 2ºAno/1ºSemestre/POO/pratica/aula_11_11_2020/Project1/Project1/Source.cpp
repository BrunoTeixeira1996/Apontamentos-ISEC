#include "pessoa.h"
#include "conta.h"
#include "banco.h"
#include <fstream>

bool getDadosPessoa(istream &is, string &n, string &ncc, int &nif) {
	getline(is, n);
	is >> ncc >> nif;

	if (is.fail() == true) {
		is.clear();
		n = "";
		ncc = "";
		nif = -1;
		return false;
	}
	return true;
}

int main() {
	Pessoa a("Alex", "12345678", 987654321);

	cout << "Pessoa a: " << a.getAsString() << endl;

	Conta c(&a);

	Banco b("Banco XPTO");
	cout << "Banco b: " << b.getAsString() << endl;

	b.addConta(c);

	cout << "Banco b com 1 conta: " << b.getAsString() << endl;


	//cout << c.getAsString() << endl;

	//c.deposita(100);
	//cout << "Conta c depois de depositar: " << c.getAsString() << endl;

	//c.levanta(50);
	//cout << "Conta c depois de levantar: " << c.getAsString() << endl;

	//Conta c2(a);

	//cout << "Conta c2: " << c2.getAsString() << endl;

	//Banco ba("Banco 1");

	//cout << ba.getAsString();

	//cout << "Novo nome: ";
	//string name;
	//getline(cin, name);
	//a.setNome(name);
	//cout << "Pessoa a: " << a.getAsString() << endl;

	return 0;
}