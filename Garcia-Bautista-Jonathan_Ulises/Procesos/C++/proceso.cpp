#include <iostream>

using namespace std;

class Procesos {
public:
    void ejecutar(int argc) {
        cout << "argc= " << argc - 1 << endl;
        if (argc == 1)
            return;
        else
            exit(argc);
    }
};

int main(int argc, char **argv) {
    Procesos p;
    p.ejecutar(argc);
    return 0;
}
