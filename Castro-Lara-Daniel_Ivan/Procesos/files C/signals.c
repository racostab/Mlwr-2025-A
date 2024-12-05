#include <stdio.h>
#include <signal.h>

void handler(void);

int main (void)
{
    signal(SIGUSR1, handler);
    while(1);
}

void handler(void)
{
    printf("Señal recibida!!! \n");
}

/*
    1.- gcc -o <ejecutable> <archivo_código>
    2.- <ejecutable>
*/
