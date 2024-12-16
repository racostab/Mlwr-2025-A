#include <iostream>
#include <unistd.h>
#include <sys/types.h>

void proceso(unsigned pid);

int main() {
    unsigned N = 5; // Cambia el valor de N según lo necesites
    for (unsigned i = 1; i <= N; i++) {
        pid_t pid = fork();
        if (pid == 0) { // Proceso hijo
            proceso(i);
            return 0; // Terminar el proceso hijo
        }
    }
    return 0;
}

void proceso(unsigned pid) {
    unsigned i = 1;
    while (true) {
        for (unsigned t = 0; t <= pid; t++) {
            std::cout << "\t";
        }
        std::cout << "<" << getpid() << "," << i++ << ">" << std::endl;
        usleep(500000); // Espera 0.5 segundos para evitar saturación
    }
}
