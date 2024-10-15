#include <iostream>

int main(int argc, char** argv) {
    std::cout << "argc = " << argc - 1 << std::endl;
    
    if (argc == 1) {
        return 0;
    } else {
        return argc;
    }
}
