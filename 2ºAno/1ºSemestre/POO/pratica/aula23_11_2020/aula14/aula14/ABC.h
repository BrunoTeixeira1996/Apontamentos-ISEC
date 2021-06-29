#ifndef ABC_H
#define ABC_H
#include <string>

class ABC
{
	char* p;

public:
	ABC(const char* s);
	~ABC();
	char* getConteudo() { return p; }
};


#endif 

