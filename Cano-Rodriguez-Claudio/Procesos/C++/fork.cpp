#include <iostream>  // For standard input/output
#include <cstdlib>   // For std::atoi (converting string to integer)
#include <unistd.h>  // For fork() and getpid()
#include <sys/types.h> // For pid_t

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        std::cerr << "ERR: No parameters provided. Usage: ./fork_example <N>" << std::endl;
        return 1; // Exit with error
    }

    // Convert argument to integer (number of processes)
    int N = std::atoi(argv[1]);
    if (N <= 0) {
        std::cerr << "ERR: Invalid number of processes. Please provide a positive integer." << std::endl;
        return 1;
    }

    // Fork N child processes
    for (int i = 0; i < N; i++) {
        pid_t pid = fork(); // Create a new process
        if (pid < 0) {
            std::cerr << "ERROR: Failed to fork process." << std::endl;
        } else if (pid == 0) {
            // Child process
            std::cout << "Child Process PID: " << getpid() << std::endl;
            _exit(0); // Exit the child process
        }
    }

    // Parent process prints its PID
    std::cout << "Parent Process PID: " << getpid() << std::endl;

    return 0; // Exit successfully
}
