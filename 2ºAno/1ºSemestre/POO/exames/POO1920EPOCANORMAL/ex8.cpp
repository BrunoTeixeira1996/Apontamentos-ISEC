#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Plantas{
    int altura;
    int alt_max;
    float percentagem;
    
public:
    virtual int crescimento(int dist_separacao)const = 0;
};

class Parasitas{
    int crescimento(int cresc)const{}

};


class Hospedeiras: public Plantas{
    int distancia;
    Parasitas parasita;
public:
    int crescimento(int dist_separacao)const{}
};

class Plantacao{
    vector<Plantas*> plantas;
    void crescePlantas()const;
};

int main(){
    
}
