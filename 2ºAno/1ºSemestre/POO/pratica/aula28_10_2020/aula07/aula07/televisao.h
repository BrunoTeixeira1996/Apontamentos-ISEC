#ifndef  TELEVISAO_H
#define TELEVISAO_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <initializer_list>

using namespace std;


class televisao
{
	//static const int dim = 10;
	const vector<string> canais;
	bool ligada = false;
	int volume = 0;
	int canal = -1; // 1 - 1º canal, 2 - 2º canal ...
public:
	televisao(initializer_list<string> c);

	string getAsString()const;
	void desliga();
	bool liga();
};
#endif // ! TELEVISAO_H


