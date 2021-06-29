#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <initializer_list>

using namespace std;

class Televisao {
	vector<string> canais;
	bool ligada = false;
	int volume = 0;
	static const int max_canais = 10;
	int num_canal = -1;

public:
	Televisao(initializer_list<string> canais01);
	string getAsstring() const;
	bool setLiga();
	void setDesliga();
	bool setAumentaVolume();
	bool setDiminuiVolume();
	bool setCanal(int n_canal);

};

string Televisao::getAsstring() const {
	ostringstream os;

	if (ligada) {
		os << "TV ligada\n";
		if (!canais.empty()) {
			os << "No canal: " << num_canal << ": " << canais[num_canal - 1] << " volume: " << volume << "\ncanais: ";
			for (auto a : canais)
				os << a << "  ";
		}
		os << "\n";
	}
	else {
		os << "TV desligada\n";
	}

	return os.str();
}

Televisao::Televisao(initializer_list<string> canais01) {
	int n = 0;
	for (auto c : canais01) {
		if (n < max_canais) {
			canais.push_back(c);
			n++;
		}
	}

	if (!canais.empty()) {
		num_canal = 1;
	}
}

//Televisao::Televisao(initializer_list<string> canais01) : canais(canais01){
//
//	if (!canais.empty()) {
//		num_canal = 1;
//	}
//}

bool Televisao::setLiga() {
	if (!canais.empty()) {
		ligada = true;
		return ligada;
	}
	return false;
}


void Televisao::setDesliga() {
	canais.clear();
	ligada = false;

}

bool Televisao::setAumentaVolume() {
	if (ligada) {
		if (volume < 10) {
			volume++;
			return true;
		}
		else {
			cout << "\nNão posso aumentar mais, está no volume máximo\n";
			return false;
		}
	}
}

bool Televisao::setDiminuiVolume() {
	if (ligada) {
		if (volume > 0) {
			volume--;
			return true;
		}
		else {
			cout << "\nNão posso diminuir mais, está no volume minimo\n";
			return false;
		}
	}
}

bool Televisao::setCanal(int n_canal) {
	if (ligada) {
		if (n_canal <= canais.size() && n_canal > 0) {
			num_canal = n_canal;
			cout << "canal mudado: " << num_canal << ": " << canais[num_canal - 1];
			return true;
		}
		else {
			return false;
		}
		
	}
}

int main() {


	Televisao tv({"rtp1","rtp2","rtp3","sic","tvi","natgeo","sic radical","foxcrime"});
	tv.setLiga();

	//tv.setAumentaVolume();
	//tv.setAumentaVolume();
	//tv.setAumentaVolume();
	//tv.setAumentaVolume();
	//tv.setDiminuiVolume();
	//tv.setDiminuiVolume();
	//tv.setDiminuiVolume();
	//tv.setDiminuiVolume();


	cout << tv.getAsstring();
	cout << "\n";
	tv.setCanal(5);

	cout << "\n";
	cout << tv.getAsstring();


	return 0;
}