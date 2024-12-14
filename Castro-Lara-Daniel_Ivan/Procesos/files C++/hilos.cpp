/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C++
	$ gcc -o procesos_v0_param procesos_v0_param.cpp
*/

#include <iostream>
#include <thread>
#include <unistd.h>  // Para getpid()

// Función para el hilo secundario
void thread() {
    while (true) {
        std::cout << "\t\t\t H=" << getpid() << std::endl;
    }
}

int main(int argc, char **argv) {
    try {
        // Crear el hilo
        std::thread t(thread);

        // Bucle infinito en el hilo principal
        while (true) {
            std::cout << "\tP=" << getpid() << std::endl;
        }

        // Esperar a que el hilo termine (no se ejecutará en este caso)
        t.join();
    } catch (const std::exception &e) {
        std::cerr << "Error en la creación del hilo: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

