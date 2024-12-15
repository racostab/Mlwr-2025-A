#include <iostream>  // Para std::cout y std::endl
#include <unistd.h>  // Para fork() y sleep()
#include <cstdlib>   // Para system() y exit()

void hijo() {
    sleep(2);
    std::cout << "quien?... te pregunto" << std::endl;
}

void padre() {
    sleep(10);
    system("ps");
    std::cout << "hijos de..." << std::endl;
}

int main() {
    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            std::cerr << "ERROR" << std::endl;
            return 1;
        }

        if (pid == 0) { 
            hijo();
            exit(0);
        } else { 
            padre();
        }
    }

    return 0;
}