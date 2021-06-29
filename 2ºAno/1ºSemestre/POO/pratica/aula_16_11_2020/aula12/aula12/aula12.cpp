#include <iostream>
#include "ponto.h"
#include "fracao.h"
#include "ponto3D.h"

using namespace std;

void tralala(Ponto3D p) {
    cout << "tralala" << endl;
    cout << "Ponto3D: "<< p << endl;
}

void func(int n) {
    cout << n;
}

int main()
{
     
    const Fracao f(7, 3);
    func(f); // é passado automaticamente o valor 7/3


    //Ponto a(10, 20);
    //cout << "Ponto a: " << a << endl;
    //tralala(a);

    //cout << "Introduza um ponto: ";
    //Ponto a;
    //cin >> a;
    //if (cin.fail()) {
    //    cin.clear();
    //    cout << "leitura falhou" << endl;
    //}
    //else
    //    cout << "Ponto a: " << a.getAsString();


    //Ponto a(10, 20);
    //cout << "Ponto a: " << a.getAsString() << "\n";

    //Ponto b = a++;
    //cout << "Ponto b: " << b.getAsString() << "\n";
    //cout << "Ponto a depois do incremento: " << a.getAsString() << "\n";

    /*Ponto a(1, 2);
    cout <<  "Ponto a: " <<a.getAsString() << endl;
    Ponto b(5, 5);
    cout << "Ponto b: " << b.getAsString() << endl;

    a += b;
    cout << "Ponto a depois da atribuicao composta:" << a << "\n";*/

   /* Fracao a(1, 2);
    Fracao b(3);
    const Fracao c(3, 4);

    cout << "a: " << a.getAsstring() << endl;
    cout << "b: " << b.getAsstring() << endl;
    cout << "c: " << c.getAsstring() << endl;
    cout << endl;

    Fracao d = a * b;
    cout << "d: " << d.getAsstring() << endl;

    Fracao e = a * b * c;
    cout << "e: " << e.getAsstring() << endl;

    Fracao f = a * 4;
    cout << "f: " << f.getAsstring() << endl;*/

    //Ponto a(10,20);
    //Ponto b(1, 2);
    //Ponto c = a + b;
    //cout <<  "Ponto c: " <<c.getAsString() << endl;

    //Ponto e = b + 2; // aqui soma ao Ponto b 2,0
    //cout << "Ponto e: " << e.getAsString()<< endl;

    //Ponto f = 4 + a; // aqui soma ao Ponto a 4,0
    //cout << "Ponto f: " << f.getAsString() << endl;


    //if (a == b)
    //    cout << " a igual  a b" << endl;
    //if (a != b)
    //    cout << "a diferente de b" << endl;

    //cout << "Ponto a: "<< a << endl;
    //cout << "Ponto b: " << b << endl;

    //Ponto d = ++a;
    //cout << "Ponto d: " << d << endl;
    //cout << "Ponto a: " << a << endl;
}


