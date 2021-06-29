#ifndef AVISO_H
#define AVISO_H
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "prego.h"

/*Precisamos de nos referir ao Prego mas sem fazer uma cópia para a nossa class*/

class Aviso
{
	string texto;
	//Prego &a;
	Prego *a;

	/*Prego const *a  (o ponteiro seria constante (não muda)) */

	/*const Prego *a  dizemos que o ponteiro aponta sempre para Ponteiros constantes
	só podiamos invocar os métodos constantes do Prego*/

	/*const Prego const * a (o ponteiro não muda e o Prego tambem não)*/

	/*Referencia*/
	/*Prego &a que é uma referência para um Prego*/
	/*const Prego &a que é uma referência para um prego constante*/

public:
	//Aviso(string t, Prego &p);
	Aviso(string t, Prego *p);
	~Aviso();

	string getAsString()const;
	string getLocal()const;
};

#endif

