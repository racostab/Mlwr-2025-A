#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void handler(int signum) {
    printf("Señal recibida!\n");
}

int main() {
    // Assign the handler to SIGUSR1
    signal(SIGUSR1, handler);
    printf("Esperando señales... (envía SIGUSR1 para probar)\n");

    // Infinite loop to keep the program running
    while (1) {
        pause(); // Suspend the process until a signal is received
    }

    return 0;
}
