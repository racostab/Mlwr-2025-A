#include <iostream>
#include <csignal>
#include <unistd.h>

// Signal handler function
void handler(int signum) {
    std::cout << "Señal recibida!" << std::endl;
}

int main() {
    // Assign the handler to SIGUSR1
    std::signal(SIGUSR1, handler);
    std::cout << "Esperando señales... (envía SIGUSR1 para probar)" << std::endl;

    // Infinite loop to keep the program running
    while (true) {
        pause(); // Suspend the process until a signal is received
    }

    return 0;
}
