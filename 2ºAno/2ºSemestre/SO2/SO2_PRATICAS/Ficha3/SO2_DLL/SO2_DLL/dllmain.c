#include <windows.h>
#include <tchar.h>


BOOL WINAPI DllMain(HANDLE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	

	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
		if (lpvReserved == NULL)
			_tprintf(TEXT("DLL loaded explicitly."));
		else
			_tprintf(TEXT("DLL loaded implicitly."));
		break;

	case DLL_PROCESS_DETACH:
		if (lpvReserved == NULL)
			_tprintf(TEXT("DLL loaded explicitly."));
		else
			_tprintf(TEXT("DLL loaded implicitly."));
		break;
	}

	return TRUE;
}