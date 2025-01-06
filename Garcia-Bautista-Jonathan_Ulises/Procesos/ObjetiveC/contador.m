#import <Foundation/Foundation.h>
#import <unistd.h>
#import <sys/wait.h>
#import <fcntl.h>
#include <sys/file.h>  // Para flock()

void proceso(int pid) {
    int i = 0;
    NSFileHandle *fileHandle = nil;

    while (1) {
        // Usar NSAutoreleasePool para manejar la memoria correctamente
        NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

        // Abrir el archivo para leer y escribir
        fileHandle = [NSFileHandle fileHandleForUpdatingAtPath:@"contador.txt"];
        if (fileHandle == nil) {
            NSLog(@"Error al abrir el archivo");
            [pool release];  // Liberar el pool manualmente
            return;
        }

        // Bloquear el archivo (fileHandle fileDescriptor ya es un int)
        int fileDescriptor = [fileHandle fileDescriptor];
        if (flock(fileDescriptor, LOCK_EX) == -1) {
            NSLog(@"Error al bloquear el archivo");
            [fileHandle closeFile];
            [pool release];
            return;
        }

        // Leer el contador
        NSData *data = [fileHandle readDataOfLength:sizeof(int)];
        int *counter = (int *)[data bytes];
        i = *counter;

        // Incrementar el contador
        i++;

        // Volver al principio del archivo y escribir el nuevo valor
        [fileHandle seekToFileOffset:0];
        NSData *newData = [NSData dataWithBytes:&i length:sizeof(int)];
        [fileHandle writeData:newData];

        // Desbloquear el archivo
        flock(fileDescriptor, LOCK_UN);

        // Cerrar el archivo
        [fileHandle closeFile];

        // Dormir 100 milisegundos
        usleep(100000);

        // Mostrar el valor del contador
        NSLog(@"<PID: %d, Valor del contador: %d>", pid, i);

        // Liberar el pool
        [pool release];
    }
}

int main(int argc, const char * argv[]) {
    // Usar NSAutoreleasePool para manejar la memoria correctamente
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    // Crear el archivo y establecer el contador en 0 si no existe
    NSFileManager *fileManager = [NSFileManager defaultManager];
    if (![fileManager fileExistsAtPath:@"contador.txt"]) {
        // Crear el archivo y escribir 0 como entero en formato binario
        int initialValue = 0;
        NSData *initialData = [NSData dataWithBytes:&initialValue length:sizeof(int)];
        NSError *error = nil;
        [initialData writeToFile:@"contador.txt" options:NSDataWritingAtomic error:&error];

        if (error) {
            NSLog(@"Error escribiendo el archivo: %@", error.localizedDescription);
        }
    }

    pid_t pid;
    int i;
    for (i = 0; i < 2; i++) {
        pid = fork();  // Crear el proceso hijo
        if (pid == -1) {
            NSLog(@"Error en fork");
            return 1;
        }
        if (pid == 0) {
            proceso(i);  // Ejecutar el proceso en el hijo
            return 0;  // Terminar el proceso hijo
        }
    }

    // Esperar que los procesos terminen
    for (i = 0; i < 2; i++) {
        wait(NULL);  // Esperar a que cada proceso hijo termine
    }

    NSLog(@"Todos los procesos hijos han terminado.");

    [pool release];  // Liberar el pool manualmente
    return 0;
}
