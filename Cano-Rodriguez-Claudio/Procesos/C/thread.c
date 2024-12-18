#include <stdio.h>      // For printf
#include <pthread.h>    // For pthread_create
#include <unistd.h>     // For getpid()

// Function executed by the child thread
void thread(void) {
    while (1) {
        printf("\t\t\tH=%d\n", getpid()); // Print PID with indentation
    }
}

int main(int argc, char *argv[]) {
    int pid;
    pthread_t tid; // Thread ID

    // Create a new thread
    pid = pthread_create(&tid, NULL, (void *)thread, NULL);
    if (pid < 0) {
        printf("ERR: no se creo el hilo\n"); // Error if thread creation fails
        return 1;
    }

    // Main thread continuously prints its PID
    while (1) {
        printf("\tP=%d\n", getpid()); // Print PID with single tab
    }
}
