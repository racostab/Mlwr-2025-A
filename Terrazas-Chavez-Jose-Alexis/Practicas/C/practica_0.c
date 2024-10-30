/*
Programa que recibe argumentos de entrada e imprime el número de ellos
Es necesario compilar el programa de la siguiente manera 'gcc -o practica_0 practica_0.c'
ppsteriormente se ejecuta de la siguiente manera ./practica_0 ls echo
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("argc = %d\n", argc);

    if (argc == 1) {
        return 0;
    } else {
        return argc;
    }
}
