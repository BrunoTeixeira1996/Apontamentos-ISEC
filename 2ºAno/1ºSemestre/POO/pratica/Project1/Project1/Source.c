#include <stdio.h>

int main() {
	printf("_MSC_VER : %d \n", _MSC_VER);
	printf("_MSC_FULL_VER : %d \n", _MSC_FULL_VER);
	printf("_MSC_BUILD : %d \n", _MSC_BUILD);

#ifdef _MSVC_LANG
	printf("_MSVC_LANG : C++%d \n", (_MSVC_LANG / 100) % 2000);
#endif

	return 0;
}