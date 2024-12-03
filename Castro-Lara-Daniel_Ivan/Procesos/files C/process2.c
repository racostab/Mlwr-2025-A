/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C que crea procesos padre e hijo y los imprime deacuerdo a la iteración for, más un padre. Todo eso en un tiempo específicado en el código.
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int i=0;

void hijo() {
    sleep(1);
    printf("HIJO\n");
}

void padre() {
    sleep (1);
    printf("PADRE\n");
}

int main() {
    for (i=1; i<=3; i++) {
        pid_t pid = fork();
        switch(pid) {
            case 1:
                printf("ERROR\n");
                return 1;
            case 0:
                hijo();
                exit(1);
            default:
                padre();
        }
    }            
    padre();
}    

/*
    1.- gcc -o <ejecutable> <archivo_código>
    2.- <ejecutable>
*/
