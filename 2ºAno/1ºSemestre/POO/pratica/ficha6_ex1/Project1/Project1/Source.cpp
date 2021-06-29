#include <iostream>
#include <random>
#include <ctime>
#include "Aquario.h"
#include "Peixe.h"
#include "Piranha.h"

using namespace std;

double getRealUniform() {
	default_random_engine e(time(0));
	uniform_real_distribution<double> d(0.0, 1.0);

	return d(e);
}

int main() {


	Aquario *a = new Aquario();
	Piranha *p = new Piranha("Dory", "laranja",15);
	a->addPeixe(p);

	cout << *a << endl;

	Piranha *pp = new Piranha(*p);

	cout << *a << endl;

	Piranha x = *p;
	cout << x << endl;


	/*Piranha p("Nemo", "laranja", 15);

	cout << p << endl;

	Piranha p2(p);

	cout << p2 << endl;
*/
	//Peixe* pp = new Piranha("Nemo", "laranja");
	//delete pp;

	/*Peixe* p1;
	Peixe* p2;
	Peixe* p3;
	Peixe* p4;

	Aquario *a = new Aquario();

	a->addPeixe(new Piranha("Nemo", "laranja",15));
	a->addPeixe(new Peixe("Dory"));
	a->addPeixe(new Peixe("Bolhas", "amarelo"));
	a->addPeixe(new Piranha("Bruno"));

	cout << *a << endl;
	
	a->alimentaPeixes(5);

	cout << *a << endl;

	delete a;*/


	/*Aquario a;
	Peixe *p1 = new Peixe("Nemo","laranja");
	Peixe *p2 = new Peixe("Dory");
	Peixe* p3 = new Peixe("Bolhas", "amarelo");

	a.addPeixe(p1);
	a.addPeixe(p2);
	a.addPeixe(p3);*/

	//p1->come(50);
	//p2->come(50);
	//p3->come(50);

	/*cout << a << endl;
	
	a.alimentaPeixes(50);

	cout << a << endl;*/
}