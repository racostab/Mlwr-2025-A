#include <iostream>
#include <thread>
#include <vector>

#define NUM_THREADS 5

void printHello(int threadId) {
    std::cout << "Hello World! It's me, thread #" << threadId << "!" << std::endl;
}

int main() {
    std::vector<std::thread> threads;
    for (int t = 0; t < NUM_THREADS; ++t) {
        std::cout << "In main: creating thread " << t << std::endl;
        threads.emplace_back(printHello, t);
    }

    for (auto &thread : threads) {
        thread.join();
    }

    return 0;
}
