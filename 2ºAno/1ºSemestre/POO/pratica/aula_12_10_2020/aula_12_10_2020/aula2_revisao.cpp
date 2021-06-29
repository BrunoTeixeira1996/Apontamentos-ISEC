#include <iostream>
#include <string>

using namespace std;

void exemplo33() {

	/*Ao falhar a leitura existem umas flags de estado que
	avisam que ocorreu um erro e o cin fica logo desativado
	*/

	cout << "leitura como um int" << endl;
	cout << "introduza um numero: ";
	int n;
	cin >> n;
	cout << "valor lido: " << n << endl;

	cout << "leitura como uma string" << endl;
	cout << "introduza uma string: ";
	string s;
	cin >> s;
	cout << "valor lido: " << s << endl;
	
}

void exemplo23() { /*Usando o exemplo 33 mas com o cin.clear()*/

	/*O clear coloca as flags de estado ao seu estado normal*/

	cout << "leitura como um int" << endl;
	cout << "introduza um numero: ";
	int n;
	cin >> n;
	cout << "valor lido: " << n << endl;

	cout << "leitura como uma string" << endl;
	cout << "introduza uma string: ";
	cin.clear();
	string s;
	cin >> s;
	cout << "valor lido: " << s << endl;

}

void exemplo43() { /*Usando o exemplo 33 mas com o cin.clear() e com o cin.ignore(int,int)*/

				   /*O ignore(256,'\n') vai ignorar os primeiros 256 chars e até atingir um \n inclusive*/
	

	cout << "leitura como um int" << endl;
	cout << "introduza um numero: ";
	int n;
	cin >> n;
	cout << "valor lido: " << n << endl;

	cout << "leitura como uma string" << endl;
	cout << "introduza uma string: ";
	cin.clear();
	cin.ignore(256,'\n');
	string s;
	cin >> s;
	cout << "valor lido: " << s << endl;

}

void exemplo53() { /*Usando o exemplo 33 mas com o cin.clear() e com o cin.ignore(int,int)*/

				   /*Testar o cin.clear()*/


	cout << "leitura como um int" << endl;
	cout << "introduza um numero: ";
	int n;
	cin >> n;
	cout << "valor lido: " << n << endl;

	if (cin.good()) { /*se a leitura do cin foi feita com sucesso*/
		cout << "leitura como uma string: ";
	}
	else { /*se a leitura do cin não foi feita com sucesso*/
		cout << "ocorreu um erro na leitura" << endl;
		cout << "limpando as flags com o cin.clear()" << endl;
		cout << "limpando o buffer com o cin.ignore()" << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "leitura como uma string: ";
	}


	string s;
	cin >> s;
	cout << "valor lido: " << s << endl;

}

void exemplo63() {

	cout << "introduza a idade: ";
	int idade;
	cin >> idade;

	while (!cin.good()) {
		cout << "formato errado" << endl;
		cin.clear(); /*limpa as flags*/
		cin.ignore(1024, '\n'); /*da flush no buffer*/
		cout << "introduza a idade: "; 
		cin >> idade;
	}

	cout << "introduza o nome: ";
	string nome;
	cin.ignore(); /*ignora o \n do cin para ler a string direito*/
	getline(cin, nome);
	
	cout << "Nome: " << nome << " Idade: " << idade << endl;

}

void imprime(string s) {
	cout << s << endl;
}

void imprime(string s, int num) {
	cout << s << num << endl;
}

void imprime(int num, string s) {
	cout << num << s << endl;
}

/*Acrescenta n carateres c ao final da string s*/
string exemplo123(string s, char c = 's', int n = 1) {

	for (int i = 0; i < n; i++) {
		s += c;
	}

	return s;
}

int somas() {
	return 0;
}

int somas(int a) {
	return a;
}

int somas(int a, int b) {
	return a + b;
}

int somas(int a, int b, int c) {
	return a + b + c;
}

void exemplo69() {
	int i = 1024;
	cout << i << endl;

	int &refI = i;

	refI = 10;
	cout << i << endl;

	int &refE = refI;

	refE = 20;

	cout << i << endl;
}

void resete(int &i) {
	i = 0;
}

void trocas(int &a, int &b) {
	int temp = 0;

	temp = a;
	a = b;
	b = temp;
}

void trocadilhos(int *a, int *b) {
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

void nomes(string s) {
	string palavra;
	int flag = 0;

	for (char x : s) { // for x in s
		if (x == ' ') { // se for espaco
			if (palavra == "Silva") {
				flag = 1;
			}
			cout << palavra << endl; // mostra a palavra
			palavra = ""; // limpo a palavra
		}
		else {
			palavra += x; // adiciona um char à palavra ainda por terminar
		}
	}

	cout << palavra << endl;
	if (flag) {
		cout << "Hey, eu conheço alguem com o nome Silva!" << endl;
	}
}

int main() {

	//exemplo33();
	//exemplo23();
	//exemplo43();
	//exemplo53();
	//exemplo63();

	/*Funções overloaded*/
	//imprime("ola");
	//imprime("a idade e: ", 25);
	//imprime(100, "euros");

	/*Função com parâmetros por omissão*/
	//cout << exemplo123("Bruno") << endl;
	//cout << exemplo123("Bruno", 'O', 4) << endl;
	//cout << exemplo123("Bruno", 'X') << endl;

	/*Funções overloading*/
	//cout << "\n" << somas() << " " << somas(1) << " " << somas(1, 2) << " " << somas(1,2, 3) << endl;

	/*Variaveis do tipo referência*/
	//exemplo69();

    /*Passagem por copia não altera o valor*/
	/*
	int a = 1024;
	cout << "Antes: " << a << endl;
	reset(a);
	cout << "Depois: " << a << endl ;
	*/
	
	/*Passagem por referência altera porque passamos por referência*/
	/*
	int a = 1024;
	cout << "Antes: " << a << endl;

	resete(a);
	cout << "Depois: " << a << endl;
	*/
	
	/*Passagem por referência*/
	/*
	int a = 5, b = 10;

	cout << "Antes: " << a << " " << b << endl;
	
	trocas(a, b);
	cout << "Antes: " << a << " " << b << endl;
	*/
	
	/*Usando agora ponteiros em vez de referência*/

	/*
	int a = 5, b = 10;

	cout << "Antes: " << a << " " << b << endl;

	trocadilhos(&a, &b);
	cout << "Antes: " << a << " " << b << endl;
	*/

	string b = "Bruno Alexandre      Silva Pinto Teixeira";

	nomes(b);
	return 0;
}