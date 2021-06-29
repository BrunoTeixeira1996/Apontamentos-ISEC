#include <iostream>
#include <string>
using namespace std; // aqui estamos a usar todos os std's

//using std::cout;
//using std::endl;
//using std::cin;
// este using faz com que nao seja preciso usar o std:: ... sempre que queremos usar o cout,cint e endl

// funções overloaded sao funções com o mesmo nome mas correspondem a funções diferentes (versões diferentes)


void f1e02a() {
	//:: chamam-se de scope operator
	//std::endl faz flush do buffer , é equivalente ao \n

	std::cout << "Nome: " << std::endl;
	char nome[50]; // declarado neste local porque é imediatamente antes da sua utilização
	std::cin >> nome;


	std::cout << "Idade:  " << std::endl;
	int idade;
	std::cin >> idade;

	std::cout << nome << " tem " << idade << std::endl;
}

void f1e03a() {


	std::cout << "Nome: " << std::endl;
	string nome;
	std::cin >> nome;
	nome = "Genoveva";
	std::cout << nome;


	std::cout << "Idade:  " << std::endl;
	int idade;
	std::cin >> idade;

	std::cout << nome << " tem " << idade << std::endl;
}


void exemplo2() {
string s1;

cout << s1 << endl;

string s2 = s1;
cout << s2 << endl;

string s3 = "Bom dia!!!";
cout << s3 << endl;

}


void exemplo3() {
	string s1, s2;

	cin >> s1 >> s2;

	if (s1 == s2) {
		cout << " as strings sao iguais" << endl;
	}
	else {
		if (s1 < s2) {  // comparação alfabética (conta o nr de letras)
			cout << s1 << " e mais pequena que " << s2 << endl;
		}
		else {
			cout << s2 << " e mais pequena que " << s1 << endl;
		}
	}
}

void exemplo4() {
	string palavra = "julieta";

	for (char letra : palavra) { // for char letra in palavra
		cout << letra << endl;   // cout cada letra e dá \n
	}
}

void exemplo5() {
	string frase;

	getline(cin, frase); // faz get da linha toda e precisa da (cin,string)
	for (char letra : frase) {
		cout << letra << endl;
	}
}

void exemplo6() {
	cout << "Nome: " << endl;
	string nome;
	getline(cin,nome);
	cout << nome;


	cout << "Idade:  " << endl;
	int idade;
	cin >> idade;

	cout << nome << " tem " << idade << endl;
}
/*
int main()
{

	//f1e02a();
	//f1e03a();
	//exemplo2();
	exemplo3();
	//exemplo4();
	//exemplo5();
	//exemplo6();

	return 0;

}
*/