/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C++
	$ gcc -o procesos_v0_param procesos_v0_param.cpp
*/

#include <iostream>
#include <unistd.h>   // Para pipe(), write()
#include <cstring>    // Para strlen()
#include <cerrno>     // Para errno
#include <cstdio>     // Para perror()

int main() {
    int fd[2];                  // Descriptores del pipe: fd[0] para lectura, fd[1] para escritura
    const char *buf = "a";      // Buffer que se escribirá en el pipe

    // Crear el pipe
    if (pipe(fd) < 0) {
        std::cerr << "Error en la creación del pipe: " << strerror(errno) << std::endl;
        return 1;
    }

    for (int i = 1; ; i++) {
        if (write(fd[1], buf, 1) < 0) {
            std::cerr << "Error al escribir en el pipe: " << strerror(errno) << std::endl;
            break;
        }

        std::cout << i << " ";
        std::cout.flush();  // Vaciar el búfer de salida para mostrar los números inmediatamente
    }

    // Cerrar los descriptores del pipe
    close(fd[0]);
    close(fd[1]);

    return 0;
}
