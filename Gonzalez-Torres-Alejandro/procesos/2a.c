#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <sys/wait.h>

using namespace std;

void hijo()
{
    sleep(1);
    cout << "Adios mundo cruel. PID del hijo: " << getpid() << endl;
}

void padre()
{
    // Espera a que terminen los hijos
    for (int i = 0; i < 3; i++) {
        wait(NULL);  // Espera a que cualquier hijo termine
    }
    cout << "Todos los hijos han terminado" << endl;
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        pid_t pid = fork();
        if (pid == -1)

