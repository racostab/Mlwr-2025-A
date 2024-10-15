#include <iostream>   // Para std::cout y std::endl
#include <unistd.h>   // Para fork() y getpid()
#include <time.h>     // Para nanosleep()
#include <cstdlib>    // Para exit()

const int MAX = 5;

int main() {
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 500000000;  // 500 milisegundos
    
    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            std::cerr << "Error al crear el proceso hijo" << std::endl;
            return 1;
        }

        if (pid == 0) {
            for (int k = MAX; k >= 1; k--) {
                std::cout << "H= " << getpid() << std::endl;
                nanosleep(&ts, NULL);
            }
            return 0;
        }
    }
    return 0;
}
