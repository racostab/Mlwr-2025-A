#include <iostream>
#include <unistd.h>
#include <cstring>

int main() {
    int fd[2];
    char buf[] = "abcde", rbuf[6];
    pipe(fd);

    if (fork() == 0) { // Child process
        close(fd[1]); // Close write end
        read(fd[0], rbuf, 5);
        rbuf[5] = '\0';
        std::cout << "H: " << rbuf << std::endl;
    } else { // Parent process
        close(fd[0]); // Close read end
        write(fd[1], buf, 5);
        std::cout << "P: " << buf << std::endl;
    }

    return 0;
}
