#include <iostream>    // For std::cout, std::cerr
#include <unistd.h>    // For fork(), getpid(), nanosleep()
#include <time.h>      // For nanosleep()
#include <cstdlib>     // For exit()

const int MAX = 5; // Countdown limit (number of iterations)

int main() {
    struct timespec ts; // Structure for nanosleep
    ts.tv_sec = 0;      // 0 seconds
    ts.tv_nsec = 500000000; // 500 milliseconds (in nanoseconds)

    for (int i = 1; i <= 3; i++) { // Loop to create 3 child processes
        pid_t pid = fork(); // Create a child process

        if (pid == -1) {
            std::cerr << "Error: Failed to create child process" << std::endl;
            return 1; // Exit on fork failure
        }

        if (pid == 0) { // Child process
            for (int k = MAX; k >= 1; k--) { // Countdown from MAX to 1
                std::cout << "Child Process [" << getpid() << "]: Countdown = " << k << std::endl;
                nanosleep(&ts, NULL); // Sleep for 500 milliseconds
            }
            exit(0); // Terminate child process
        }
    }

    return 0; // Parent process exits
}
