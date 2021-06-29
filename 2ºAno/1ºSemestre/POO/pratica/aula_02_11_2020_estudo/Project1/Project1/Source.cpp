
#include "ponto.h"
#include "retangulo.h"
#include "desenho.h"




int main() {


	Desenho b("Segundo");
	Retangulo r2({ 7,2 }, 3, 8);
	Retangulo r1({ 1,5 }, 4, 4);
	
	Retangulo r3({ 2,3 }, 1, 1);
	b.setRetOrd(r3);
	b.setRetOrd(r1);
	b.setRetOrd(r2);


	cout << b.getAsString();

	//b.remArea(2);

	//cout << "Removido \n";
	//cout << b.getAsString();

	//vector<string> c{ "como vai?", "tudo bem?" };

	//c.insert(c.begin(), "ola"); // insere "ola" no inicio do vector "c"

	//for (auto n : c)
	//	cout << n << " ";

	//vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	//auto it = v.begin();
	//while (it != v.end()) {
	//	if (*it % 2) {
	//		it = v.erase(it);
	//	}
	//	else {
	//		++it;
	//	}
	//}

	//it = v.begin();
	//while (it != v.end() && *it != 5) { // aponta pra o 5 do vector "v"
	//	++it;
	//}

	//if(it != v.end())
	//	v.erase(it, v.end()); //apaga desde o 5 (inclusive) até ao fim

	//for (auto n : v)
	//	cout << n << " ";




	//vector<int> v{ 1,2,3,4,5 };
	//vector<int>::iterator n = v.begin();

	//for (n = v.begin(); n != v.end(); n++) {
	//	*n = (*n) * 2;
	//	cout << *n << " ";
	//}

	//cout << endl;

	//vector<int>::const_iterator c = v.begin();

	//for (c = v.cbegin(); c != v.cend(); c++)
	//	cout << *c << " ";

	//auto b = v.begin();
	//if (b != v.end())
	//	cout << *b << " ";

	//for (auto b = v.begin(); b != v.end(); b++) {
	//	cout << *b << " ";
	//}

	//Ponto  a(1,2);
	//Ponto  b(3, 4);

	//cout << "Ponto A: " << a.getAsString() << endl;
	//cout << "Ponto B: " << b.getAsString() << endl;

	//cout << "Distancia entre A e B: " << a.getDist(b) << endl;

	//Ponto const c(5,6);
	///*c) o facto do Ponto ser constante, faz com que as funções que modificam os valores não sejam possiveis*/

	//a.setX(9);
	//a.setY(10);
	//cout << "Ponto A: " << a.getAsString() << endl;

	//Ponto d;
	//cout << "Ponto D: " << d.getAsString() << endl;

	//Ponto p1(1, 2);
	//Retangulo k(p1,10,20);

	//cout << k.getAsString() << endl;

	///*Construimos aqui um Ponto, implicitamente*/
	//k.setCanto({ 4,5 });

	//cout << k.getAsString() << endl;


}