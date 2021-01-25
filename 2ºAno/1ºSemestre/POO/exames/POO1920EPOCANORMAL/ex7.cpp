#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Funcionario{
protected:
    string nome;
public:
    Funcionario(const string &n): nome(n){}
    virtual string getNome()const = 0;
    virtual string cumprimentar()const = 0;
};

class Doutor: public Funcionario {

public: 
  Doutor(const string &no) : Funcionario(no){}
  string getNome() const override{return nome;}
  string cumprimentar() const override{
    ostringstream os;
    
    os << "Bom dia Doutor: " << getNome() << endl;
    
    return os.str();
  }
};

class Engenheiro: public Funcionario {
    
  public: 
  Engenheiro(const string & no): Funcionario(no){}
  string getNome() const override {return nome;}
  string cumprimentar() const override{
    ostringstream os;
    
    os << "Bom dia Engenheiro: " << getNome() << endl;
    
    return os.str();
  }
};

class Empresa {
  vector<Funcionario*>funcionarios;

public:
  Empresa() {
    funcionarios.push_back(new Doutor("D1"));
    funcionarios.push_back(new Doutor("D2"));
    funcionarios.push_back(new Engenheiro("E1"));
    funcionarios.push_back(new Engenheiro("E2"));
  }
  
  void cumprimentar()const{
      for(auto a : funcionarios)
        cout << a->cumprimentar();
  }

};

int main(){
    Empresa empresa;
    empresa.cumprimentar();

}
