#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    int fd[2];        // Descriptores de archivo para la tubería
    const char* buf;  // Datos a escribir en la tubería
} PipeWriter;

// Función para inicializar el PipeWriter
void initPipeWriter(PipeWriter* writer, const char* buffer) {
    writer->buf = buffer;
    if (pipe(writer->fd) < 0) {
        perror("Error en la creación del pipe");
        exit(EXIT_FAILURE);
    }
}

// Función para escribir en la tubería
void writeToPipe(PipeWriter* writer) {
    int i = 0;
    while (1) {
        write(writer->fd[1], writer->buf, 1); // Escribe 1 byte en la tubería
        printf("%d ", i++);
        fflush(stdout); // Asegura que el buffer de salida se imprima
    }
}

// Función para liberar recursos
void closePipeWriter(PipeWriter* writer) {
    close(writer->fd[0]);
    close(writer->fd[1]);
}

int main() {
    const char* buffer = "a";
    PipeWriter writer;

    initPipeWriter(&writer, buffer);
    writeToPipe(&writer);
    closePipeWriter(&writer);

    return 0;
}

