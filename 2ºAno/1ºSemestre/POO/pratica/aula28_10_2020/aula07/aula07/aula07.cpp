#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <initializer_list>

using namespace std;

class Carro {
	//....
};

void mensagem_erro(initializer_list<string> msgs) {
	for (auto m : msgs)
		cout << m << " ";
	cout << endl;
}

/*
int main() {

	string esperado = "esperado XPTO", obtido = "obtido XXXX";

	if(obtido != esperado)
		mensagem_erro( {"funcao X: ", esperado, obtido} );
	else
		mensagem( {"funcao X: ", "ok"} );

	vector<int> veti;
	if (veti.empty()) {

		for (int i = 0; i < 30; i++) {
			veti.push_back(i);
		}

	}

	for (auto n : veti) {
		cout << n << " ";
	}
	cout << "\n";


	//vector<int> v = {1,2,3,4,5,6,7,8,9,10 }; // os numeros são a lista de inicializadores. pode ser com = ou sem =

	//for (auto n : v) {
	//	cout << n << " ";
	//}
	//cout << "\n";

	//for (auto &r : v) {
	//	r *= r; // r = r * r
	//}

	//for (int i = 0; i < v.size(); i++) {
	//	cout << v[i] << " ";
	//}





	//vector<int> veti;
	vector<int> veti2(veti); // mesma coisa que na linha 14
	vector<int> veti3 = veti; //inicialização por cópia

	vector<string> artigos = { "o","a","os","as" };
	vector<int> vetis(10, -1); // cria um vetor de tamanho 10 com valores inicializados com -1
	vector<string> vets2s();
	vector<string> vets2(5,"Ola");
	vector<Carro> garagem;

}

*/