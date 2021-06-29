#include "interface.h"
#include <fstream>

using namespace std;


Interface::Interface()
{
}


Interface::~Interface()
{
}


int Interface::comeca() {
	string linha, comando;

	while (!flag_sair) {	
		
		cout << endl <<"Introduza um comando: ";
		getline(cin, linha);

		istringstream divide(linha);

		divide >> comando;
		veComando(comando, linha);
	}

	return 0;
}

void Interface::veComando(string comando, string linha) {

	if (flag_sair)
		return;
	
	if (comando == "avanca" || flag_jogando == 1) {
		if (!flag_inicio) 
			cout << "Crie primeiro territorios! Use 'cria' ou 'carrega'." << endl;
		else {
			flag_jogando = 1;
			modoJogo(linha);
		}		
	}
	else if (comando == "cria" || comando == "carrega" || comando == "sair") {
		modoConfig(linha);
	}
	else if(comando == "lista"){
		if (!flag_inicio) 
			cout << "Nenhum territorio para listar! Use primeiro 'cria' ou 'carrega'." << endl;
		else
			modoConfig(linha);
	}
	else {
		cout << "Comando nao existe na configuracao! Use 'cria' ou 'carrega' e so depois 'avanca'." << endl;
	}
}

void Interface::modoConfig(string linha) {
	string comando, tipo, aux;
	int n, contaArg = 0;

	istringstream divide(linha);
	istringstream divideAux(linha);

	divide >> comando >> tipo >> n;

	//verificar numero de argumentos
	while (divideAux >> aux) {
		contaArg++;
	}

	if (comando == "cria") {
		if (!tipo.empty() && n > 0 && contaArg == 3) {
			if (!logica.addTerritorio(tipo, n)) {
				cout << "[ERRO] territorio nao existe" << endl;
			}
			else
				cout << "Criou " << n << " territorios do tipo " << "'" << tipo << "'" << " com sucesso!" << endl;
				flag_inicio = 1;
		}
		else {
			cout << "[ERRO] no 'cria'" << endl;
		}
	}	

	else if (comando == "carrega" && !tipo.empty() && contaArg == 2) {
		ifstream ficheiro(tipo);
		string ler;

		if (ficheiro.is_open()) {
			cout << "Criou territorios a partir do ficheiro " << "'"<< tipo <<"'" << " com sucesso!" << endl;
			flag_inicio = 1;

			while (!ficheiro.eof()) {
				getline(ficheiro, ler);

				if (ler.empty()) {
					cout << "[ERRO] ficheiro mal construdio, lido ate ao erro" << endl;
					return ;
				}

				istringstream divideFich(ler);		
				divideFich >> comando >> tipo >> n;			//exemplo: cria planicie 2
					
				if (!logica.addTerritorio(tipo, n)) {
					cout << "[ERRO] territorio nao existe" << endl;
				}
			}
			ficheiro.close();
		}
		else
			cout << "[ERRO] ficheiro nao existe!" << endl;
	}
	else if (comando == "carrega" && tipo.empty() && contaArg < 2 || contaArg > 2) {
		cout << "[ERRO] 'carrega' nome Ficheiro" << endl;
	}
	else if (comando == "lista") {
		if (!tipo.empty()) {
			cout << logica.infoTerritorio(tipo) << endl;
		}
		else {
			lista();
		}
	}
	else if (comando == "sair") {
		cout << "Aplicacao terminada!" << endl;
		flag_sair = true;
		return;
	}
}


void Interface::modoJogo(string linha) {
	string comando, tipo, nome, aux;
	int ano = 1, turno = 1, fase = 1;
	int contaArg = 0;

	if (!flag_infoJogo) {
		cout <<endl<< "\t=========================" << endl
			<< "\t|| ENTROU NO MODO JOGO ||" << endl
			<< "\t=========================" << endl;
		menuComandos();
	}

	flag_infoJogo = 1;
	cout << "\n" << endl;

	while (comando != "sair") {
		linha.clear();
		comando.clear();
		tipo.clear();
		nome.clear();

		if (!flag_fase1) {
			cout << endl<< "Encontra-se na fase 1" << endl;
			cout << logica.infoAnoTurno() << endl;
			flag_fase1 = true;
		}
		cout << endl;
		cout << "Introduza um comando: ";
		getline(cin, linha);

		istringstream divide(linha);
		istringstream divideAux(linha);

		divide >> comando >> tipo >> nome;

		while (divideAux >> aux) {
			contaArg++;
		}

		if (fase == 1) {
			modJFase1(comando, tipo, &fase, nome, contaArg);
			contaArg = 0;
		}
		else if (fase == 2) {
			modJFase2(comando, &fase, nome, tipo, contaArg);
			contaArg = 0;
		}
		else if (fase == 3) {
			modJFase3(comando, tipo, &fase, nome, &ano, &turno, contaArg);
			contaArg = 0;

			if(turno == 13){
				cout << logica.terminaJogo();
				flag_sair = true;
				return;
			}
		}

	}

}

void Interface::modJFase1(string comando, string tipo, int *fase, string nome, int contaArg) {
	int n; //para a quantidade do modifica

	if (comando == "lista") {
		if (!tipo.empty()) {
			if (tipo == "tec") {
				cout << logica.infoTecnologias() << endl;
			}
			else
				cout << logica.infoTerritorio(tipo);
		}
		else if (tipo.empty())
			lista();
	}
	else if (comando == "conquista") {
		if (contaArg != 2)
			cout << "[ERRO] no conquista" << endl;
		else if (!flag_conquista && !flag_passa && contaArg == 2) { // se ainda nao conquistou ou ainda nao passou
			conquista(tipo);
		}
		else if (flag_conquista)
			cout << "So pode conquistar 1x por turno" << endl;
		else if (flag_passa)
			cout << "Ja fez o comando 'passa' anteriormente!" << endl;

	}
	else if (comando == "passa") {
		if (contaArg != 1)
			cout << "[ERRO] no 'passa'" << endl;
		else if (!flag_passa && !flag_conquista) { // se ainda nao conquistou ou ainda nao passou
			flag_passa = true;
			cout << "Nao conquistou nenhum territorio..." << endl;
		}
		else if (flag_passa)
			cout << "So pode passar 1x por turno" << endl;
		else if (flag_conquista)
			cout << "Ja fez o comando 'conquista' anteriormente!" << endl;

	}
	else if (comando == "avanca") {
		if (contaArg != 1)
			cout << "[ERRO] no 'avanca'" << endl;
		else if (flag_passa || flag_conquista) { // avanca se houve um 'passa' ou um 'conquista'
			(*fase)++;
			cout <<endl<< "Encontra-se na fase 2" << endl;
			cout << logica.infoAnoTurno() << endl;
		}
		else {
			cout << "Nao pode avancar sem usar o 'passa' ou 'conquista'" << endl;
		}
	}
	else if (comando == "sair") {
		if (contaArg != 1)
			cout << "[ERRO] no 'sair'" << endl;
		else {
			cout << "A sair ......." << endl;

			flag_sair = true;

			return;
		}
	}
	else if (comando == "toma") {
		if (contaArg != 3)
			cout << "[ERRO] no 'toma'" << endl;
		else
			cout << logica.comandoToma(tipo, nome);
	}
	else if (comando == "fevento") {
		if (contaArg != 2)
			cout << "[ERRO] no fevento" << endl;
		else
			cout << logica.comandoFEvento(tipo);
	}
	else if (comando == "modifica") {
		if (contaArg != 3)
			cout << "[ERRO] no modifica" << endl;
		else {
			n = stoi(nome);
			modifica(tipo, n);
		}
	}
	else if (comando == "limpa")
		cout << "\033[2J\033[1;1H";

	else if (comando == "grava")
		grava(tipo);

	else if (comando == "ativa")
		ativa(tipo);

	else if (comando == "mostra")
		mostraJogos();

	else if (comando == "apaga")
		apaga(tipo);

	else if (comando == "menu")
		menuComandos();

	else if (comando == "info") {
		infoFase(*fase);
		cout << logica.infoAnoTurno() << endl;
	}
	else
		cout << "Comando invalido nesta fase" << endl;
	}


void Interface::modJFase2(string comando, int *fase, string nome, string tipo, int contaArg) {
	int n; //para a quantidade do modifica

	if (comando == "lista") {
		if (!tipo.empty()) {
			if (tipo == "tec") {
				cout << logica.infoTecnologias() << endl;
			}
			else
				cout << logica.infoTerritorio(tipo);
		}
		else if (tipo.empty())
			lista();
	}
	else if (comando == "maisouro" && !flag_mOuro) {
		if (contaArg != 1)
			cout << "[ERRO] no maisouro" << endl;
		else if (flag_Maisvez){
			cout << "Ja fez o comando 'maisprod' anteriormente!" << endl;
		}
		else { // usa o comando 'maisouro'
			cout << logica.comandoMais(comando);
			flag_mOuro = true;
			flag_Maisvez = true;
		}
	}
	else if (comando == "maisouro" && flag_mOuro)
		cout << "Nao pode fazer o 'maisouro' novamente" << endl;

	else if (comando == "maisprod" && !flag_mProd) {

		if (contaArg != 1)
			cout << "[ERRO] no maisprod" << endl;
		else if (flag_Maisvez == true) {
			cout << "Ja fez o comando 'maisouro' anteriormente!" << endl;
		}
		else {
			cout << logica.comandoMais(comando);
			flag_mProd = true;
			flag_Maisvez = true;
		}
	}
	else if (comando == "maisprod" && flag_mProd == true)
		cout << "Nao pode fazer o 'maisprod' novamente" << endl;

	else if (comando == "avanca") {
		if (contaArg != 1)
			cout << "[ERRO] no 'avanca'" << endl;
		else {
			(*fase)++;
			cout<<endl << "Encontra-se na fase 3" << endl;
			cout << logica.infoAnoTurno() << endl;
		}

	}
	else if (comando == "toma") {
		if (contaArg != 3)
			cout << "[ERRO] no 'toma'" << endl;
		else
			cout << logica.comandoToma(tipo, nome);
	}
	else if (comando == "fevento") {
		if (contaArg != 2)
			cout << "[ERRO] no 'fevento'" << endl;
		else
			cout << logica.comandoFEvento(tipo);
	}
	else if (comando == "modifica") {
		if (contaArg != 3)
			cout << "[ERRO] no 'modifica'" << endl;
		else {
			n = stoi(nome);
			modifica(tipo, n);
		}
	}
	else if (comando == "limpa")
		cout << "\033[2J\033[1;1H";

	else if (comando == "grava")
		grava(tipo);

	else if (comando == "ativa")
		ativa(tipo);

	else if (comando == "mostra")
		mostraJogos();

	else if (comando == "apaga")
		apaga(tipo);

	else if (comando == "menu")
		menuComandos();

	else if (comando == "info") {
		infoFase(*fase);
		cout << logica.infoAnoTurno() << endl;
	}
	else
		cout << "Comando invalido nesta fase" << endl;
}

void Interface::modJFase3(string comando, string tipo, int* fase,string nome, int *ano, int *turno, int contaArg) {
	bool flag_exit = false;
	int n;  //para o modifica

	if (comando == "lista") {
		if (!tipo.empty()) {
			if (tipo == "tec") {
				cout << logica.infoTecnologias() << endl;
			}
			else
				cout << logica.infoTerritorio(tipo);
		}
		else if (tipo.empty())
			lista();
	}

	else if (comando == "maismilitar" && !flag_mMilitar) {
		if (contaArg != 1)
			cout << "[ERRO] no 'maismilitar'" << endl;
		else {
			cout << logica.comandoMaisMilitar();
			flag_mMilitar = true;
		}
	}
	else if (comando == "maismilitar" && flag_mMilitar) {
		cout << "Ja fez o comando 'maismilitar' anteriormente! "<< endl;
	}
	else if (comando == "adquire") {
		if (contaArg != 2)
			cout << "[ERRO] no 'adquire'" << endl;
		else
			cout << logica.comandoAdquire(tipo);
	}
	else if (comando == "avanca") {
		if (contaArg != 1)
			cout << "[ERRO] no 'avanca'" << endl;
		else {
			(*fase) = 1;
			cout <<endl<< "Encontra-se na fase 4 e entrou na fase dos eventos" << endl;
			cout << logica.infoAnoTurno() << endl << endl;
			cout << logica.faseEvento(&flag_exit);
			logica.recolheRecursos();
			logica.passaTurno(ano, turno);
		}

		if (flag_exit) {
			cout << logica.terminaJogo();
			flag_sair = true;
			return;
		}
		resetFlags();
	}
	else if (comando == "toma") {
		if (contaArg != 3)
			cout << "[ERRO] no 'toma'" << endl;
		else
			cout << logica.comandoToma(tipo, nome);
	}
	else if (comando == "fevento") {
		if (contaArg != 2)
			cout << "[ERRO] no 'fevento'" << endl;
		else
			cout << logica.comandoFEvento(tipo);
	}
	else if (comando == "modifica") {
		if (contaArg != 3)
			cout << "[ERRO] no 'modifica'" << endl;
		else {
			n = stoi(nome);
			modifica(tipo, n);
		}
	}
	else if (comando == "limpa")
		cout << "\033[2J\033[1;1H";

	else if (comando == "grava")
		grava(tipo);

	else if (comando == "ativa")
		ativa(tipo);

	else if (comando == "mostra")
		mostraJogos();

	else if (comando == "apaga")
		apaga(tipo);

	else if (comando == "menu")
		menuComandos();

	else if (comando == "info") {
		infoFase(*fase);
		cout << logica.infoAnoTurno() << endl;
	}
	else
		cout << "Comando invalido nesta fase" << endl;

}


void Interface::conquista(string tipo) {
	string resposta;

	resposta = logica.conqTerritorio(tipo);
	
	
	if (resposta == "[Erro], NExiste") {
		cout << "Territorio nao existe no Mundo";
		flag_conquista = false;
	}
	else if(resposta == "[Erro, Ilha]")  {
		cout << "Ainda nao possui os requerimentos para conquistar Ilhas ...";
		flag_conquista = false;
	}

	else if (resposta == "[Erro], Jogo") {
		cout << "O jogo vai terminar, Forca Militar <= 0 ...";
		flag_sair = true;
		return;
	}
	else if (resposta == "[Erro], NConquista") {
		cout << "Oops, parece que nao foi possivel conquistar ..."
			<< "O factor Sorte nao foi suficiente";
		flag_conquista = false;
	}

	else {
		cout << resposta << endl;
		flag_conquista = true;
	}
}



void Interface::lista() {
	cout << logica.infoTerrMundo() << endl
		<< "\t================================" << endl
		<< "\t|| Informacao sobre o imperio ||" << endl
		<< "\t================================" << endl  << endl << logica.infoTerrImp()
	<< "---------------------------------------------------------"<< endl;
}


void Interface::grava(string nome) {
	armazenamentos.push_back(new Guarda(nome, logica));
	cout << "Gravou o jogo em memoria com o nome '" << nome << "'" << endl;
}

void Interface::ativa(string nome) {
	bool flag_ativa = false;

	for (size_t i= 0; i < armazenamentos.size(); i++) {
		if (nome == armazenamentos[i]->getNome()) {
			logica = armazenamentos[i]->getLogica();
			cout << "Carregou o jogo em memoria chamado '" << nome << "'" << endl;
			flag_ativa = true;
			break;
		}
	}
	
	if (!flag_ativa) {
		cout << endl << "[ERRO] estado indicado nao esta guardado em memoria!" << endl;
		cout << "Utilize 'mostra' para ver quais os estados ja gravados" << endl;
	}
}

void Interface::apaga(string nome) {
	bool flag_apaga = false;

	for (auto it = armazenamentos.begin(); it != armazenamentos.end(); it++) {
		if ((*it)->getNome() == nome) {
			it = armazenamentos.erase(it);
			cout << "Apagou o jogo em memoria chamado '" << nome << "'" << endl;
			flag_apaga = true;
			break;
		}
	}
	
	if (!flag_apaga) {
		cout << "O estado indicado nao existe ainda!" << endl
		<< "Utilize primeiro o 'grava' para gravar um estado" << endl;
	}
}

void Interface::mostraJogos()const {

	cout << endl << "Lista dos jogos em memoria" << endl
		<< "============================" << endl <<endl ;
	for (size_t i= 0; i < armazenamentos.size(); i++)
		cout << "Nome: " << armazenamentos[i]->getNome() << endl;
}


void Interface::modifica(string tipo, int n) {
	if (!logica.modificaDados(tipo, n)) {
		cout << "[ERRO]Tipo inválido (ouro ou prod + quantidade)" << endl;
	}
	else {
		cout << "[DEBUG]Modificou para " << n << " de " << tipo << endl;
	}
	
}


void Interface::resetFlags() {
	flag_fase1= flag_conquista = flag_Maisvez = flag_mMilitar = flag_mOuro = flag_mProd = flag_passa = false;
	flag_inicio = 0;
}

void Interface::infoFase(int fase) {
	cout <<endl<< "Encontra-se na fase " << fase << endl;
}

void Interface::menuComandos() {

	cout << endl <<"----Lista de comandos disponiveis durante o jogo----" << endl;
	cout << endl << "-'lista' para a qualquer momento do jogo listar informacao do mundo e imperio" << endl
		<< "-'avanca' avancando para a fase seguinte" << endl << endl 
		<< "Para a fase 1: " << endl 
		<< "   -'conquista' ou 'passa' sendo possivel usar apenas um e 1x por turno" << endl << endl
		<< "Para a fase 2: " << endl
		<< "   -'maisouro' ou 'maisprod' sendo possivel usar apenas um e 1x por turno " << endl << endl
		<< "Para a fase 3: " << endl
		<< "   -'maismilitar' sendo apenas possivel usa-lo 1x" << endl
		<< "   -'adquire'" << endl << endl
		<< "Referentes a memoria do jogo: " << endl
		<< "   -'grava', 'ativa' e 'apaga' a qualquer momento do mesmo" << endl << endl
		<< "Para alem dos comandos DEBUG: 'fevento', 'modifica', 'toma' disponiveis a qualquer momento do jogo, existem ainda: " << endl
		<< "   -'mostra' para listar todos os estados gravados em memoria" << endl
		<< "   -'info' para ver a fase, ano e turno em que se encontra" << endl
		<<"   -'lista tec' para obter informacao sobre as tecnologias" << endl
		<< "   -'limpa' para limpar todo o ecra" << endl
		<<"   -'menu' para voltar a ver esta informacao" << endl;
}