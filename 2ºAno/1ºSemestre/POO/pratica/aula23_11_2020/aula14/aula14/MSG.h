#ifndef MSG_H
#define MSG_H
#include <iostream>
using namespace std;


class MSG
{
public:
	MSG(const char* p = "") {
		cout << "ola " << p << endl;
	}
	~MSG() {
		cout << "Adeus" << endl;
	}

};


#endif
