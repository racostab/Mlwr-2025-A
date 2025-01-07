#include <iostream>
#include <signal.h>
#include <unistd.h>

class SignalHandler {
public:
    // Constructor
    SignalHandler() {
        // Asociamos la señal SIGUSR1 con el método handler de la clase
        signal(SIGUSR1, SignalHandler::handler);
    }

    // Método para iniciar el bucle de espera de señales
    void startListening() {
        // Bucle infinito para esperar señales
        while (true) {
            pause();  // Espera hasta que llegue una señal
        }
    }

private:
    // Método estático que manejará las señales
    static void handler(int sig) {
        std::cout << "¡Señal recibida!!! Signal: " << sig << std::endl;
    }
};

int main() {
    // Creamos un objeto de la clase SignalHandler
    SignalHandler signalHandler;

    // Iniciamos el proceso de escucha de señales
    signalHandler.startListening();

    return 0;
}
