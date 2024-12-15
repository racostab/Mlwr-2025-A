#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


int main (int argc, char **argv) {
    int i, error, fd[2];
    char *buf="a";

    error = pipe(fd);
    if (error < 0) {
        printf("Error en la creación del pipe\n");
        return 1;
    }

    for(i=1; ;i++) {
        write(fd[1], buf, 1);
        printf("%d", i);
        fflush(stdout);
    }
}
