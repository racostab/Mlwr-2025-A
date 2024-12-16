#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/wait.h>

#define FILENAME "contador.txt"

void actualizarArchivo(const char *columna, int delay) {
    FILE *file;
    int contador;

    while (1) {
        // Abrir el archivo en modo lectura y escritura
        file = fopen(FILENAME, "r+");
        if (file == NULL) {
            perror("Error al abrir el archivo");
            exit(EXIT_FAILURE);
        }

        // Bloquear el archivo para acceso exclusivo
        if (flock(fileno(file), LOCK_EX) != 0) {
            perror("Error al bloquear el archivo");
            fclose(file);
            exit(EXIT_FAILURE);
        }

        // Leer el valor del archivo
        fscanf(file, "%d", &contador);

        if (columna[0] == '1') {
            printf("Columna 1 | Ri = %-5d\n", contador);
        } else {
            printf("\t\tColumna 2 | Ri = %-5d\n", contador);
        }

        // Incrementar el valor leído
        contador++;

        // Rewind para sobrescribir desde el inicio
        rewind(file);
        fprintf(file, "%d\n", contador);
        fflush(file);

        if (columna[0] == '1') {
            printf("Columna 1 | Wi = %-5d\n", contador);
        } else {
            printf("\t\tColumna 2 | Wi = %-5d\n", contador);
        }

        // Desbloquear el archivo y cerrar
        flock(fileno(file), LOCK_UN);
        fclose(file);

        // Pausa para simular un retraso en la ejecución
        sleep(delay);
    }
}

int main() {
    // Crear el archivo inicial con valor 0
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Error al crear el archivo");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "0\n");
    fclose(file);

    // Crear dos procesos hijos
    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("Error al crear el primer proceso hijo");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        // Código para el primer proceso hijo (Columna 1 con delay de 2 segundos)
        actualizarArchivo("1", 2);
        exit(0);
    } else {
        pid_t pid2 = fork();
        if (pid2 < 0) {
            perror("Error al crear el segundo proceso hijo");
            exit(EXIT_FAILURE);
        }

        if (pid2 == 0) {
            // Código para el segundo proceso hijo (Columna 2 con delay de 3 segundos)
            actualizarArchivo("2", 3);
            exit(0);
        }
    }

    // Esperar a los procesos hijos (aunque este programa es infinito)
    wait(NULL);
    wait(NULL);

    return 0;
}
