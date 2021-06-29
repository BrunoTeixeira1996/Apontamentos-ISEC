#include "MSG.h"

MSG &teste() {
	MSG aux('y');

	return aux;
}

int main() {

	//MSG a('a');
	MSG b;
	string enter;
	//MSG d = b;

	//MSG &c = b; //aqui não é criado nenhum objeto, é apenas uma referência para o b

	//MSG d = b; //aqui estamos a criar um objeto e conseguimos ver o Objeto d a ser destruido (contrutor por cópia)

	//cout << "a variavel a: " << a.getAsString() << "\n";
	//a = b; //aqui estamos atribuir o Objeto "b" ao Objeto "a" (atribuição)
	//cout << "a variavel a: " << a.getAsString() << "\n";


	//string enter;
	//getline(cin, enter);

	////MSG mat[2]; //aqui são criados 2 objetos
	////MSG mate[2] = { 'e' , 'f'}; //aqui são criados dois objetos com a letra "e" e letra "f"
	getline(cin, enter);

	teste();
	getline(cin, enter);
	/*cout << "a variavel a: " << a.getAsString() << "\n";
	cout << "a variavel b: " << b.getAsString() << "\n";*/



	return 0;
}