#include <iostream>
#include <unistd.h>  // Para fork(), getpid(), sleep()

using namespace std;

int main() {
    const int max_time = 5;
    cout << "Proceso principal con PID " << getpid() << endl;

    pid_t pid = fork();  // Crear proceso hijo

    if (pid == 0) {
        // Código del proceso hijo
        cout << "Soy el proceso hijo con PID " << getpid() << endl;
        for (int i = 1; i <= max_time; ++i) {
            cout << "Proceso hijo esperando... " << i << " segundos" << endl;
            sleep(1);
        }
        cout << "El proceso hijo ha terminado" << endl;
    } else if (pid > 0) {
        // Código del proceso padre
        sleep(max_time);  // El proceso padre espera 5 segundos
        cout << "El proceso padre ha terminado" << endl;
    } else {
        cerr << "Error al crear el proceso" << endl;
        return 1;
    }
    return 0;
}
