#include <iostream>
#include <string>

using namespace std;

void exemplo1() {
	
	cout << "Introduza um numero: " << endl;
	cout << "leitura como um int: " << endl;

	int num;
	cin >> num;

	cout << "valor lido: " << num << endl;

	cout << "Introduza uma string: " << endl;
	cout << "leitura como um string: " << endl;

	string s;
	cin >> s;

	cout << "valor lido: " << s << endl;


}

void exemplo2() {

	cout << "Introduza um numero: " << endl;
	cout << "leitura como um int: " << endl;

	int num;
	cin >> num;
	cout << "valor lido: " << num << endl;

	cout << "Introduza uma string: " << endl;
	cout << "leitura como um string depois de cin.clear(): " << endl;
	cin.clear();

	string s;
	cin >> s;

	cout << "valor lido: " << s << endl;


}

void exemplo3() {

	cout << "Introduza um numero: " << endl;
	cout << "leitura como um int: " << endl;

	int num;
	cin >> num;
	cout << "valor lido: " << num << endl;

	cout << "Introduza uma string: " << endl;
	cout << "leitura como um string depois de cin.clear(): " << endl;
	cin.clear(); //limpa as flags de erro que são criadas quando o cin falha
	cin.ignore(256,'\n'); // ignora até 256 chars ou até atingir um \n
	

	string s;
	cin >> s;

	cout << "valor lido: " << s << endl;


}

void exemplo4() {

	cout << "Introduza um numero: " << endl;
	cout << "leitura como um int: " << endl;

	int num;
	cin >> num;
	cout << "valor lido: " << num << endl;

	cout << "Introduza uma string: " << endl;
	if (cin.good()) {
		cout << "leitura como um string: " << endl;
	}
	else {
		cout << "valor inválido" << endl;
		cout << "leitura como uma sring depois de cin.clear() e cin.ignora()";
		cin.clear();
	    cin.ignore(256, '\n'); // ignora até 256 chars ou até atingir um \n
	}
	
	string s;
	cin >> s;

	cout << "valor lido: " << s << endl;


}

void exemplo5() {
	
	cout << "Introduza a idade: ";


	int idade;
	cin >> idade;
	

	if (cin.good()) {
		cout << "Introduza o nome: " << endl;
	}
	else {
		cin.clear();
		cin.ignore(256,'\n');
	}

	string nome;
	cin.ignore(); // consome o \n
	//o cin.ignore só ignora apenas o 1º argumento, ou os 2 argumentos, não funciona se ignorarmos só o 2º argumento
	getline(cin, nome);

	cout << "Nome: " << nome << " Idade: " << idade;
}

void ex4ficha1(string s) {
	cout << s << endl;
}

void ex4ficha1(string s, int num){
	cout << s << num << endl;
}

void ex4ficha1(int quantia, string s) {
	cout << quantia << s << endl;
}

string exemplo7(string s, char c = 's', int n = 1) {
	//acrescenta n carateres c ao final da string s
	for (int i = 0; i < n; i++) {
		s += c; // s = s+c aqui esta a concatenar uma string
	}

	return s;
}


int soma() { // por overloaded
	return 0;
}

int soma(int a) {
	return a;
}

int soma(int a, int b) {
	return a + b;
}

int soma(int a, int b, int c) {
	return a + b + c;
}

int exemplo8(int a = 0, int b = 0, int c = 0) { // por omissao
	return a + b + c;
}

// o c++ tem um tipo composto chamdo de referencia (basicamente referirmo-nos a uma variavel por outro nome)
void exemplo9() {
	int i = 1024;

	cout << i << endl;

	int &refI = i; // o refI e o i referem-se exatamente ao mesmo endereço de memória
	refI = 10;

	cout << i << endl;

	// podemos ter um ponteiro para ponteiro
	// mas nao podemos ter uma referencia para referencia

	int &ref2 = refI;
	ref2 = 20;
	cout << i << endl;


}

void reset(int &i) {
	i = 0;
}

void troca(int *x, int *y) { // versao com referencia
	int aux = *x;
	*x = *y;
	*y = aux;
}

void troca(int &x, int &y) { // versao com referencia
	int aux = x;
	x = y;
	y = aux;
}
/*
int main() {

	//exemplo1();
	//exemplo2();
	//exemplo3();
	//exemplo4();
	//exemplo5();
	//ex4ficha1("ola"); //funcao overloaded
	//ex4ficha1("Ola", 25); // funcao overloaded
	//ex4ficha1(25, "Hello"); // funcao overloaded
	
	//no exemplo7 so podemos omitir os ultimos argumentos
	//cout << exemplo7("flor",'O',3) << endl;
	//cout << exemplo7("passarinho", 'X') << endl;
	//cout << exemplo7("carro") << endl;

	//ex5ficha1 com versoes overloaded
	//cout << "\n" << soma() << " " << soma(1) << " ";
	//cout << soma(1, 2) << " " << soma(1, 2, 3) << endl;

	//ex5ficha1 com versao com parametro por omissao
	//cout << "\n" << exemplo8() << " " << exemplo8(1) << " ";
	//cout << exemplo8(1, 2) << " " << exemplo8(1, 2, 3) << endl;

	//exemplo9();

	//int a = 1024;
	//cout << "antes: " << a << endl;

	//reset(a);

	//cout << "depois: " << a << endl;

	int a = 5, b = 10;
	troca(&a, &b);// versao com ponteiros
	cout << "\na = " << a << " b = " << b << endl;

	troca(a, b); // versao por referencia (é mais pratico mas mais perigoso porque temos de ir ver se é passado por referencia)
	cout << "\na = " << a << " b = " << b << endl;

}
*/