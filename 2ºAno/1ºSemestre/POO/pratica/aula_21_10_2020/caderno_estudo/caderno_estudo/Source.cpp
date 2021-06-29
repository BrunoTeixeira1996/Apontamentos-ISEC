#include <iostream>
#include <string>
#include "caderno.h"
using namespace std;



int main() {
	int conta = 0;
	Caderno c("Oxford", "Verde", 50, 30, 10);
	c.setAbrir();
	c.setEscreve("Era uma noite escura de tempestade.\n");

	if (c.setViraPagina()) {
		c.setEscreve("LALLALALALA.\n");
		cout << "Conteudo do caderno: " << c.getConteudo() << "\n";
	}
	else {
		cout << "Não consegui escrever no caderno\n";
		cout << "Conteudo do caderno: " << c.getConteudo() << "\n";

	}

	conta = c.getnPalavras();
	cout << "contador: " << conta;
}
