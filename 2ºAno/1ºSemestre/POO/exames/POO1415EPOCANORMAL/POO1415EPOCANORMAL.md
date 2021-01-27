
# Exercicio 1
## Explicação
Se criarmos assim um objeto _A *p = new B_* significa que estamos a criar um objeto dinâmico B que herda do **A** as suas funções e depois faz entao o override delas, podendo ou não usar as funções da **class A** ou da **class B** dependendo do **virtual**.

Caso contrario, se criarmos um objeto **new B** não herdamos nada do **A** e as funções que irão fazer **cout** pertencem ao **B**.

### Resposta
Existem 2 funções de listar, listar1, que recebe um Ponteiro para **A** , e listar2 que recebe um Ponteiro para **B**.
O erro está na função main, quando chamamo o **listar1(new B)** e quando chamamos a função **listar2(new A)** porque ambas estão a receber o tipo errado.

# Exercicio 2

## Explicação
Basta criar uma classe Arvore e como a Arvore deriva de Vegetal, para que a Arvore seja uma classe concreta, temos de definir todas as funções que a classe Vegetal não define ou cria como sendo virtual.
Se as funções forem puramente virtuais, temos obrigatoriamente de as definir na classe Derivada, se for uma função virtual não pura, não é preciso.

### Resposta

```cpp
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class SerVivo{
public:
    virtual void funcA()=0;
    virtual void funcB()=0;
};

class Vegetal : public SerVivo{
public:
    virtual void funcB(){cout << "funcB em Vegetal\n";}
    virtual void funcC()=0;
};

class Arvore: public Vegetal{
public:
    void funcA(){}
    void funcC(){}
};


int main() {
    Arvore a;
    return 0;
}
```

# Exercicio 3
## Explicação
Temos um destrutor virtual na class Animal e na class Panda.
Ao criar um objeto _Animal *a=new Panda_, estamos a criar um objeto dinâmico **Panda** que herda da classe **Animal**, logo, quando esse objeto é destruido o **destrutor virtual** da class **derivada** é chamado e logo a seguir é chamado o **destrutor virtual** da class **base**.

No caso da Arvore, não existe nenhum destrutor virtual, logo o destrutor por omissão irá ser o da classe **base**

Outra nota é que basta termos um destutor virtual na classe **base** para ser aplicado nas classes **derivadas** caso o objeto **derivado** seja inicializado a partir da class **base**.

### Resposta
```
 ~Panda  ~Animal  ~Planta
 ```

# Exercicio 4
## Explicação
O operator para realizar a conta **z = a + b** tem de ser obrigatoriamente global.

### Resposta

```cpp
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class A{
    int n;
public:
    A(int nn = 0){n = nn;}
    int getNumero()const{return n;}
    
    string getAsString()const{
        ostringstream os;
        os << "Numero: " << n << endl;
        
        return os.str();
    }
    
    //operador de conversão, de objeto para int
    operator int()const{
        return n;
    }
    
};


 A operator+(const A &pri, const A &seg){
        return A(pri.getNumero() + seg.getNumero());
    }

int main() {
    A x(2), y(3),z;
    
    //operador +
    z = x + y;
    cout <<  z.getAsString();
    
    //operador de conversão
    int n = x;
    cout << n;
    
    
    //getN() = 4;
    

}
```

# Exercicio 5
## Explicação
Criou-se um construtor que recebe o construtor da class **A** e depois o objeto da class **B**
### Resposta

```cpp
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class A {
  int altura;
public:
    A(int a) {altura = a;}
};
class B {
  int peso;
public:
    B(int p) {peso = p;}
};
class C: public A {
  B carga;

public:
    C(): A(5), carga(10){}
};

int main() {
   // objecto objc fica com 5 de altura e 10 de peso
   C objc;

   return 0;
}
```

# Exercicio 6
### Resposta
```cpp
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class FichaAluno {
public:
    ~FichaAluno(){cout << "destruindo uma ficha de aluno;\n";}  
};
class Curso {
  vector <FichaAluno*> alunos;
  FichaAluno * pedag1;
  FichaAluno * pedag2;
  public:
    ~Curso(){
        for(auto a : alunos)
            delete a;
        alunos.clear();
        
        cout << "destruindo o vector de alunos;\n";
    }
};
void func() {
  Curso c;
  FichaAluno aluno;
}
int main() {
  func();
}
```

