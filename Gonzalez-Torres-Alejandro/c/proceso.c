/*
    Descripción:
    Este programa crea una cantidad definida de procesos utilizando `fork()`. 
    El número de procesos a crear se pasa como argumento al ejecutar el programa.
    Cada proceso imprime su número de orden y su PID.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **args)
{
    int contador_procesos = 0; // Contador de procesos creados

    // Validar número de argumentos
    if (argc != 2)
    {
        printf("Uso: %s <cantidad_de_procesos>\n", args[0]);
        return 1;
    }

    // Convertir argumento a número entero
    int cantidad_procesos = atoi(args[1]);

    // Validar que la cantidad de procesos sea positiva
    if (cantidad_procesos <= 0)
    {
        printf("Por favor, ingresa un número entero positivo como argumento.\n");
        return 1;
    }

    printf("Procesos a crear: %d\n", cantidad_procesos);

    // Crear procesos
    for (int indice = 1; indice <= cantidad_procesos; indice++)
    {
        contador_procesos++;

        if (fork() == -1)
        {
            perror("Error al crear un proceso");
            return 1;
        }

        // Imprimir información del proceso
        printf("Proceso número %d: PID %d\n", contador_procesos, getpid());
    }

    return 0;
}
