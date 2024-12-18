#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int N;

    // Check if the program has the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "ERR: no params\n");
        return 1;
    } else {
        N = atoi(argv[1]); // Convert command-line argument to an integer
    }

    // Fork N times to create N child processes
    for (int i = 1; i <= N; i++) {
        if (fork() == -1) {
            fprintf(stderr, "ERROR: Failed to fork\n");
        }
    }

    // Print the process ID of each process (parent or child)
    printf("Process PID: %d\n", getpid());
    return 0;
}

