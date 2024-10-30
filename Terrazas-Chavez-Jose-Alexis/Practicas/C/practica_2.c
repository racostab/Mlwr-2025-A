#include <stdio.h>
#include <unistd.h>  // Para fork(), getpid(), sleep()
#include <stdlib.h>  // Para system()

void proceso_hijo(int max_time) {
    printf("Soy el proceso hijo con PID %d\n", getpid());
    for (int i = 1; i <= max_time; ++i) {
        printf("Proceso hijo esperando %d segundos con un PID de %d\n", i, getpid());
        sleep(2);  // Espera 2 segundos por iteración
    }
    printf("Adios mundo cruel...\n");
}

void proceso_padre(pid_t pid_hijo) {
    printf("He creado un proceso hijo con PID %d\n", pid_hijo);
    sleep(10);  // Espera 10 segundos
    printf("El proceso padre ha terminado\n");
    system("ps");  // Ejecutar comando 'ps'
}

int main() {
    const int max_time = 5;

    printf("Proceso principal con PID %d\n", getpid());

    pid_t pid = fork();  // Crear proceso hijo

    if (pid == 0) {
        proceso_hijo(max_time);
    } else if (pid > 0) {
        proceso_padre(pid);
    } else {
        perror("Error al crear el proceso");
        return 1;
    }
    return 0;
}
