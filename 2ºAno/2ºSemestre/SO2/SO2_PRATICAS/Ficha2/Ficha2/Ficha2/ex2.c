#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#define TAM 200
/*
int _tmain(int argc, TCHAR* argv[]) {
	HKEY chave; //Handle para a chave depois aberta/criada
	DWORD resultado; // o que aconteceu com a chave
	TCHAR chave_nome[TAM] = TEXT("SOFTWARE\\SO2\\chaveP55");
	TCHAR par_nome[TAM] = TEXT("1º atributo");
	TCHAR par_valor[TAM] = TEXT("É o novo valor");
#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif
*/
/*
	//Criar ou abrir uma chave do Registry
	if (RegCreateKeyEx(
		HKEY_CURRENT_USER ,				//HKEY hKey -> qual a diretoria onde eu quero criar a chave,
		chave_nome,						//LPCTSTR lpSubKey -> qual é o nome desta chave
		0,								//DWORD Reserved
		NULL,							// LPTSTR lpClass
		REG_OPTION_NON_VOLATILE,		// -> a chave nao se apaga quando se desliga e liga o pc
		KEY_ALL_ACCESS,					// -> podemos fazer tudo da chave
		NULL,							//const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
		&chave,						//PHKEY phkResult
		&resultado) != ERROR_SUCCESS) {
		_tprintf(TEXT("Chave nao foi criada nem aberta ! ERRO!\n"));
		return -1;
	}

	//é porque a chave foi criada
	if (resultado == REG_CREATED_NEW_KEY)
		_tprintf(TEXT("A chave foi criada: %s\n"), chave_nome);
	//é porque a chave ja existe e foi aberta
	else
		_tprintf(TEXT("A chave foi aberta:%s\n"), chave_nome);

	//Criar par nome de atributo = valor (1 por cada chamada da função)
	//Tipo : String(REG_SZ), Inteiro(REG_DWORD), Bloco de Bytes(REG_BINARY)
	if (RegSetValueEx(
		chave,						//HKEY   hKey
		par_nome,					//LPCSTR     lpValueName,
		0,							//DWORD      Reserved,
		REG_SZ,						//DWORD      dwType -> tipo do atributo,
		par_valor,					//const BYTE * lpData -> que valor queremos lá por
		sizeof(TCHAR)*(_tcslen(par_valor)+1)			//DWORD      cbData -> tamanho do valor + 1 para terminar a string
	) != ERROR_SUCCESS)
		_tprintf(TEXT("Atributo não foi alterado nem criado ! ERRO!\n"));

	//Consultar um valor de um atributo
	//strcpy(par_nome, TEXT("2º atributo")); -> caso fosse necessario , escrever para a string em C depois de criado
	par_valor[0] = '\0'; // esta vazio
	DWORD tamanho = sizeof(par_valor);

	if (RegQueryValueEx(
		chave,	
		par_nome,
		0,							//DWORD      Reserved,
		NULL,						
		par_valor,
		&tamanho
	) != ERROR_SUCCESS)
		_tprintf(TEXT("Atributo não foi encontrado! ERRO!\n"));
	else
		_tprintf(TEXT("Atributo encontrado com valor:%s e tamanho:%d\n"), par_valor, tamanho);


	RegCloseKey(chave);//fechar o handle da chave no fim do programa
	return 0;
}
*/