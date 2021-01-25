#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Fruta{
    
protected:
    static int conta;
    int id;
    float peso;

public:
    Fruta(float pe): peso(pe){
         id = conta++;
    }
    
    virtual float getPeso()const = 0;
    virtual int getID()const = 0;
    virtual void setPeso(int a)=0;
    virtual float setCrescer()=0;
    
};

int Fruta::conta = 1;

class Limao: public Fruta{
    
public:
    Limao() : Fruta(150){}
    
    float getPeso()const override{return peso;}
    int getID()const override{return id;}
    void setPeso(int a){peso = a;}
    float setCrescer(){return peso = peso * 1.15;}
    
};

class Laranja: public Fruta {
  
public: 
  Laranja(): Fruta(100){}
  
  float getPeso()const override{return peso;}
  int getID()const override{return id;}
  void setPeso(int a){peso = a;}
  float setCrescer(){return peso = peso * 1.10;}
};


class Arvore {
  vector <Fruta*> frutas;
  
public:
  Arvore() = default;
  
  void nascer(Fruta *x) {frutas.push_back(x);}
  
  void cair(int x) {
    for (auto i = frutas.begin(); i != frutas.end(); i++)
      if ((*i)->getID() == x){
          i = frutas.erase(i);
          return;
      } 
  }
  
  void crescer() {
    for (int i = 0; i < frutas.size(); i++)
        frutas[i]->setCrescer();
  }
  
  int getTotal() const {return frutas.size();}
  
  Fruta* getFruto(int i) const {return frutas[i];}
  
};

//Mostra o id e peso de todos os frutos da Arvore
ostream & operator << (ostream & out, Arvore & a) {
  for (int i = 0; i < a.getTotal(); i++)
    out << a.getFruto(i)->getID() << " " << a.getFruto(i)->getPeso() << endl;
    
  return out;
}
int main() {
    Arvore a;
    a.nascer(new Laranja());
    a.nascer(new Laranja());
    a.nascer(new Limao());
    
    cout << a << endl;
    
    a.crescer();
    
    cout << a << endl;

}
