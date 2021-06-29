#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>

// ESTRUTURA DE DADOS PARA COMUNICAR ENTRE CLIENTE E SERVIDOR
typedef struct {
    char nome[20];
    int num;
    int pid;
}PEDIDO;
