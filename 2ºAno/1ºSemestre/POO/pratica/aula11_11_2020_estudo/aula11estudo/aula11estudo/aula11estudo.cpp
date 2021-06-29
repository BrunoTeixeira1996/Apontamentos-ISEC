#include <iostream>
#include "pessoa.h"
#include "conta.h"

using namespace std;

int main()
{
    Pessoa a("Alex", "123456789", 987654321);
    Conta c(&a);

    cout << c.getAsString();

    c.deposita(100);
    c.levanta(50);

    cout << c.getAsString();
}
