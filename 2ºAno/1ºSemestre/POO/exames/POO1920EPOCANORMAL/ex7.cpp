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
    virtual ~Funcionario(){} //invoca o destrutor de cada derivada
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
    
   ~Empresa() {
        for(auto funcionario : funcionarios)
            delete funcionario; // liberta memória dinâmica do funcionario
  }
  
  void cumprimentar()const{
      for(auto a : funcionarios)
        cout << a->cumprimentar();
  }
  
  // remove o engenheiro/doutor com esse nome do vector  
  void remove(string nome) 
  {  
     int posicao = 0; //Guarda posição onde se encontra no vetor
     for(auto funcionario : funcionarios)
     {
         if (funcionario->getNome() == nome)
         {
             delete funcionario; //liberta memoria dinâmica
             funcionarios.erase(funcionarios.begin() + posicao); //elimina essa celula do vetor
             break;
         }
         posicao++; //atualiza poisção
     }
 }

};

int main(){
    Empresa empresa;
    empresa.cumprimentar();

}
