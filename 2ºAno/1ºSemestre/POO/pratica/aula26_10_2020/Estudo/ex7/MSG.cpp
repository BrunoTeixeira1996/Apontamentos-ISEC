#include "MSG.h"


 int MSG::proxNum = 1;

 MSG::MSG(char l) : letra(l), numero(proxNum++){
	 cout << "criado: letra:  " << letra << " numero: " << numero << "\n";
 };

 string MSG::getAsString()const {
	 ostringstream os;

	 os << "letra: " << letra << " numero: " << numero;

	 return os.str();
 }

 MSG::~MSG() {
	 cout << "terminado: letra:  " << letra << " numero: " << numero << "\n";
 }

 MSG::MSG(const MSG &z) {
	 letra = z.letra;
	 numero = z.numero;
	 cout << "criado por copia : letra: " << letra << " numero: " << numero << "\n";
 }