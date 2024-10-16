#include <stdio.h>

int main(int argc, char *argv[])
{
    // Mostrar el número de argumentos pasados, excluyendo el nombre del programa
    printf("argc = %d\n", argc - 1);

    // Si no hay argumentos adicionales, termina con código de salida 0
    if (argc == 1)
        return 0;

    // Devolver el número de argumentos totales
    return argc - 1;
}

