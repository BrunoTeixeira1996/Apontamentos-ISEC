#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Elementos{
  string titulo;
  int altura;
  int largura;
  
public:
    virtual string getTitulo()const{}
    virtual int getAltura()const{}
    virutal int getLargura()const{}
  
};


class Paragrafo:public Elementos{
    vector<string> conjunto;
public:
    string getTitulo()const override{}
    int getAltura()const override{}
    int getLargura()const override{}
};

class Figura:public Elementos{
    int **info_bin;
public:
    Figura(int l) : info_bin(l){}
    string getTitulo()const override{}
    int getAltura()const override{}
    int getLargura()const override{}
    
};

class Tabela:public Elementos{
    vector<int> conj;
public:
    Tabela(vector<int> ol) : conj(ol){}
    string getTitulo()const override{}
    int getAltura()const override{}
    int getLargura()const override{}
    
};

class Documento{
    string titulo;
    string autor;
    vector<Elementos*>elementos;
public:
    Documento(string ti,string aut, vector<Elementos*>ele) : titulo(ti), autor(aut), elementos(ele) {}
    
    void setElementos(){}
    void getElemento(){}
    void removeElementos(){} 
};



int main() {


}
