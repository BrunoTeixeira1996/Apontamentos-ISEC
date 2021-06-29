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