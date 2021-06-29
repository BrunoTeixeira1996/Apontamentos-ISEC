#include "ABC.h"

void copiaStr(char* d, const char* o) {
	unsigned tam = strlen(o);
	for (unsigned i = 0; i <= tam; i++)
		d[i] = o[i];
}


ABC::ABC(const char* s) {
	p = new char[strlen(s) + 1];
	copiaStr(p, s);
}

ABC::~ABC() {
	delete[] p;
}

ABC& ABC::operator=(const ABC& x) {
	char* copia = new char[strlen(x.p) + 1];
	copiaStr(copia, x.p);
	if (p != nullptr)
		delete(p);
	p = copia;

	return *this;
}

ABC::ABC(const ABC& r) {
	p = nullptr;
	*this = r;
}