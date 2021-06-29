#include "desenho.h"


string Desenho::getAsString()const {
	ostringstream os;
	os << "Desenho: " << nome;

	if (ret.empty())           // se o vector estiver vazio
		os << " em branco\n";
	else
		for (auto r : ret)
			os << "\n   " << r.getAsString();
	return os.str();
}

bool Desenho::setRetangulo(const Retangulo &r) {

	for (auto d : ret) {  //caso nao esteja vazio, tenho de percorrer o vector e ver se interseta com algum
		if (d.getInterseta(r)) // mal o d intersete com algum retangulo, faço return false
			return false;
	}


		ret.push_back(r);  // se estiver vazio ou não intersetar com nenhum retangulo existente
		return true; // faço push_back e return true

}

void Desenho::remArea(double valor) {
	auto it = ret.begin();

	while (it != ret.end()) {
		if (it->getArea() > valor)
			it = ret.erase(it);
		else
			++it;
	}

}

bool Desenho::setRetOrd(const Retangulo &r) {
	for (auto d : ret) {
		if (d.getInterseta(r))
			return false;
	}

	if (ret.empty()) { // se o vector estiver vazio
		ret.push_back(r); // push_back
	}
	else { // se nao estiver vazio
		
		auto it = ret.begin(); // iterador apontar para o inicio do vector

		  
		while (it != ret.end()) {    // enquanto nao chegar ao fim
			if (it->getArea() < r.getArea()) { // se a area daquele elemento for < que a area do R
				it++; // incremento o iterador
			}
			else {   // se nao, insiro no ret
				ret.insert(it, r);
				return true;
			}
		}
	}



	return true;
}