#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void hijo()
{
    sleep(1);
    printf("Adios mundo cruel. PID del hijo: %d\n", getpid());
    // Puedes agregar la funcionalidad de nanosleep si lo necesitas
}

void padre()
{
    // Espera a que terminen los hijos
    for (int i = 0; i < 3; i++) {
        wait(NULL);  // Espera a que cualquier hijo termine
    }
    printf("Todos los hijos han terminado\n");
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        pid_t pid = fork();
        if (pid == -1) {
            // Error en fork
            printf("Error al crear proceso hijo\n");
            return 1;
        } else if (pid == 0) {
            // Código del hijo
            hijo();
            exit(0);  // El hijo termina aquí
        }
    }

    // Código del padre
    padre();
    system("ps");  // Mostrar los procesos actuales después de que los hijos terminen
    printf("El proceso padre ha terminado. PID del padre: %d\n", getpid());

    return 0;
}

