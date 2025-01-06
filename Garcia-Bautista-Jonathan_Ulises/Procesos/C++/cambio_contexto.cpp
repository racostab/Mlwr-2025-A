#include <iostream>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>

using namespace std;

class Proceso {
public:
    Proceso(unsigned pid) : pid(pid) {}

    void ejecutar() {
        unsigned i = 1;
        while (true) {
            for (int t = 0; t <= pid; t++) {
                cout << "\t\t";
            }
            cout << "<" << getpid() << "," << i++ << ">" << endl;
            usleep(10000);
        }
    }

private:
    unsigned pid;
};

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <numero de procesos>" << endl;
        return 1;
    }

    int num_procesos = atoi(argv[1]);

    if (num_procesos <= 0) {
        cout << "El número de procesos debe ser un número entero positivo." << endl;
        return 1;
    }

    pid_t pid = 0;
    for (int i = 0; i < num_procesos; i++) {
        pid = fork();
        sleep(1);
        switch (pid) {
            case -1:  // Error
                cout << "Error" << endl;
                return 1;
            case 0:   // Proceso hijo
                Proceso proceso(i);
                proceso.ejecutar();
                break;
            default:   // Proceso padre
                break;
        }
    }

    return 0;
}
