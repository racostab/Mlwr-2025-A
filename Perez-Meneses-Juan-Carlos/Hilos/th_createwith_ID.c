#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function definition
void* thread_function(void* arg) {
    int thread_id = *((int*)arg);  // Retrieve the thread ID from the argument
    printf("Thread %d is running.\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];  // Array to hold thread identifiers
    int thread_ids[3];     // Array to hold unique thread IDs for passing to each thread

    // Create 3 threads
    for (int i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;  // Assign a unique ID to each thread
        int result = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        if (result != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < 3; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return 1;
        }
    }

    printf("All threads have finished.\n");
    return 0;
}
