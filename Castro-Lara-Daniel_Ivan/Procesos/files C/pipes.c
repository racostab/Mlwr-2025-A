/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C que crea por medio de pipe el total de procesos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main (int argc, char **argv)
{
    int i, error, fd[2];
    char *buf="a";

        error = pipe(fd);
        if(error<0){
            printf("Error en la creacion del pipe\n");
            return 1;
        }

    for (i=1; ;i++) {
        write (fd[1], buf, 1);
        printf("%d ", i);
        fflush(stdout);
    }
} 

// 28/nov/2024 macOS M1 65536 

/*
    1.- gcc -o <ejecutable> <archivo_código>
    2.- <ejecutable>
*/
