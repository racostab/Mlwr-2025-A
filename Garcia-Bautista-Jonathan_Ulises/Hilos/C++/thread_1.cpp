#include <iostream>
#include <thread>
#include <unistd.h>
#include <sys/types.h>

class ThreadManager {
public:
    // Método que se ejecuta en el hilo secundario
    void threadFunction() {
        while (true) {
            std::cout << "\t\t\t H = " << getpid() << std::endl;
            sleep(1);  // Sleep por 1 segundo
        }
    }

    // Método para crear el hilo secundario y ejecutar el proceso principal
    void run() {
        // Crear un hilo secundario que ejecuta la función threadFunction
        std::thread worker(&ThreadManager::threadFunction, this);

        // Ejecutar el hilo principal
        while (true) {
            std::cout << "\n\tP = " << getpid() << std::endl;
            sleep(1);  // Sleep por 1 segundo
        }

        // Asegurarse de que el hilo termine antes de salir (siempre se debe hacer join)
        worker.join();
    }
};

int main() {
    // Crear un objeto de la clase ThreadManager
    ThreadManager manager;

    // Llamar al método run() para iniciar el programa
    manager.run();

    return 0;
}
