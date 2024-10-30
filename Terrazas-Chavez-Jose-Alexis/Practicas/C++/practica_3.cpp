#include <iostream>
#include <unistd.h>  // Para fork(), getpid(), sleep()
#include <cstdlib>   // Para system()

using namespace std;

void proceso_hijo(int max_time) {
    cout << "Soy el proceso hijo con PID " << getpid() << endl;
    for (int i = 1; i <= max_time; ++i) {
        cout << "Proceso hijo esperando " << i << " segundos con un PID de " << getpid() << endl;
        sleep(2);  // Pausar por 2 segundos en cada iteración
    }
    cout << "Adios mundo cruel..." << endl;
}

void proceso_padre(pid_t pid_hijo) {
    cout << "He creado un proceso hijo con PID " << pid_hijo << endl;
    sleep(10);  // Espera 10 segundos antes de continuar
    cout << "El proceso padre ha terminado" << endl;
    system("ps");  // Ejecuta el comando 'ps'
}

int main() {
    const int max_time = 5;

    cout << "Proceso principal con PID " << getpid() << endl;

    pid_t pid = fork();  // Crear proceso hijo

    if (pid == 0) {
        proceso_hijo(max_time);
    } else if (pid > 0) {
        proceso_padre(pid);
    } else {
        cerr << "Error al crear el proceso" << endl;
        return 1;
    }
    return 0;
}
