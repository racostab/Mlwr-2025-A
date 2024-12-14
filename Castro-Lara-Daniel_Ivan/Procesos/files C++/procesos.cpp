/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C++
	$ gcc -o procesos_v0_param procesos_v0_param.cpp
*/

#include <iostream>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX 5

int main() {
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 500000000; // 500 milisegundos

    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();
        switch (pid) {
            case -1:
                std::cerr << "ERROR" << std::endl;
                return 1;
            case 0:
                for (int k = MAX; k >= 1; k--) {
                    std::cout << "H= " << getpid() << std::endl;
                    nanosleep(&ts, NULL);
                }
                return 0;
            default:
                wait(NULL); // Espera a que el proceso hijo termine
        }
    }
    return 0;
}

//programe que regrese un parametro a la terminal
