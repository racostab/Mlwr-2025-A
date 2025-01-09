#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>

// Función para simular un proceso
void ejecutar_proceso(unsigned identificador)
{
    unsigned contador = 1;
    while (1)
    {
        for (int espaciado = 0; espaciado <= identificador; espaciado++)
        {
            printf("\t");
        }
        printf("<%d, %d>\n", getpid(), contador++);
        usleep(10000);
    }
}

int main(int argc, char **args)
{
    // Validar argumentos
    if (argc != 2)
    {
        printf("Modo de uso: %s <cantidad_procesos>\n", args[0]);
        return 1;
    }

    int procesos_totales = atoi(args[1]); // Convertir argumento a entero

    // Validar entrada
    if (procesos_totales <= 0)
    {
        printf("La cantidad de procesos debe ser un número positivo.\n");
        return 1;
    }

    pid_t proceso_id = 0;

    for (int indice = 0; indice < procesos_totales; indice++)
    {
        proceso_id = fork(); // Crear proceso hijo

        sleep(1); // Pausa para sincronización

        switch (proceso_id)
        {
        case -1: // Error al crear proceso
            fprintf(stderr, "Error al crear proceso.\n");
            return 1;

        case 0: // Código del proceso hijo
            ejecutar_proceso(indice);
            break;

        default: // Código del proceso padre
            // El padre no realiza ninguna acción adicional
            break;
        }
    }

    return 0;
}
