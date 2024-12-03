/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C que se encuentra en ciclo infinito realizando cambios de contexto.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void proceso(int pid) {
    int i = 1;
    while (1) {
        for (int t = 0; t <= pid; ++t) {
            printf("\t");
        }
        printf("<%d,%d>\n", getpid(), i);
        i++;
    }
}

int main() {
    const int N = 3;  

    for (int i = 1; i <= N; ++i) {
        pid_t pid = fork();  

        if (pid == 0) {
            proceso(i);
            exit(0);
        }
    }
	
    while (1) {
        sleep(1);  
    }
    return 0;
}

/*
    1.- gcc -o <ejecutable> <archivo_código>
    2.- <ejecutable>
*/





