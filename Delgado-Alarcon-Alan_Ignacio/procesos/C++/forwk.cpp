#include <iostream>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char **argv) {
    int N;
    if (argc != 2) {
        std::cerr << "ERR: no params" << std::endl;
        return 1;
    } else {
        N = std::atoi(argv[1]);
    }

    for (int i = 1; i <= N; i++) {
        if (fork() == -1) {
            std::cerr << "ERROR" << std::endl;
        }
    }
    std::cout << getpid() << std::endl;
    return 0;
}
