/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C que crea un proceso imprimiendo el valor de argc.
*/

#include <stdio.h>

int main(int argc, char **argv){
    printf("argc= %d \n", argc);
    if(argc == 1) {
        return 0;
    } else {
        return argc;
    }
}

/*
    1.- gcc -o <ejecutable> <archivo_código>
    2.- <ejecutable>
*/
