#include "imperio.h"



Imperio::Imperio()
{
	territorios.push_back(new TerrInic());
}

Imperio::Imperio(const Imperio& imp) {
	*this = imp;

}

Imperio& Imperio::operator=(const Imperio& imp) {
	cofre = imp.cofre;
	armazem = imp.armazem;
	forca_militar = imp.forca_militar;
	pontos_vitoria = imp.pontos_vitoria;
	sorte = imp.sorte;
	num_tecnologia = imp.num_tecnologia;

	drones_militares = imp.drones_militares;
	misseis_teleguiados = imp.misseis_teleguiados;
	defesas_territoriais = imp.defesas_territoriais;
	bolsa_valores = imp.bolsa_valores;
	banco_central = imp.banco_central;

	// limpamos a memoria
	for (auto i : territorios) {
		delete i;
	}
	territorios.clear();

	// escreve
	for (size_t i = 0; i < imp.territorios.size(); i++) {
		territorios.push_back(imp.territorios[i]->clone());
	}

	return *this;
}


Imperio::~Imperio()
{
	// limpa os ponteiros do vector territorios
	for (auto i : territorios) {
		delete i;
	}
	territorios.clear();
}


int Imperio::getFSorte() {
	srand((unsigned int)time(NULL));

	int f_sorte = (rand() % 5 + 1) + forca_militar;
	sorte = f_sorte;

	return f_sorte;
}

void Imperio::setContaTecnologia() {

	if (drones_militares)
		num_tecnologia++;
	if (misseis_teleguiados)
		num_tecnologia++;
	if (defesas_territoriais)
		num_tecnologia;
	if (bolsa_valores)
		num_tecnologia++;
	if (banco_central)
		num_tecnologia++;
}

bool Imperio::insereTerritorio(Territorio* t) {
	if (t == nullptr)
		return false;

	territorios.push_back(t);
	return true;
}


string Imperio::getAsString()const {
	ostringstream os;
	int max_ouro_prod, max_forca_militar;
	
	if (banco_central)
		max_ouro_prod = 5;
	else
		max_ouro_prod = 3;

	if (drones_militares)
		max_forca_militar = 5;
	else
		max_forca_militar = 3;

	os <<"  Ouro no cofre: " << cofre << " Produtos no armazem: " << armazem << " Valor Max. de Recursos: " << max_ouro_prod << endl
		 << "  Forca militar: " << forca_militar << " Valor Max. de Forca Militar: "<< max_forca_militar << endl
		<< "  Pontos de vitoria: " << pontos_vitoria << " Fator sorte: " << sorte << endl;
	
	return os.str();

}

string Imperio::getInfoTecnologias()const {
	ostringstream os;

	os <<endl<< "Tecnologias Existentes" << endl;
	os << "=========================" << endl << endl;
	os << "Drones Militares (3 de ouro) -> Aumenta nivel maximo da Forca Militar para 5 -> ";
	(drones_militares) ? os << "Adquirida\n" : os << "Nao Adquirida" << endl;

	os << "Misseis Teleguiados (4 de ouro) -> Permite o utilizador conquistar ilhas -> ";
	(misseis_teleguiados) ? os << " Adquirida\n" : os << " Nao Adquirida" << endl;


	os << "Defesas Territoriais (4 de ouro) -> Acrescenta 1 unidade de resistencia ao ultimo Territorio conquistado -> ";
	(defesas_territoriais) ? os << " Adquirida\n" : os << " Nao Adquirida" << endl;


	os << "Bolsa de Valores (2 de ouro) -> Torna possiveis as trocas entre produtos e ouro 'maisouro' e 'maisprod' -> ";
	(bolsa_valores) ? os << " Adquirida\n" : os << " Nao Adquirida" << endl;


	os << "Banco Central (3 de ouro) -> Aumenta a capacidade máxima do armazem e do cofre -> ";
	(banco_central) ? os <<  " Adquirida\n" : os << " Nao Adquirida" << endl;


	return os.str();
}

string Imperio::getTerritorios()const {
	ostringstream os;

	os << endl;
	os << "\t============================" << endl
	<< "\t|| Territorios do Imperio ||" << endl
	<< "\t============================" << endl << endl;

	for (auto imp : territorios)
		os << imp->getAsString();

	return os.str();
}

string Imperio::getTecnologias()const {
	ostringstream os;
	int conta = 0;

	os << "  Tecnologias: ";
	if (drones_militares) {
		os << "Drones Militares" << " / ";
		conta++;
	}
	if (misseis_teleguiados) {
		os << "Misseis Teleguiados" << " / ";
		conta++;
	}
	if (defesas_territoriais) {
		os << "Defesas Territorias" << " / ";
		conta++;
	}
	if (bolsa_valores) {
		os << "Bolsa de Valores" << " / ";
		conta++;
	}
	if (banco_central) {
		os << "Banco Central";
		conta++;
	}

	if (conta == 0)
		os << "Nao tem nenhuma Tecnologia";

	return os.str();
}

bool Imperio::conqIlha() {
	if (misseis_teleguiados && territorios.size() >= 5)
		return true;
	return false;
}


void Imperio::setPontosVitoria(Territorio* t) {
	if (t->getTipo() == "Ilha") {
		pontos_vitoria += 2;
	}
	else {
		pontos_vitoria += 1;
	}
}


bool Imperio::setRecolher(int ano, int turno) {
	int aux_ouro = 0, aux_prod = 0, aux_c = 0, aux_a = 0, soma_a = 0, soma_c = 0;

	for (Territorio *t : territorios) {
		if (banco_central) {
			aux_ouro = 0, aux_prod = 0;
			t->recolher(ano, turno, &aux_ouro, &aux_prod);

			soma_a = armazem + aux_prod;
			soma_c = cofre + aux_ouro;

			if (soma_c >= 5 && soma_a >= 5) {
				cofre = 5;
				armazem = 5;
			}
			else if (soma_c >= 5 && soma_a < 5) {
				cofre = 5;
				armazem = soma_a;
			}
			else if (soma_c < 5 && soma_a >= 5) {
				cofre = soma_c;
				armazem = 5;
			}
			else if (soma_c < 5 && soma_a < 5) {
				cofre = soma_c;
				armazem = soma_a;
			}
		}

		if (!banco_central) {
			aux_ouro = 0, aux_prod = 0;
			t->recolher(ano, turno, &aux_ouro, &aux_prod);


			soma_a = armazem + aux_prod;
			soma_c = cofre + aux_ouro;


			if (soma_c >= 3 && soma_a >= 3) {
					cofre = 3;
					armazem = 3;
			}
			else if (soma_c >= 3 && soma_a < 3) {
				cofre = 3;
				armazem = soma_a;
			}
			else if (soma_c < 3 && soma_a >= 3) {
				cofre = soma_c;
				armazem = 3;
			}
			else if(soma_c < 3 && soma_a < 3){
				cofre = soma_c;
				armazem = soma_a;
			}
		}
	}

	return true;
}




bool Imperio::setMaisOuro() {

	if (bolsa_valores && !banco_central) {
		if (armazem >= 2 && cofre < 3) {
			cofre += 1;
			armazem -= 2;
			return true;
		}
		else if (armazem < 2 || cofre >= 3)
			return false;
		
	}

	else if (bolsa_valores && banco_central) {
		if (armazem >= 2 && cofre < 5) {
			cofre += 1;
			armazem -= 2;
			return true;
		}
		else if (armazem < 2 || cofre >= 5)
			return false;
	}

	return false;

}

bool Imperio::setMaisProd() {
	if (bolsa_valores && !banco_central) {
		if (cofre >= 2 && armazem < 3) {
			armazem += 1;
			cofre -= 2;
			return true;
		}
		else if (cofre < 2 || armazem >= 3)
			return false;
	}
	else if (bolsa_valores && banco_central) {
		if (cofre >= 2 && armazem < 5) {
			armazem += 1;
			cofre -= 2;
			return true;
		}
		else if (cofre < 2 || armazem >= 5)
			return false;
	}

	return false;
}


bool Imperio::setMaisMilitar() {
	if (drones_militares && forca_militar < 5) {
		armazem -= 1;
		cofre -= 1;
		forca_militar += 1;
		return true;
	}
	else if (!drones_militares && forca_militar < 3) {
		armazem -= 1;
		cofre -= 1;
		forca_militar += 1;
		return true;
	}

	return false;
}

bool Imperio::setDronesMilitares() {
	if (cofre >= 3 && !drones_militares) {
		drones_militares = true;
		cofre -= 3;
		
		return true;
	}
	
	return false;
}

bool Imperio::setMisseisTeleguiados() {
	if (cofre >= 4 && !misseis_teleguiados) {
		misseis_teleguiados = true;
		cofre -= 4;

		return true;
	}

	return false;
}

bool Imperio::setDefesasTerritoriais() {
	if (cofre >= 4 && !defesas_territoriais) {
		defesas_territoriais = true;
		cofre -= 4;
		return true;
	}

	return false;

}

bool Imperio::setBolsaValores() {
	if (cofre >= 2 && !bolsa_valores) {
		bolsa_valores = true;
		cofre -= 2;

		return true;
	}
	return false;
}


bool Imperio::setBancoCentral() {
	if (cofre >= 3 && !banco_central) {
		banco_central = true;
		cofre -= 3;

		return true;
	}
	return false;
}


bool Imperio::recAbandonado(int ano) {
	if (ano == 1) { // será produtos
		if (banco_central && armazem < 5 || !banco_central && armazem < 3) {
			armazem++;
			return true;
		}
		return false;
	}

	if (ano == 2) { // SERA OURO
		if (banco_central && cofre < 5 || !banco_central && cofre < 3) {
			cofre++;
			return true;
		}
		return false;
	}
	
	return false;
}

int Imperio::evenInvasao(int ano) {
	srand((unsigned int)time(NULL));
	int fator_sorte, resultado;

	fator_sorte = (rand() % 6 + 1);

	if (ano == 1)
		fator_sorte += 2;
	else if (ano == 2)
		fator_sorte += 3;

	resultado = fator_sorte;

	// se tiver a tecnologia Defesas Territoriais
	if (defesas_territoriais)
		territorios.back()->setResistencia(territorios.back()->getResistencia() + 1);
		
	if (resultado < territorios.back()->getResistencia()) {
		return 0; // retorna 0 se a invasao falhar
	}
	else {
		// foi feita a invasao
		territorios.pop_back();

		//se es o vector ficar vazio é porque o Territorio Inicial foi conquistado
		if (territorios.empty())
			return 2;
		
		return 1;
	}
}


bool Imperio::aliDiplomatica() {
	// força militar entre 0 e 3 mas no max  é 5
	if (drones_militares && forca_militar < 5 || !drones_militares && forca_militar < 3) {
		forca_militar++;
		return true;
	}
	return false;

}