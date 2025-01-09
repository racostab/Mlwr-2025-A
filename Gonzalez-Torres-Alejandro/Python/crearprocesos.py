/*
El programa crea un proceso hijo utilizando fork(). El proceso hijo imprime su PID y espera durante 5 segundos, mostrando un mensaje por segundo. Mientras tanto, el proceso principal continúa sin realizar acciones adicionales. Este ejemplo ilustra cómo trabajar con procesos en C.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void run_process() {
    int _wait_time = 5; // Tiempo de espera en segundos

    printf("Proceso principal activo con PID %d\n", getpid());

    pid_t _proc_id = fork(); // Crear proceso hijo

    if (_proc_id == 0) {
        // Código ejecutado por el proceso hijo
        printf("Proceso hijo iniciado con PID %d\n", getpid());
        for (int _counter = 0; _counter < _wait_time; ++_counter) {
            printf("Proceso hijo en espera... %d segundos\n", _counter + 1);
            sleep(1);
        }
        printf("Proceso hijo finalizado.\n");
        exit(0); // Terminar el proceso hijo
    } else if (_proc_id > 0) {
        // Código ejecutado por el proceso principal
        // No hace nada en este caso
    } else {
        // Error en la bifurcación
        perror("Error en fork");
        exit(1);
    }
}

int main() {
    run_process();
    return 0;
}

