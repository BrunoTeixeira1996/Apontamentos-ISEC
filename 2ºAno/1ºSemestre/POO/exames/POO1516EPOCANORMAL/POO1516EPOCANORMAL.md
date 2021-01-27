
# Exercicio 1 a)

### Resposta
```
---1---
perimetro: 0
area: 0
---2---
perimetro:0
area:8
---3---
perimetro: 0
area: 0
---4---
```

# Exercicio 1 b)
### Resposta
Dá erro em p1->f() porque f() não é função membro de Figura mas sim de Rectangulo.
Da erro tambem na última linha uma vez que estamos a instanciar uma Figura a partir de um Rectangulo e devia de ser ao contrario.

# Exercicio 2

## Explicação
A class RelogioLuxo precisa de declarar a função virtual bool obtemTaxa uma vez que esta é uma função puramente virtual na sua classe Base.
Outro problema está no int escalao que devia estar dentro de protected e está em privado. Como não inicializamos o escalao dentro do RelogioLuxo é obrigatorio o int escalao ficar como protected.
Outro problema era a falta do construtor por omissão na classe Base e da sua inicialização na classe Derivada.

### Resposta

```cpp
#include <iostream>

class ItemLuxo {
protected:
    int escalao;
public:
    ItemLuxo() = default;
    ItemLuxo(int esc) {escalao = esc;}
    virtual bool obtemTaxa() = 0;
    virtual void atribuiEscalao(int e)= 0;
};

class RelogioLuxo: public ItemLuxo {
    int preco;
    int categ;
public:
    RelogioLuxo(int pre) : ItemLuxo()  {
        preco = pre;
        categ = 3;
    }
    void atribuiEscalao(int e) {escalao = e;}
    bool obtemTaxa(){return false;}
};
int main(int argc, char ** argv) {
    RelogioLuxo a(25000);
    return 0;
}
```

# Exercicio 3

### Nota
Por alguma razão o cout das copias está mal, tudo o resto está a funcionar.

## Resposta

```cpp
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Registo {
    int DonoBI;
    string NomeItem;
    int copias = 0;
    static int conta;
public:
    int getDono()const {return DonoBI;}
    string getNome()const{return NomeItem;}
    int getCopias()const{return copias;}
    
    
    Registo(int dbi, string ni) {
        DonoBI = dbi;
        NomeItem = ni;
        copias = 0;
    }
    Registo &operator=(const Registo &r){
        NomeItem = r.NomeItem;
        copias++;
        return *this;
    }
};
int Registo::conta = 0;

ostream &operator<<(ostream &os, const Registo r){
    os << r.getDono() << " / " << r.getNome() << "(copiado: "<< r.getCopias() << ")";
    
    return os;
}
int main() {
    Registo a(123,"carro"), b(456,"casa"), c(789,"mesa");
    a = b = c;
    a = c;
    cout << a << "\n" << b << "\n" << c;
}
// --- OUTPUT ---
//123 / mesa (copiado:0)
//456 / mesa (copiado:1)
//789 / mesa (copiado:2)
```

# Exercicio 4

## Resposta

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Pessoas{
protected:
    string nome;
public:
    Pessoas(string n) : nome(n){}
    virtual void cumprimentar()const = 0;
    virtual string getNome()const = 0;
    
};


class Aluno: public Pessoas {
public:
    Aluno(string n) : Pessoas(n){}
    void cumprimentar()const{cout << "Menino " << nome << endl;}
    string getNome()const{return nome;}
};
class Prof : public Pessoas{
public:
    Prof(string n) : Pessoas(n) {}
    void cumprimentar()const{cout << "Sr. Prof. " << nome << endl;}
    string getNome()const{return nome;}
};

class Escola{
    vector<Pessoas*>pessoas;
public:
    Escola(vector<Pessoas*>p) : pessoas(p){}
    void cump(){
        for(auto a : pessoas)
            a->cumprimentar();
    }
    string getAsString()const{
        ostringstream os;
        
        for(auto a : pessoas)
           os << a->getNome() << "\n";
            
    return os.str();
        
    }
};

int main(){
    Pessoas * p1 = new Aluno("Ismael");
    Pessoas * p2 = new Aluno("Israel");
    Pessoas * p3 = new Prof("Leonor");
    Pessoas * p4 = new Prof("Francisco");
    Pessoas * p5 = new Aluno("Rafael");

    Escola esc({p1,p2,p3,p5,p4});
    
    //cout << esc.getAsString();
    esc.cump();
    
}
```

# Exercicio 5

## Explicação

Linha 3 -> Erro porque é constante e não podemos alterar o seu valor
Linha 5 -> Erro porque o y aponta para constante e não é inicializada como constante.
Na linha 6 não dá erro porque podemos inicializar uma constante apontar para um ponteiro, não podemos é inicializar um ponteiro não constante para uma constante.

# Exercicio 6

### Resposta
```cpp
class Gravata {
    string cor;
public:
    Gravata(string s) {
        cor = s;
    }
};
class Roupa {
    string marca;
public:
    Roupa(string m) {
        marca = m;
    }
};

class Fato : public Roupa{
    Gravata gra;

};
```

# Exercicio 7



