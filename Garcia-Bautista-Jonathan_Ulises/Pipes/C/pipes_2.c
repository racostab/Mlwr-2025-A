/*
    gcc -o pipes_2 pipes_2.c 
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int error, fd[2], pid, tam=5;

    char *buf="abcde";
    error = pipe (fd);

    if(error < 0)
    {
        printf("Error en la creacion del pipe\n");
        return 1;
    }

    pid = fork();
    switch(pid) {
    {
        case -1:
                    printf("Error de creacion");
                    exit(1);
        case 0:
                    read(fd[0], buf, tam);
                    printf("H= %s \n", buf);
                    break;
        default:
                    sleep (15);
                    write (fd[1], buf, tam);
                    printf("P= %s \n", buf);
                    break;
        }

    }
}
