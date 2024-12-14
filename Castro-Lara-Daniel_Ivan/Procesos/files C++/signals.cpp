/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C++
	$ gcc -o procesos_v0_param procesos_v0_param.cpp
*/

#include <iostream>
#include <csignal>  // Para el manejo de señales
#include <unistd.h> // Para la función sleep

// Manejador de señales
void handler(int signum) {
    std::cout << "¡Señal recibida!" << std::endl;
}

int main() {
    // Asignar el manejador a la señal SIGUSR1
    std::signal(SIGUSR1, handler);

    std::cout << "Esperando señales... (envía SIGUSR1 para probar)" << std::endl;

    // Bucle infinito para mantener el programa en ejecución
    while (true) {
        sleep(1); // Evitar que el bucle consuma demasiados recursos
    }

    return 0;
}

