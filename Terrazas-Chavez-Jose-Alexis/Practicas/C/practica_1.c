#include <stdio.h>
#include <unistd.h>  // Para fork(), getpid(), sleep()

int main() {
    const int max_time = 5;
    printf("Proceso principal con PID %d\n", getpid());

    pid_t pid = fork();  // Crear proceso hijo

    if (pid == 0) {
        // Código del proceso hijo
        printf("Soy el proceso hijo con PID %d\n", getpid());
        for (int i = 1; i <= max_time; ++i) {
            printf("Proceso hijo esperando... %d segundos\n", i);
            sleep(1);
        }
        printf("El proceso hijo ha terminado\n");
    } else if (pid > 0) {
        // Código del proceso padre
        sleep(max_time);  // Proceso padre espera 5 segundos
        printf("El proceso padre ha terminado\n");
    } else {
        perror("Error al crear el proceso");
        return 1;
    }
    return 0;
}
