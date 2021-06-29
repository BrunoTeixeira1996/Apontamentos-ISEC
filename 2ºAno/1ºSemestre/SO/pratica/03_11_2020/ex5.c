#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int a = 10;

	if (fork() == 0)
		a++;
	else
		a--;
	printf("\na = %d\n", a);


	return 0;
}

/*a = 9 e a = 11 , a ordem é desconhecida
porque o SO nao me garante nada*/