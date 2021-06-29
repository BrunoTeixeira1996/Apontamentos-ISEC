#ifndef MSG_H
#define MSG_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class MSG
{
	static int proxNum;
	int numero;
	char letra;
public:
	MSG(char l = 'x');
	MSG(const MSG &z);
	~MSG();
	string getAsString() const;
};


#endif