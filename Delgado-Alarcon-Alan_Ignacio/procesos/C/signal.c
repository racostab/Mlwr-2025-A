#include <stdio.h>
#include <signal.h>

void handler(void);

int main(void) {
    signal(SIGUSR1, handler);
    while(1);
}

void handler(void) {
    printf("Señal recibida!");
}

// este programa recibe señales
// otro programa que mande la señal

// colas de mesnajes son bloqueantes por primitiva
