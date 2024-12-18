#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char buf[] = "abcde", rbuf[6]; // Buffer for writing and reading
    pipe(fd);

    if (fork() == 0) { // Child process
        close(fd[1]); // Close write end
        read(fd[0], rbuf, 5);
        rbuf[5] = '\0';
        printf("H: %s\n", rbuf);
    } else { // Parent process
        close(fd[0]); // Close read end
        write(fd[1], buf, 5);
        printf("P: %s\n", buf);
    }
    return 0;
}
