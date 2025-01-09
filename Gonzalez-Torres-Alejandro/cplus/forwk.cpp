// Este programa crea un número de procesos hijo especificado por el argumento de línea de comandos.
// Cada proceso imprime su PID (Process ID) al finalizar.

#include <iostream>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char **argv) {
    int x; // Cantidad de procesos a crear.
    if (argc != 2) {
        std::cerr << "ERR: Faltan parámetros" << std::endl;
        return 1; // Salida con error.
    } else {
        x = std::atoi(argv[1]); // Convierte el argumento en un entero.
    }

    for (int y = 1; y <= x; ++y) {
        if (fork() == -1) { // Crea un proceso hijo y verifica errores.
            std::cerr << "ERR: Fallo en fork()" << std::endl;
        }
    }
    std::cout << getpid() << std::endl; // Imprime el PID del proceso actual.
    return 0; // Finaliza el programa.
}
