#include <iostream>
#include <pthread.h>
#include <unistd.h> // For getpid()

void* thread(void*) {
    while (true) {
        std::cout << "\t\t\tH=" << getpid() << std::endl;
    }
    return nullptr;
}

int main() {
    pthread_t tid; // Thread ID

    // Create a new thread
    if (pthread_create(&tid, nullptr, thread, nullptr) != 0) {
        std::cerr << "ERR: Failed to create thread" << std::endl;
        return 1;
    }

    // Main thread
    while (true) {
        std::cout << "\tP=" << getpid() << std::endl;
    }

    return 0;
}
