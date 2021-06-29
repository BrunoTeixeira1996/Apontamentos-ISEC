#pragma once
#ifndef PREGO_H
#define PREGO_H
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Prego {
	int x, y;
public:
	Prego(int a, int b) { x = a; y = b; cout << "construindo prego em " << x << "," << y << "\n"; }

	~Prego() { cout << "destruindo prego em " << x << "," << y << "\n"; }

	void mudaDeSitio(int a, int b) { x = a; y = b; } 
	string getAsString()const;
	string getLocal()const;
};



#endif // !PREGO_H


