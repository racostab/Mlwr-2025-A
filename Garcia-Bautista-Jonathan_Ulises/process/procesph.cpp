#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
using namespace std;

int MAX = 10;

void hijo() {
    sleep(1);
    cout << "Adios mundo cruel" << endl;

    /*
    struct timespec ts;
    for (int k = MAX; k >= 1; k--) {
        std::cout << "H = " << getpid() << std::endl;
        nanosleep(&ts, NULL);
    }
    */
}

void padre() {
    sleep(5);
    system("ps");
    cout << "Hijos de..." << endl;
}

int main() {
    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();
        switch (pid) {
            case -1: // Error en fork
                std::cout << "Error" << std::endl;
                return 1;
            case 0: // Proceso hijo
                hijo();
                exit(0);
            default: // Proceso padre
                padre();
        }
    }
    padre();

    while (wait(nullptr) > 0);

    return 0;
}
