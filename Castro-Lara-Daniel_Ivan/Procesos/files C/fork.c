/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C que duplica el proceso actual
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    
        pid = fork();
        switch(pid){
            case -1: 
                printf("Error de creación\n");
            case 0: 
                printf("Código del hijo\n");
            default: 
                printf("Código del padre\n");
        }
}   

/*
    1.- gcc -o <ejecutable> <archivo_código>
    2.- <ejecutable>
*/
