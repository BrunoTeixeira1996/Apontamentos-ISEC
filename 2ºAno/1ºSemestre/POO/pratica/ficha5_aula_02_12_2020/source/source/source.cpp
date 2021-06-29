#include <iostream>
#include "agenda.h"
#include "contacto.h"


int main()
{
    Agenda a;
    a.adicionaContacto("Jose", 123123123);
    a.adicionaContacto("Bruno", 123123123);
    a.adicionaContacto("Teixeira", 123123123);
    cout <<"Agenda a: " << a.getAsString() << endl;

//    Agenda b(a);
 //   cout << "Agenda b: " << b.getAsString() << endl;;

    const string s = "agendaTeste.txt";
    if (a.gravaAgenda(s)) {
        cout << "Agenda gravada" << endl;
    }
    else {
        cout << "Agenda nao gravada :(" << endl;
    }

    Agenda b = Agenda::leAgenda(s);
    cout << "Agenda b: " << b.getAsString() << endl;
}
