#include <stdio.h>
#include <unistd.h>  // Para fork(), getpid(), sleep()
#include <stdlib.h>  // Para exit()

void proceso(int pid) {
    int i = 1;
    while (1) {
        for (int t = 0; t <= pid; ++t) {
            printf("\t");
        }
        printf("<%d,%d>\n", getpid(), i);
        i++;
        // sleep(1);  // Simular tiempo de ejecución
    }
}

int main() {
    const int N = 3;  // Número de procesos

    for (int i = 1; i <= N; ++i) {
        pid_t pid = fork();  // Crear proceso hijo

        if (pid == 0) {
            proceso(i);  // Ejecutar la función en el hijo
            exit(0);  // Terminar el proceso hijo
        }
    }

    // Mantener el proceso padre corriendo
    while (1) {
        sleep(1);  
    }

    return 0;
}
