#include "televisao.h"


televisao::televisao(initializer_list<string> c) : canais(c) {
	if (!canais.empty())
		canal = 1;
}

void televisao::desliga() {
	ligada = false;
}

bool televisao::liga() {
	if (!canais.empty()) {
		ligada = true;
		return true;
	}
	return false;
}
//televisao::televisao(initializer_list<string> c)
//{
//	int n = 0;
//
//	for (auto ca : c) {
//		if (n < dim) {
//			canais.push_back(ca);
//			n++;
//		}
//	}
//	if (!canais.empty()) {
//		canal = 1;
//	}
//}
//



string televisao::getAsString()const {
	ostringstream os;
	if(ligada){
		os << "Tv ligada ";
		if (!canais.empty()) {
			os << ", no canal " << canal << ": " << canais[canal-1];
			os << ", volume de som " << volume;
			os << " e os canais ";
			for (auto c : canais) {
				os << c << ", ";
			}
		}
	}
	else {
		os << "Tv desligada ";
	}


	return os.str();
}