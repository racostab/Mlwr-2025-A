/*
Programa que crea tres porcesos y realiza un cambio de contexto cada que uno termina,
el cambio de contexto lo determina el quantum.
Si se quiere detener proceso se tiene que colocar el comando ps -fea en otra terminar 
y una vez ubicado el PID matarlo con el el comando $kill <PID>
*/
#include <iostream>
#include <unistd.h>  // Para fork(), getpid(), sleep()
#include <cstdlib>   // Para exit()
using namespace std;

void proceso(int pid) {
    int i = 1;
    while (true) {
        for (int t = 0; t <= pid; ++t) {
            cout << "\t";
        }
        cout << "<" << getpid() << "," << i << ">" << endl;
        i++;
        // sleep(1);  // Simular el quantum con una pausa
    }
}

int main() {
    const int N = 3;  // Número de procesos

    for (int i = 1; i <= N; ++i) {
        pid_t pid = fork();  // Crear proceso hijo

        if (pid == 0) {
            proceso(i);  // Ejecutar función en proceso hijo
            exit(0);  // Terminar el proceso hijo
        }
    }

    // Mantener el proceso padre corriendo
    while (true) {
        sleep(1);  
    }

    return 0;
}
