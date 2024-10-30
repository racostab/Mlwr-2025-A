/*
Programa que crea un proceso y seguidamente crealiza una sincronización de PID con el proceso
subsecuente, gracias al comando "execl" a través de la libreria "os" , esto quiere decir que el
proceso del padre lo obtendra la efecución del comando ps -f (se coloa f y no fea para visualizar
rapidamente el PID) por lo que en ese momento se detendrá el código de ejecución y no imprime el 
print despues de la sincronización.
*/
#include <iostream>
#include <unistd.h>  // Para execl() y getpid()

using namespace std;

int main() {
    cout << "Proceso padre con PID " << getpid() << endl;

    // Reemplaza el proceso actual con el comando 'ps -f'
    execl("/bin/ps", "ps", "-f", (char*)NULL);

    // Este mensaje nunca se mostrará
    cout << "Nunca me verán" << endl;

    return 0;
}
