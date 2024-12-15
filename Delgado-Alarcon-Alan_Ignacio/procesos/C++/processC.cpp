#include <iostream>  // Para usar std::cout

int main(int argc, char **argv) {
    std::cout << "argc = " << argc << std::endl;

    if (argc == 1) {
        return 0;
    } else {
        return argc;
    }
}