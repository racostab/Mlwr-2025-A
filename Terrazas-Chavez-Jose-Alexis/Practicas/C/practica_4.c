#include <stdio.h>
#include <unistd.h>  // Para execl() y getpid()

int main() {
    printf("Proceso padre con PID %d\n", getpid());

    // Reemplaza el proceso actual con el comando 'ps -f'
    execl("/bin/ps", "ps", "-f", (char *)NULL);

    // Este mensaje nunca se mostrará
    printf("Nunca me verán\n");

    return 0;
}
