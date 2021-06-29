#include "prego.h"



string Prego::getAsString() const{
	ostringstream os;
	os << "Prego: " << x << "/" << y << endl;

	return os.str();
}

string Prego::getLocal()const {
	ostringstream os;
	os << "(" << x << "," << y << ")" << endl;

	return os.str();
}