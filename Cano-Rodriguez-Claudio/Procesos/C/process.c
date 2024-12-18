#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5 // Countdown limit

int main() {
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 500000000; // 500 milliseconds

    for (int i = 1; i <= 3; i++) { // Create 3 child processes
        pid_t pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Error: Failed to create child process\n");
            return 1;
        }

        if (pid == 0) { // Child process
            for (int k = MAX; k >= 1; k--) {
                printf("Child Process [%d]: Countdown = %d\n", getpid(), k);
                nanosleep(&ts, NULL);
            }
            exit(0);
        }
    }

    return 0; // Parent process exits
}
