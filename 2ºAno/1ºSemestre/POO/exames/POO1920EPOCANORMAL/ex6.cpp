#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


class Bilhete {
  string passageiro;
  int passaporte;
  string & companhia;
  vector <int> id_malas;
    
public:
    Bilhete(string p, int pa, string &co, vector<int> ma) : passageiro(p), passaporte(pa), companhia(co), id_malas(ma) {companhia = co;}
    
    
    //operador de atribuicao
    Bilhete &operator=(const Bilhete &b){
        if (this == &b) { return *this; } //protege de uma potencial auto-atribuição
        passageiro = b.passageiro;
        passaporte = b.passaporte;
        
        id_malas.clear();

        for(size_t i = 0; i < b.id_malas.size(); i++){
            id_malas.push_back(b.id_malas[i]);
        }
      return *this;

    }
    string getAsString()const{
        ostringstream os;
        
        os << "Passageiro: " << passageiro << " Passaporte: " << passaporte << " Companhia: " 
        << companhia << " Malas: ";
        for(auto i : id_malas)
            os << " " << i;
            
        return os.str();
    }
    
    Bilhete &operator<<(int p){
        for(auto i : id_malas){
            if(p == id_malas[i])
                return *this;
        }
        
        id_malas.push_back(p);
        return *this;
    }
    
    Bilhete &operator-=(int id){
        auto it = id_malas.begin();
        
        while(it != id_malas.end()){
            if(id >= *it){
                it = id_malas.erase(it);
            }
            else{
                it++;
            }
            
        }

        return *this;
    }
};

ostream &operator<<(ostream &os, const Bilhete &b){
    return os << b.getAsString();
}


int main(){
    string ola = "ola";
    
    Bilhete bi("Bruno",123,ola,{1,30,3,40,5});
    Bilhete a("Rafael",123,ola,{3,4});
    
    //cout << bi << endl << a << endl;
    
    //bi << 123 << 789 << 123;
    
   (bi -= 20) -= 30;
    
    cout << bi;

}
