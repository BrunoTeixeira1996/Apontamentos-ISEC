#include <iostream>
#include "ponto.h"
#include "retangulo.h"
#include "desenho.h"
#include <vector>



int main() {

	desenho d("Desenho 1");
	Retangulo r1({ 1,5 }, 1, 2);
	d.addRetangulo(r1);
	Retangulo r2({ 7,2 }, 42, 52);
	d.addRetangulo(r2);
	cout << d.getAsString();

	cout << "Eliminar\n";

	d.elimRetangulo(4);
	cout << d.getAsString();

	//vector<string> c{ "como vais?", "tudo bem?" };
	//c.insert(c.begin(), "ola");

	//for (auto n : c)
	//	cout << n << "\n";



	//vector<int> v{ 1,2,3,4,5,6,7,8,9};
	//auto it = v.begin();

	//while (it != v.end() && *it != 5)
	//	it++;

	//if(it != v.end())
	//	v.erase(it, v.end());

	//for (auto n : v)	/*o ranged base for nao permite que se altere a dimensão do vetor neste caso*/

	//	cout << n << " ";




	//while (it != v.end()) { /*remove os impares*/
	//	if (*it % 2)
	//		it = v.erase(it); /*muito importante isto, porque o it tem de apontar para o elemento seguinte ao do erase*/
	//	else
	//		++it;
	//}

	//auto b = v.begin(); // o iterador aponta para o primeiro elemento do vetor

	
	//vector<int>::iterator n = v.begin();

	////if (b != v.end()) //v.end() já está fora da coleção de dados (é o iterador para o primeiro objeto que está após o ultimo elemento)
	////	cout << *b;

	//for (n = v.begin(); n != v.end(); n++) {
	//	*n = *n * 2;
	//}

	//vector<int>::const_iterator c = v.cbegin(); /*Convem usarmos const_iterator para fazer couts de
	//											iterators uma vez que nao é preciso alterar nenhum conteudo*/

	//for (c = v.begin(); c != v.end(); c++) {
	//	cout << *c << " ";
	//}

	//Ponto a(1,2);
	//Ponto b(3, 4);
	//const Ponto c(5, 6);

	//cout << "Ponto a: " << a.getAsString();
	//cout << "Ponto b: " << b.getAsString();
	//cout << "Distancia entre a e b: " << a.getDist(b) << endl;

	//b.setX(5);
	//cout << "Ponto b: " << b.getAsString() << "\n";

	//Ponto p;
	//cout << "Ponto c: " << p.getAsString() << "\n";

	//Ponto p1(1,2);

	//Retangulo a(p1, 5, 6);
	//cout << "a: " << a.getAsString() << "\n";

	//Retangulo b(p1, 50, 60);
	//cout << "a: " << b.getAsString() << "\n";

	return 0;
}