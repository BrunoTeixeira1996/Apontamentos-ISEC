#include <windows.h>
#include <Windowsx.h>
#include <tchar.h>
#include "resource.h"

#define NUM_CLIENTES 3
#define LIST_SIZE 8

TCHAR* LIST_ITENS[] = {
	TEXT("10€"),
	TEXT("20€"),
	TEXT("40€"),
	TEXT("60€"),
	TEXT("80€"),
	TEXT("100€"),
	TEXT("150€"),
	TEXT("200€")
};

LRESULT CALLBACK TrataEventos(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK TrataEventosLogin(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK TrataEventosLevantar(HWND, UINT, WPARAM, LPARAM);

TCHAR szProgName[] = TEXT("Ficha8");

typedef struct {
	unsigned int ID;
	TCHAR username[16];
	TCHAR password[16];
	unsigned int saldo;
} cliente;

typedef struct {
	unsigned int tipo; // 1 = depósito, 2 = levantamento
	unsigned int quantia;
	unsigned int ID;
} operacao;

typedef struct {
	cliente clientes[NUM_CLIENTES];
	operacao historico[200];
	unsigned int numOperacoes;
} dados;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcApp;
	HANDLE hAccel;
	dados dadosPartilhados;

	wcApp.cbSize = sizeof(WNDCLASSEX);
	wcApp.hInstance = hInst;

	wcApp.lpszClassName = szProgName;
	wcApp.lpfnWndProc = TrataEventos;

	wcApp.style = CS_HREDRAW | CS_VREDRAW;

	wcApp.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
	wcApp.hIconSm = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
	wcApp.hCursor = LoadCursor(hInst, MAKEINTRESOURCE(IDC_POINTER));
	wcApp.lpszMenuName = MAKEINTRESOURCE(ID_MENU_PRINCIPAL);

	wcApp.cbClsExtra = sizeof(dados);
	wcApp.cbWndExtra = 0;
	wcApp.hbrBackground = CreateSolidBrush(RGB(220, 220, 220));

	if (!RegisterClassEx(&wcApp))
		return(0);

	hWnd = CreateWindow(
		szProgName,
		TEXT("SO2 - Ficha 8"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		300,
		150,
		(HWND)HWND_DESKTOP,
		(HMENU)NULL,
		(HINSTANCE)hInst,
		0);

	dadosPartilhados.numOperacoes = 5; // Apenas para testar...
	LONG_PTR x = SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)&dadosPartilhados);

	ShowWindow(hWnd, nCmdShow);

	hAccel = LoadAccelerators(NULL, MAKEINTRESOURCE(IDR_ACCELERATOR));

	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(hWnd, hAccel, &lpMsg))
		{
			TranslateMessage(&lpMsg);
			DispatchMessage(&lpMsg);
		}
	}

	return((int)lpMsg.wParam);
}

LRESULT CALLBACK TrataEventos(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	TCHAR str1[512], str2[512];
	dados * dadosPartilhados;

	dadosPartilhados = (dados *)GetWindowLongPtr(hWnd, GWLP_USERDATA);

	switch (messg)
	{
	// evento de criação de janela
	case WM_CREATE:
		// começa com os menus desativadas
		EnableMenuItem(GetMenu(hWnd), ID_CONSULTA, MF_DISABLED | MF_GRAYED);
		EnableMenuItem(GetMenu(hWnd), ID_LEVANTAMENTO, MF_DISABLED | MF_GRAYED);
		break;

	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case ID_LOGIN:
			// lida com a dialogbox
			// 1º contexto onde vai ser executada -> NULL porque é no contexto atual
			// 2º ID da dialogbox em si
			// 3º janela mae da dialogbox -> ou NULL(sistema assume que nao estou a usar uma janela modal e permite trabalhar nessa janela e na que está atrás)
			// ou o handle da janela principal
			// 4º serve para tratar os eventos das dialogbox
			DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG_LOGIN), hWnd, TrataEventosLogin);
			// ativa os submenus depois do login
			EnableMenuItem(GetMenu(hWnd), ID_CONSULTA, MF_ENABLED);
			EnableMenuItem(GetMenu(hWnd), ID_LEVANTAMENTO, MF_ENABLED);
			break;

		case ID_CONSULTA:
		case ID_ACCELERATOR_C:
			// LoadString() vai buscar uma string à tabela de strings
			LoadString(NULL, IDS_STR_CONSULTA, str1, 512);
			_stprintf_s(str2, 512, TEXT("%s (%d)"), str1, dadosPartilhados->numOperacoes);
			MessageBox(hWnd, str2, TEXT("String Table"), MB_OK | MB_ICONINFORMATION);
			break;

		case ID_ACCELERATOR_L:
		case ID_LEVANTAMENTO:

			DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG_LEVANTAMENTO), NULL, TrataEventosLevantar);
			break;

		}

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, messg, wParam, lParam);
		break;
	}

	return(0);
}

LRESULT CALLBACK TrataEventosLogin(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	TCHAR username[16];

	switch (messg)
	{
	case WM_COMMAND:

		// o LOWORD(wParam) traz o ID onde foi carregado 
		// se carregou no OK
		if (LOWORD(wParam) == IDOK)
		{
			// GetDlgItemText() vai à dialogbox e vai buscar o input do user
			GetDlgItemText(hWnd, IDC_EDIT_LOGIN, username, 16);
			MessageBox(hWnd, username, TEXT("Username"), MB_OK | MB_ICONINFORMATION);
		}
		// se carregou no CANCEL
		else if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hWnd, 0);
			return TRUE;
		}

		break;

	case WM_CLOSE:

		EndDialog(hWnd, 0);
		return TRUE;
	}

	return FALSE;
}

LRESULT CALLBACK TrataEventosLevantar(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	int i;
	HWND hwndList;
	// quando uma dialogbox é inicializava, ela recebe um evento chamado de WM_INITDIALOG
	// no caso das janelas, é um evento chamado de WM_CREATE

	switch (messg)
	{
	case WM_INITDIALOG:

		hwndList = GetDlgItem(hWnd, IDC_LIST_MONTANTES);
		SendMessage(hwndList, LB_RESETCONTENT, 0, 0);

		// enviamos uma mensagem para cada tipo da lista
		for (i = 0; i < LIST_SIZE; i++)
			SendMessage(hwndList, LB_ADDSTRING, 0, (LPARAM)LIST_ITENS[i]);

		break;

	// quando ha um evento sobre a listbox ha um evento WM_COMMAND
	case WM_COMMAND:

		if (LOWORD(wParam) == IDC_LIST_MONTANTES)
		{	
			// a HIWORD(wParam) mostra qual foi a operação feita sobre a dialogbox
			switch (HIWORD(wParam))
			{
			// caso seja duplo clique
			case LBN_DBLCLK:

				hwndList = GetDlgItem(hWnd, IDC_LIST_MONTANTES);
				i = (int)SendMessage(hwndList, LB_GETCURSEL, 0, 0);
				MessageBox(hWnd, LIST_ITENS[i], TEXT("ListBox"), MB_OK | MB_ICONINFORMATION);

				break;
			}
		}

		break;

	case WM_CLOSE:

		EndDialog(hWnd, 0);
		return TRUE;
	}

	return FALSE;
}
