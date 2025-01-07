#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <sys/wait.h>

using namespace std;

void proceso(unsigned pid)
{
    int i = 0;
    FILE* f;

    while (true)
    {
        f = fopen("contador.txt", "r+");
        if (f == nullptr)
        {
            perror("Error al abrir el archivo");
            return;
        }
        if (flock(fileno(f), LOCK_EX) == -1)
        {
            perror("Error al bloquear el archivo");
            fclose(f);
            return;
        }
        fscanf(f, "%d", &i);
        i++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", i);
        flock(fileno(f), LOCK_UN);
        fclose(f);
        usleep(100000);  // 100 milisegundos
        cout << "<PID: " << getpid() << ", Valor del contador: " << i << ">" << endl;
    }
}

int main() {
    pid_t pid;
    FILE* f = fopen("contador.txt", "w");
    if (f == nullptr)
    {
        perror("Error al crear el archivo");
        return 1;
    }
    fprintf(f, "0");
    fclose(f);
    for (int i = 0; i < 2; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("Error en fork");
            return 1;
        }
        if (pid == 0)
        {
            proceso(i);
            return 0;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        wait(NULL);
    }

    return 0;
}
