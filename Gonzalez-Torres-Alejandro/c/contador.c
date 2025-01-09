#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <sys/wait.h>

// Función para manejar el incremento del contador
void manejar_proceso(unsigned id)
{
    int contador = 0;
    FILE *archivo;

    while (1)
    {
        archivo = fopen("contador.txt", "r+");
        if (archivo == NULL)
        {
            perror("No se pudo abrir el archivo");
            return;
        }

        if (flock(fileno(archivo), LOCK_EX) == -1)
        {
            perror("No se pudo bloquear el archivo");
            fclose(archivo);
            return;
        }

        // Leer, incrementar y escribir el nuevo valor en el archivo
        fscanf(archivo, "%d", &contador);
        contador++;
        fseek(archivo, 0, SEEK_SET);
        fprintf(archivo, "%d", contador);

        // Liberar el bloqueo y cerrar el archivo
        flock(fileno(archivo), LOCK_UN);
        fclose(archivo);

        usleep(100000); // Pausa de 100 milisegundos
        printf("<Proceso: %d, Contador: %d>\n", getpid(), contador);
    }
}

int main(int argc, char **args)
{
    pid_t id_proceso;
    FILE *archivo = fopen("contador.txt", "w");

    // Verificar si se puede crear el archivo inicial
    if (archivo == NULL)
    {
        perror("Error al crear el archivo de contador");
        return 1;
    }

    fprintf(archivo, "0");
    fclose(archivo);

    // Crear dos procesos hijos
    for (int indice = 0; indice < 2; indice++)
    {
        id_proceso = fork();

        if (id_proceso == -1)
        {
            perror("Error al crear un proceso hijo");
            return 1;
        }

        if (id_proceso == 0)
        {
            manejar_proceso(indice);
            return 0;
        }
    }

    // Esperar a que los procesos hijos terminen
    for (int indice = 0; indice < 2; indice++)
    {
        wait(NULL);
    }

    return 0;
}
