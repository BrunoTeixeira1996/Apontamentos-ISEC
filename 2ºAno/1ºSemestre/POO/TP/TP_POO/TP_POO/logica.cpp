#include "logica.h"
#include <iostream>

Logica::Logica()
{
	Imperio imperio;
	Mundo mundo;
}


Logica::~Logica()
{
}



string Logica::infoTerrImp() {
	ostringstream os;
	
	os << imperio.getAsString() << endl;
	os << imperio.getTecnologias() << endl;
	os << imperio.getTerritorios() << endl;

	return os.str();
}

string Logica::infoTecnologias() {
	ostringstream os;

	os << imperio.getInfoTecnologias();

	return os.str();
}

string Logica::infoTerrMundo() {
	ostringstream os;

	os << mundo.getTerritorios() << endl;

	return os.str();
}

string Logica::infoTerritorio(string nome) {
	ostringstream os;
	Territorio* p = nullptr;

	if (mundo.veTerritorio(nome) == true) {
		p = mundo.retornaTerritorio(nome);
		os << "Nome: " << p->getNome() << " Resistencia: " << p->getResistencia() << " Ouro: " << p->getOuro()
			<< " Produto: " << p->getProduto() << endl;
	}
	else {
		os << "Territorio nao existe";
	}

	return os.str();
}


bool Logica::addTerritorio(string tipo, int quantidade) {

	if (tipo == "castelo") {
		for (int i = 0; i < quantidade; i++) {

			mundo.novoTerritorio(new Castelo());
		}
		return true;
	}
	else if (tipo == "planicie") {
		for (int i = 0; i < quantidade; i++) {
			mundo.novoTerritorio(new Planicie());
		}
		return true;
	}
	else if (tipo == "montanha") {
		for (int i = 0; i < quantidade; i++) {
			mundo.novoTerritorio(new Montanha());
		}
		return true;
	}
	else if (tipo == "fortaleza") {
		for (int i = 0; i < quantidade; i++) {
			mundo.novoTerritorio(new Fortaleza());
		}
		return true;
	}
	else if (tipo == "mina") {
		for (int i = 0; i < quantidade; i++) {
			mundo.novoTerritorio(new Mina());
		}
		return true;
	}
	else if (tipo == "duna") {
		for (int i = 0; i < quantidade; i++) {
			mundo.novoTerritorio(new Duna());
		}
		return true;
	}
	else if (tipo == "refugio") {
		for (int i = 0; i < quantidade; i++) {

			mundo.novoTerritorio(new RefPiratas());
		}
		return true;
	}
	else if (tipo == "pescaria") {
		for (int i = 0; i < quantidade; i++) {
			mundo.novoTerritorio(new Pescaria());
		}
		return true;
	}

	return false;
	
}

string Logica::conqTerritorio(string nome) {
	ostringstream os;
	Territorio* p = nullptr;

	if (mundo.veTerritorio(nome) == true) { // verifica se o Territorio a ser conquistado existe no Mundo
		p = mundo.retornaTerritorio(nome); // o Ponteiro p fica apontar para o Territorio em questao

		if (p->getTipo() == "Ilha") {
			if (!imperio.conqIlha()) {
				os << "[Erro, Ilha]"; // significa que nao tem os requesitos para conquistar ilhas
				return os.str();
			}
		}

		if (imperio.getFSorte() >= p->getResistencia()) {	// verifica o fator sorte
			imperio.insereTerritorio(p);					//copiar o Territorio a ser conquistado para o Vector de Territorios do Imperio
			mundo.eliminaTerritorio(nome);					//eliminar do Vector de Territorios do Mundo o Territorio conquistado
			imperio.setPontosVitoria(p);					// pontos de vitoria (+1 se for Continente, +2 se for Ilha)
			os << "Parabens, " << nome << " conquistado!" << endl;
			return os.str();
		}
		else {												// se nao conseguiu conquistar

			imperio.decMilitar();						// se nao for, decrementa a força_miliar

			if (imperio.getMilitar() > 0) {				// vai ver se a força militar > 0
				os << "[Erro], NConquista";
				return os.str();
			}
			else {
				os << "[Erro], Jogo";// significa que ficou com a força militar a 0
				return os.str();
			}
		}
	}
	else { //Territorio a ser conquistado nao existe no Mundo
		os << "[Erro], NExiste";
		return os.str();
	}

}

string Logica::comandoToma(string qual, string nome) {
	ostringstream os;
	Territorio* p = nullptr;

	if (qual == "terr") {
		if (mundo.veTerritorio(nome)) {
			p = mundo.retornaTerritorio(nome);
			imperio.insereTerritorio(p);
			mundo.eliminaTerritorio(nome);
			imperio.setPontosVitoria(p);
			os << "Adquiriu: " << nome << endl;
			return os.str();
		}
		else {
			os << "Territorio nao existe ... " << endl;
			return os.str();
		}

	}
	else if (qual == "tec") {
		if (nome == "drone") {
			imperio.setDEBUGDronesMilitares();
			os << "Adquiriu os Drones Militares";
		}
		else if (nome == "missil") {
			imperio.setDEBUGMisseisTeleguiados();
			os << "Aquiriu os Misseis Teleguiados";

		}
		else if (nome == "defesa") {
			imperio.setDEBUGDefesasTerritoriais();
			os << "Adquiriu as Defesas Territoriais";
		}
		else if (nome == "bolsa") {
			imperio.setDEBUGBolsaValores();
			os << "Adquiriu a Bolsa de Valores";
		}
		else if (nome == "banco") {
			imperio.setDEBUGBancoCentral();
			os << "Aquiriu o Branco Central";
		}
		else
			os << "Essa tecnologia nao existe";

		return os.str();

	}

	os << "Comando mal feito ...";
	return os.str();

}

bool Logica::modificaDados(string tipo, int quantidade) {

	if (tipo == "ouro") {
		imperio.setOuroDebug(quantidade);
		return true;
	}
	if (tipo == "prod") {
		imperio.setProdDebug(quantidade);
		return true;
	}
	return false;

}

bool Logica::recolheRecursos() {
	imperio.setRecolher(mundo.getAno(), mundo.getTurno());// recolhe ouro e prod

	return true;
}

string Logica::comandoMais(string comando) {
	ostringstream os;

	if (imperio.getBolsaValores()) {
		if (comando == "maisouro") {
			if (imperio.setMaisOuro())
				os << "Trocou 2 unidades de produtos por 1 unidade de ouro";
			else
				os << "Nao foi possivel fazer a troca";
		}

		if (comando == "maisprod") {
			if (imperio.setMaisProd())
				os << "Trocou 2 unidades de ouro por 1 unidade de produto";
			else
				os << "Nao foi possivel fazer a troca";
		}
	}
	else {
		os << "Nao tem a tecnologia 'Bolsa de Valores'";
	}

	return os.str();

}

string Logica::comandoMaisMilitar() {
	ostringstream os;

	if (imperio.getDronesMilitares()) {
		if (imperio.setMaisMilitar())
			os << "Comprou uma unidade militar";
		else
			os << "Nao foi possivel comprar uma unidade militar";
	}
	else if (!imperio.getDronesMilitares()) {
		if (imperio.setMaisMilitar())
			os << "Comprou uma unidade militar";
		else
			os << "Nao foi possivel comprar uma unidade militar";
	}

	return os.str();

}

string Logica::comandoAdquire(string tipo) {
	ostringstream os;

	if (tipo == "drone") {
		if (imperio.setDronesMilitares())
			os << "Adquiriu os Drones Militares";
		else
			os << "Nao foi possivel adquirir essa tecnologia";
	}
	else if (tipo == "missil") {
		if (imperio.setMisseisTeleguiados())
			os << "Aquiriu os Misseis Teleguiados";
		else
			os << "Nao foi possivel adquirir essa tecnologia";

	}
	else if (tipo == "defesa") {
		if (imperio.setDefesasTerritoriais())
			os << "Adquiriu as Defesas Territoriais";
		else
			os << "Nao foi possivel adquirir essa tecnologia";
	}
	else if (tipo == "bolsa") {
		if (imperio.setBolsaValores())
			os << "Adquiriu a Bolsa de Valores";
		else
			os << "Nao foi possivel adquirir essa tecnologia";
	}
	else if (tipo == "banco") {
		if (imperio.setBancoCentral())
			os << "Aquiriu o Branco Central";
		else
			os << "Nao foi possivel adquirir essa tecnologia";
	}

	else
		os << "Essa tecnologia nao existe";

	os << endl;

	return os.str();

}

string Logica::infoAnoTurno() {
	ostringstream os;

	os << "Ano: " << mundo.getAno() << " Turno: " << mundo.getTurno();

	return os.str();
}

string Logica::faseEvento(bool *flag_exit) {
	ostringstream os;
	srand((unsigned int)time(NULL));

	int num_evento = (rand() % 4);


	if (num_evento == 0) {
		os << "O Evento 'Recurso Abandonado' foi o selecionado ... " << endl;

		if (imperio.recAbandonado(mundo.getAno())) {
			if (mundo.getAno() == 1)
				os << "Ganhou uma unidade de produto !!! " << endl;
			else
				os << "Ganhou uma unidade de ouro !!! " << endl;
		}
		else
			os << "Nao tem capacidade para mais recursos no Imperio ... " << endl;
	}

	else if (num_evento == 1) {
		os << "O Evento 'Invasao' foi o selecionado ... " << endl;

		int evento_invasao = imperio.evenInvasao(mundo.getAno());

		if (evento_invasao == 0) {
			os << "O Inimigo nao conseguiu conquistar o seu Territorio !!! " << endl;
		}


		else if (evento_invasao == 1)
			os << "Infelizmente o Inimigo conseguiu conquistar o seu Territorio ... " << endl;

		else if (evento_invasao == 2) {
			os << "Oops, parece que ficou sem Territorios no seu Imperio , o jogo vai terminar ... " << endl;
			*flag_exit = true;
		}

	}
	else if (num_evento == 2) {
		os << "O Evento 'Aliança Diplomatica' foi selecionado ... " << endl;

		if (imperio.aliDiplomatica())
			os << "Ganhou uma unidade de força militar !!! " << endl;
		else
			os << "Nao tem capacidade para mais recursos no Imperio ... " << endl;
	}

	else if (num_evento == 3) {
		os << "Neste turno nao foi selecionado nenhum evento ... " << endl;
	}

	return os.str();
	
}

string Logica::comandoFEvento(string nome) {
	ostringstream os;

	if (nome == "recAbandonado") {
		os << "O Evento 'Recurso Abandonado' foi o selecionado ... " << endl;

		if (imperio.recAbandonado(mundo.getAno())) {
			if (mundo.getAno() == 1)
				os << "Ganhou uma unidade de produto !!! " << endl;
			else
				os << "Ganhou uma unidade de ouro !!! " << endl;
		}
		else
			os << "Nao tem capacidade para mais recursos no Imperio ... " << endl;
	}

	else if (nome == "evenInvasao") {
		os << "O Evento 'Invasao' foi o selecionado ... " << endl;

		int evento_invasao = imperio.evenInvasao(mundo.getAno());

		if (evento_invasao == 0) {
			os << "O Inimigo nao conseguiu conquistar o seu Territorio !!! " << endl;
		}
		else if (evento_invasao == 1)
			os << "Infelizmente o Inimigo conseguiu conquistar o seu Territorio ... " << endl;

		else if (evento_invasao == 2) {
			os << "Oops, parece que ficou sem Territorios no seu Imperio , o jogo vai terminar ... " << endl;
		}

	}
	else if (nome == "aliDiplomatica") {
		os << "O Evento 'Aliança Diplomatica' foi selecionado ... " << endl;

		if (imperio.aliDiplomatica())
			os << "Ganhou uma unidade de força militar !!! " << endl;
		else
			os << "Nao tem capacidade para mais recursos no Imperio ... " << endl;
	}

	else if (nome == "semEvento") {
		os << "Neste turno nao foi selecionado nenhum evento ... " << endl;
	}

	return os.str();

}


void Logica::passaTurno(int* ano, int* turno) {

	mundo.incTurnoAno();

	*ano = mundo.getAno();
	*turno = mundo.getTurno();
}

string Logica::terminaJogo() {
	ostringstream os;
	int res_final = 0;

	imperio.setContaTecnologia();

	os << endl << "Pontos de Vitoria: " << imperio.getPontosVitoria() << endl;
	os << "Pontos adicionais por Tecnologia: " << imperio.getContaTecnologia() << endl;
	os << "Bonus Cientifico: " << imperio.getBonusCientifico() << endl;
	os << "Bonus Imperador Supremo: " << mundo.getImpSupremo() << endl;

	res_final = imperio.getPontosVitoria() + imperio.getContaTecnologia() +
		imperio.getBonusCientifico() + mundo.getImpSupremo();

	os << "Pontuacao Final: " << res_final << endl;

	return os.str();

}
