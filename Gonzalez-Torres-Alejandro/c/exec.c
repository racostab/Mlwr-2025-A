#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    // Obtener el PID actual
    pid_t id_proceso = getpid();
    printf("Identificador del proceso actual: %d\n\n", id_proceso);

    // Ejecutar el comando 'ps -fea'
    execl("/usr/bin/ps", "ps", "-fea", (char *)NULL);

    // Este bloque nunca se ejecutará debido a execl
    {
        printf("Este mensaje no se verá debido a execl.\n");
    }

    return 0;
}
