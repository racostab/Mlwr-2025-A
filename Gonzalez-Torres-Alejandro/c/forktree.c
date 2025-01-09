/*
    Este programa crea múltiples procesos hijos utilizando `fork()`. 
    Cada proceso hijo imprime su PID (`getpid()`), mientras que el proceso 
    padre continúa creando nuevos procesos. El programa demuestra cómo 
    se generan procesos en un árbol jerárquico.
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    int max_impresiones = 1; // Máximo de impresiones por hijo
    pid_t id_proceso = 0;    // Variable para almacenar el PID del proceso

    // Bucle principal para crear procesos
    for (int nivel = 0; nivel <= 3; nivel++) // Crea 2^n procesos en 3 niveles
    {
        id_proceso = fork(); // Crear un nuevo proceso

        switch (id_proceso)
        {
        case -1: // Error al crear un proceso
            perror("Error al crear proceso");
            return 1;

        case 0: // Código del proceso hijo
            for (int iteracion = max_impresiones; iteracion >= 1; iteracion--)
            {
                printf("Hijo (PID: %d)\n", getpid());
            }
            // Salida explícita para evitar que el hijo cree más procesos
            return 0;

        default: // Código del proceso padre
            // El padre continúa con el bucle y crea nuevos procesos
            break;
        }
    }

    return 0;
}
