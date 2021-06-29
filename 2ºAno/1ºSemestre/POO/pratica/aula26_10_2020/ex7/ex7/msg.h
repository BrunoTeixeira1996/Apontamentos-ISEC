#ifndef MSG_H
#define MSG_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


class MSG {
	static int prox;
	int numero;
	char letra;

public:
	MSG(const MSG &z);
	MSG(char l = 'x'); // construtor por omissão

	string getAsString() const; // obter os dados de um objeto sob a forma de string

	~MSG(); // destrutor
};


#endif