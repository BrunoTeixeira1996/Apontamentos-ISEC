#include <iostream>
#include <string>
#include <sstream>

using namespace std;


void ex7() {

	string s;
	cout << "Insira o nome: ";
	getline(cin, s);

	
	bool flag = false;
	string palavra;

	for (char x : s) {
		if (x == ' ') {
			if (palavra == "Silva") {
				flag = true;
			}
			
			cout << palavra << endl;
			palavra = "";
		}
		else{
			palavra += x;
		}
	}

	if (flag) {
		cout << "Encontrei o Silva!" << endl;
	}

	cout << palavra << endl;

}

void exemplo1() {
	istringstream ss;
	istringstream s2("bom     dia      amigo");
	string palavra;
	while (s2 >> palavra) { /* s2 >> palavra , vai buscar a proxima palavra ao s2 e copia para a string palavra
							podemos usar tambem uma variavel boleana */
		cout << palavra << endl;
	}

	s2.str("outra string diferente");
	cout << s2.str() << endl;
}


void ex7iss() {
	string s;
	
	cout << "Insira o nome: ";
	getline(cin, s);

	istringstream linha(s);
	bool silva = false;
	string palavra;

	while (linha >> palavra) {
		if (palavra == "Silva") {
			silva = true;
		}
		cout << palavra << endl;
	}

	if (silva) {
		cout << "Ha aqui um silva";
	}
}

string int2string(int n) {
	string valores[10] = { "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez" };

	if (n < 1 || n > 10) {
		return "";
	}
	else {
		return valores[n - 1]; // retorna n-1 porque o dicionario começa no 0
	}

}

int string2int(string s) {
	string valores[10] = { "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez" };
	
	for (int i = 0; i < 10; i++) { // percorro o array
		if (s == valores[i]) {  // se encontrar a string no meu array
			return i + 1; // retorno o i+1
		}
	}

	return 0;
}

void ex9() {
	bool fim = true;
	int numero;
	string palavra;

	while (fim) { // enquanto o utilizador não escrever a palavra "fim"
		cout << "Introduza um numero de 1 a 10: ";
		if (cin >> numero) { // teste para ver se o cin recebeu um numero inteiro
			palavra = int2string(numero); // chamo a função int2string que retorna o numero em string
			if (palavra == "") { // se a funcao retornar uma string vazia, significa que o nr nao era válido
				cout << "Invalido" << endl;
			}
			else { // se nao, mostro no cout o numero em string
				cout << palavra << endl;
			}
		}
		else {  // caso o cin  nao receba um numero inteiro mas sim uma string
			cin.clear(); // limpo as flags com o cin.clear()
			cin >> palavra; // leio a string
			if (palavra == "fim") { // se for fim, vou terminar o programa
				fim = false;
			}
			else { // se nao for "fim"
				numero = string2int(palavra); // chamo a funcao string2int para me retornar o numero
				if (numero == 0) { // se essa funcao retornar um 0, significa que a string nao era válida
					cout << "invalido" << endl;
				}
				else {
					cout << numero << endl; // se nao, mostra o numero
				}
			}
		}
	}
}

/*TCP: FICHA 2: exercicio 1 , 1a) e 1b)*/

/*
int main() {
	ex9();

	//ex7();
	//exemplo1();
	//ex7iss();

	
	return 0;
}


*/