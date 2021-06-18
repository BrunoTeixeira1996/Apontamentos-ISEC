#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#define TAM 200
int _tmain(int argc, TCHAR* argv[]) {
	HKEY chave; // handle para chave depois de aberta ou criada
	DWORD resultado; //o que aconteceu com a chave
	TCHAR chave_dir[TAM] = TEXT("Software\\AULA\\");
	TCHAR chave_nome[TAM];//nome da chave

	TCHAR par_nome[TAM]; //nome do par-valor
	TCHAR par_valor[TAM];//valor do par-valor


#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	/*Perguntar ao utilizado o nome da chave a criar para ser criada na diretoria Software\AULA\....*/
	_tprintf(TEXT("Qual é o nome da chave: "));
	_fgetts(chave_nome, TAM, stdin);

	/*Concatenar a chave_dir com a chave_nome para criar o diretorio correto*/
	_tcscat_s(chave_dir, TAM, chave_nome);

	
	/*Criar ou abrir a chave dir no Registry*/
	if (RegCreateKeyEx(
		HKEY_CURRENT_USER,
		chave_dir,
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		NULL,
		&chave,
		&resultado
	) != ERROR_SUCCESS) {
		_tprintf(TEXT("Chave nao foi nem criada nem aberta! ERRO!"));
		return -1;
	}
	if (resultado == REG_CREATED_NEW_KEY)
		_tprintf(TEXT("A chave foi criada: %s"), chave_nome);
	else
		_tprintf(TEXT("A chave foi aberta: %s"), chave_nome);

	/*Entra no ciclo de criação de pares-valores*/
	do {
		/*Pede o nome e valor do atributo*/
		_tprintf(TEXT("Nome do par-valor ou 'fim' para terminar:"));_tscanf_s(TEXT("%s"), par_nome,TAM);

		if (_tcscmp(par_nome, TEXT("fim")) == 0) {
			break;
		}
		_tprintf(TEXT("Valor do par-valor: "));_tscanf_s(TEXT("%s"), par_valor,TAM);

		/*Criar par nome-atributo*/
		if (RegSetValueEx(
			chave,
			par_nome,
			0,
			REG_SZ,
			(LPCBYTE)&par_valor,
			sizeof(TCHAR) * (_tcslen(par_valor) + 1) //lê o buffer todo
		) != ERROR_SUCCESS)
			_tprintf(TEXT("O atributo nao foi alterado nem criado! ERRO! %s"), par_nome);
	} while (1);


	/*Entra no ciclo de verificação de valores dos pares-valores*/
	do {
		TCHAR nome[TAM];
		/*Pede nome do par_nome*/
		_tprintf(TEXT("Nome do par_nome ou 'fim' para terminar: "));_tscanf_s(TEXT("%s"), nome,TAM);
		if (_tcscmp(nome, TEXT("fim")) == 0) {
			break;
		}
		//Consultar valor de um atributo
		par_valor[0] = '\0';
		DWORD tamanho = sizeof(par_valor);
		if (RegQueryValueEx(
			chave,
			nome,
			0,
			NULL,
			(LPBYTE)par_valor,
			&tamanho
		) != ERROR_SUCCESS)
			_tprintf(TEXT("Atributo [%s] não foi encontrado!\n"),par_nome);
		else
			_tprintf(TEXT("\nAtributo encontrado com o valor : %s e tamaho : %d\n"), par_valor, tamanho);
	} while (1);

	RegCloseKey(chave); //fechar sempre o handle
	return 0;
}