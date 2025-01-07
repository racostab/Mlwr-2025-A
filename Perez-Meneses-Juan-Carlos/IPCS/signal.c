#include <stdio.h>
#include <signal.h>

void handler(int sig);

int main(void)
{
    signal(SIGUSR1, handler);

    while(1);
}

void handler(int sig)
{
    printf("Señal recibida !!!\n");
}

