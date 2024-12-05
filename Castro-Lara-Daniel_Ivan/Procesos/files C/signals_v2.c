#include <stdio.h>
#include <signal.h>

void handler(int);

int main (void)
{
    signal(SIGUSR1, handler);
    while(1);
}

void handler(int sig)
{
    printf("Señal recibida!!! \n", sig);
}

/*
    1.- gcc -o <ejecutable> <archivo_código>
    2.- <ejecutable>
*/
