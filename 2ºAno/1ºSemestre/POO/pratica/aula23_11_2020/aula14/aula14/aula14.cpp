#include <iostream>
#include <vector>
#include "MSG.h"
#include "ABC.h"

using namespace std;

/*Para alterar o MSG*a e o MSG*b no main
* na func() tenho de passar uma referencia para  ponteiro ou um ponteiro para ponteiro
*/
void func(MSG *&dd, MSG *&cc) {
    dd = new MSG("mensagem A");
    cc = new MSG("mensagem B");

}

void gastaMem() {
    ABC temp("Texto temporario que ocupa espaço");
}


int main()
{
    for (unsigned int i = 0; i < 1000; i++)
        gastaMem();
    cout << "o programa ja deve ter terminado" << endl;


   //MSG* x = new MSG[3]{ {"aa"}, {"bb"} };

    //int* ai = new int[10]{ 1,2,3,4,5,6,7,8,9 };
    //for (unsigned i = 0; i < 10; i++)
    //    ai[i] += 2;

    //int* p = nullptr;
    //for (p = ai; p < ai + 10; p++)
    //    cout << *p << " ";

    //delete[] ai;

    //int* ai = new int[10]();// aqui nao posso passar valor entre parenteses mas posso entre chavetas

    


    /*MSG* a = nullptr;
    MSG* b = nullptr;
    func(a,b);
    if (a != nullptr)
        delete a;
  
    if (b != nullptr)
        delete b;*/





    //int* pi = new int(1024);
    //string* ps = new string(5, '9');
    //vector<int>* pv = new vector<int>{ 0,1,2,3,4,5 };
    //cout << *pi << endl;
    //cout << *ps << endl;

    //for (auto i : *pv)
    //    cout << i << " ";

    //if (pi != nullptr) {
    //    delete pi;
    //    pi = nullptr;
    //}

    //if (ps != nullptr) {
    //    delete ps;
    //    ps = nullptr;
    //}

    //if (pv != nullptr) {
    //    delete pv;
    //    pv = nullptr;
    //}
}

