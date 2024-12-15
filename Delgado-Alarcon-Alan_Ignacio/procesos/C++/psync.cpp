#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>

void proceso(unsigned pid);
int counter = 0;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "ERR: no params" << std::endl;
        return 1;
    }

    int N = std::atoi(argv[1]);

    for (int i = 0; i < N; ++i) {
        pid_t pid = fork();
        if (pid == -1) {
            std::cerr << "ERROR" << std::endl;
            return 1;
        } else if (pid == 0) {
            proceso(i);
            exit(0);
        }
    }

    while (wait(NULL) > 0);
    return 0;
}

void proceso(unsigned pid) {
    while (true) {
        std::ifstream fileRead("contador.txt");
        std::ofstream fileWrite("contador.txt", std::ios::trunc);
        if (!fileRead.is_open() || !fileWrite.is_open()) {
            std::cerr << "ERR: file operation failed" << std::endl;
            exit(1);
        }

        for (int t = 0; t < pid; ++t) {
            std::cout << "\t\t";
        }

        fileRead >> counter;
        std::cout << "<Value R: " << counter << " , PID: " << getpid() << ">\n";
        ++counter;
        sleep(1);

        for (int t = 0; t < pid; ++t) {
            std::cout << "\t\t";
        }

        fileWrite << counter << std::endl;
        std::cout << "<Value W: " << counter << " , PID: " << getpid() << ">\n";
        fileRead.close();
        fileWrite.close();
    }
}
