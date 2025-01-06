/*
    gcc -o pipes_2 pipes_2.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int i, error, fd[2];
    char *buf="a";
    error = pipe(fd);
    if(error < 0)
    {
        printf("Error en la creación del pipe\n");
        return 1;
    }
    
    while(1)
    {
        write(fd[1],buf, 1);
        printf("%d ",i++);
        fflush(stdout);
    }
}