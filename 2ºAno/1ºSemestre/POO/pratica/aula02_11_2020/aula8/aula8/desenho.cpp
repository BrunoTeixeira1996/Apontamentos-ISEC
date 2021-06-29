#include "desenho.h"


string desenho::getAsString()const {
	ostringstream os;
	os << "Nome: " << nome << "\n";
	if (ret.empty())
		os << "Desenho em branco\n";
	else
		for (auto r : ret)
			os  << r.getAsString();


	return os.str();
}

bool desenho::addRetangulo(const Retangulo &r) {
	for (auto d : ret) {
		if (d.intersecta(r)) {/*se o retangulo novo intersetar com o que já lá esta, retorna false*/
			return false;
		}
	}

	ret.push_back(r);
	return true;
}


void desenho::elimRetangulo(double val) {
	auto it = ret.begin(); //criamos o iterator apontar para o inicio do vetor

	while (it != ret.end()) { //enquanto nao chegar ao fim
		if (it->getArea() > val) { //se a area do item for > que o valor passado por argumento
			it = ret.erase(it);  //fazemos erase desse iterador
		}
		else {
			it++;
		}
	}

}