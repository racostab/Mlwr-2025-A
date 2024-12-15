#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


int main (int argc, char **argv) {
    int error, fd[2], pid, tam=5;
    char *buf="abcde";

    error = pipe(fd);
    if (error < 0) {
        printf("Error en la creación del pipe\n");
        return 1;
    }

    pip = fork();
    switch(pid) {
        case ERROR:
            printf("Error de creación");
            exit(1);
        case HIJO:
            read(fd[0], buf, tam);
            printf("H= %s \n", buf);
            break
        default:
            sleep(15);
            write(fd[1], buf, tam);
            printf("P= %s \n", buf);
            break;
    }
}
