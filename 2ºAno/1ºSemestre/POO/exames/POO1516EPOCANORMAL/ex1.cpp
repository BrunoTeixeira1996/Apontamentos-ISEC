#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Ingredientes{
    string nome;
    float gramas;
    
public:
    static int nSerie;
    string tipo;
    
    virtual string getNome()const=0;
    virtual float getGramas()const=0;
    virtual int getNSerie()const=0;
    virtual string getAsString()const=0;
    virtual void setNome()=0;
    virtual void mudaGrama()=0;
    virtual string getTipo()const=0;
    
    
};
int Ingredientes::nSerie = 0;

class Batata: public Ingredientes{
    string nome;
    float gramas;
    int nSerie;
    string tipo;
public:
    Batata() = delete;
    Batata(string no,float gra) : nome(no), gramas(gra){
        nSerie = Ingredientes::nSerie++;
        tipo = "Batata";
    }
    
    string getNome()const{return nome;}
    float getGramas()const{return gramas;}
    int getNSerie()const{return nSerie;}
    string getTipo()const{return tipo;}
    
    string getAsString()const{
        ostringstream os;
        
        os << "Nome: " << nome << " Gramas: " << gramas
        << " N.Serie: " << nSerie << endl;
        
        return os.str();
    }
    
    void setNome(){nome = "Puré";}
    void mudaGrama(){gramas = gramas * 0.8;}
    
    
    
};

class Agua: public Ingredientes{
    string nome;
    float gramas;
    int nSerie;
    string tipo;
public:
    Agua() = delete;
    Agua(string no, float gra) : nome(no), gramas(gra){
        nSerie = Ingredientes::nSerie++;
        tipo = "Agua";
    }
    
    
    
    string getNome()const{return nome;}
    float getGramas()const{return gramas;}
    int getNSerie()const{return nSerie;}
    string getTipo()const{return tipo;}
    
    string getAsString()const{
        ostringstream os;
        
        os << "Nome: " << nome << " Gramas: " << gramas
        << " N.Serie: " << nSerie << endl;
        
        return os.str();
    }
    
   void setNome(){}
   void mudaGrama(){}
    
};

class Tacho{
  int temperatura;
  float gramas;
  vector<Ingredientes*>ingredientes;
  
public:
    Tacho(float gra) : gramas(gra){
        temperatura = 5;
    }
    
    void insereIngredientes(Ingredientes *p){
        float aux = 0;
        for(auto a : ingredientes){
            aux += a->getGramas();
        }
        
        if(temperatura <= 50 && p->getTipo() == "Batata"){
            if((p->getGramas() + aux) <= gramas){
                ingredientes.push_back(p);
                return;
            }
            else{
                return;
            }
        }
        else if(temperatura > 50 && p->getTipo() == "Batata"){
            p->setNome();
            p->mudaGrama();
            if((p->getGramas() + aux) <= gramas){
                ingredientes.push_back(p);
                return;
            }
        }
        else if(p->getTipo() == "Agua"){
            if((p->getGramas() + aux) <= gramas){
                ingredientes.push_back(p);
                return;
            }
            return;
            
        }
        
    }
    void setAumentaTemp(int temp){
        if(temperatura >= 50){
            temperatura += temp/2;
        }
        else{
            temperatura += temp;
        }
    }
    
    void setDiminuiTemp(int temp){
        if(temp <= temperatura)
            temperatura -= temp;
        else
            return;
    }
    
    void esvaziaTacho(){
        for(auto it = ingredientes.begin(); it != ingredientes.end(); it++){
            it = ingredientes.erase(it);
        }
        
        ingredientes.clear();
    }
    
    string getAsString()const{
        ostringstream os;
        
        os << "Temperatura: " << temperatura
        << " Gramas atuais: " << gramas << endl;
        
        for(auto a: ingredientes){
            os << a->getAsString();
        }
            
        return os.str();
    }
    
};


int main()
{
    Ingredientes *p1 = new Batata("Batatinha",2.3);
    Ingredientes *p2 = new Agua("Agua gelada",2.1);
    Ingredientes *p3 = new Batata("Batata Doce",2.9);
    Ingredientes *p4 = new Agua("Agua Doce",34);

    
    Tacho ta(100);
    
    
    ta.insereIngredientes(p1);
    ta.insereIngredientes(p2);
    ta.insereIngredientes(p3);
    ta.insereIngredientes(p4);
    ta.setAumentaTemp(50);
    
    cout << ta.getAsString() << endl;

   //incompleto
   
   return 0;
}
