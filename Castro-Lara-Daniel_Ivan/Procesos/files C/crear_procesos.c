/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C que crea reemplaza el proceso actual con el comando 'ps -f'.
*/

#include <stdio.h>
#include <unistd.h> 

int main() {
    printf("Proceso padre con PID %d\n", getpid());
    execl("/bin/ps", "ps", "-f", (char *)NULL);
    printf("Nunca me verán\n");
    return 0;
}

/*
    1.- gcc -o <ejecutable> <archivo_código>
    2.- <ejecutable>
*/

