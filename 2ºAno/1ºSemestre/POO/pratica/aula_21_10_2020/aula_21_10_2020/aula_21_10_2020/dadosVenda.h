#ifndef DADOS_VENDA_H
#define DADOS_VENDA_H
#include <string>

class DadosVenda {
	std::string numLivro;
	unsigned unidadesVendidas;
	double receita;
public:
	DadosVenda(std::string isbn, double rec, int uv = 1);

	std::string getISBN() const;


};

#endif