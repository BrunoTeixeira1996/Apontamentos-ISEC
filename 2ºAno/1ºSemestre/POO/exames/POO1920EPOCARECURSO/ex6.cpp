#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Excursao {
  string data;
  const string destino;
  int lotacao;
  vector <int> inscritos;
  
public:
    Excursao(string da, string des, int lo) : data(da), destino(des), lotacao(lo){}
    
    
    // operador << copias do parâmetro para o vector do this
    Excursao &operator<<(int p){
        
        for(auto i : inscritos){
            if(p == i)
                return *this;
        }
        
        inscritos.push_back(p);
        return *this;
    }
    
    //operador >> , copia o array do this para o array do A
    Excursao &operator>>(Excursao &e){
        int lota = 0;
        
        for(int i = 0;  i < e.lotacao && i < inscritos.size(); i++){
            e.inscritos.push_back(inscritos[i]);
            lota++;
        }
        
        auto it = inscritos.begin();
        
        while(lota > 0){
                it = inscritos.erase(it);
                lota--;
        }
        
        return *this;
    }
    
    //operador "copia" this recebe o A
    Excursao &operator=(Excursao &p){
        auto it = inscritos.begin();
        
        while(it != inscritos.end()){
            it = inscritos.erase(it);
            it++;
        }
        
        data = p.data;
        lotacao = p.lotacao;
        
        p >> *this;
        
        return *this;
        
    }
    
    //operador[]
    int &operator[](int i){
        if(i > 0)
            return inscritos[i];
        else
            cout << "Erro";
    }
    
    //operador de conversao
    operator int()const{
        int contador = 0;
        for(auto a : inscritos)
            contador++;
        return contador;
    }
    
    

    
    string getAsString()const{
        ostringstream os;
        os << "Data: " << data << " Destino: " << destino << " Lotacao: " << lotacao
        << " Inscritos: ";
        for(auto a : inscritos)
            os << " " << a;
            
        return os.str();
    }
    
    
};

ostream &operator<<(ostream &os, const Excursao &e){
    return os << e.getAsString();
}

int main(){
    const string destino = "Porto";
    const string ola = "Lisboa";
    int a;
    
    Excursao excursao3("2020-10-01",destino,30);
    Excursao excursao2("2021-11-11",ola,30);
    
    excursao3 <<  123 << 456 << 789;
    
    cout << excursao3 << endl;
    
    a = excursao3;
    cout << "A: " << a << endl;
    
    cout << excursao3 << endl;
    //excursao3[2] = 666;
    
    //cout << excursao3 << endl;

    //excursao2 = excursao3;
    
    //cout << excursao2 << endl << excursao3;
    
    //excursao3 << 123 << 789 << 12 << 33 << 22 << 44 ;
    //cout << "Excursao 3: " << excursao3 << endl;
    
    
    //excursao3 >> excursao2;
    //cout << "Excursao 2: " << excursao2 << endl;
    
    //cout << "Excursao 3: " << excursao3 << endl;


}
