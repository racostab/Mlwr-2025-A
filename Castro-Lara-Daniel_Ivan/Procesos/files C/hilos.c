/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C que implementa hilos en el espacio del kernal.
*/

#include <stdio.h>
#include <pthread.h>

void thread(void);

int main (int argc, char **argv)
{
    int pid;
    pthread_t tid;

       pid = pthread_create(&tid, NULL, (void *)&thread, NULL);
       if( pid < 0 ){
        printf("Error en la creacion del Thread\n");
        return 1;
       }
    while(1){
        printf("\tP=%d\n", getpid());
    }
}

void thread(void)
{
    while(1){
        printf("\t\t\t H=%d\n", getpid());
    }
}

/*
    1.- gcc -o <ejecutable> <archivo_código>
    2.- <ejecutable>
*/