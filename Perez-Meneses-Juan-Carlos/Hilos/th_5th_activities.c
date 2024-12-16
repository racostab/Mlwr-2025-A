#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
    long tid;
    tid = (long)threadid;
    
    printf("Hello World! It's me, thread #%ld!\n", tid);
    
    // Permitir que el hilo se pueda cancelar de forma asíncrona
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    
    // Bucle para mantener el hilo en ejecución
    while (1) {
        printf("Thread #%ld is still running...\n", tid);
        sleep(1);  // Simular trabajo en ejecución
    }

    // Si el hilo es cancelado, este mensaje no se mostrará
    pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    // Crear hilos
    for(t = 0; t < NUM_THREADS; t++) {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Esperar un momento antes de cancelar un hilo
    sleep(3);

    // Cancelar el hilo 2 como ejemplo
    printf("In main: canceling thread 2\n");
    pthread_cancel(threads[2]);

    // Esperar la terminación de todos los hilos
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
        printf("In main: thread %ld has been joined and terminated\n", t);
    }

    printf("All threads have completed or been canceled. Exiting program.\n");
    pthread_exit(NULL);
}
