#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int contador = 0; // Recurso compartido
sem_t sem;

void *incrementar(void *arg) {
    for (int i = 0; i < 5; i++) {
        sem_wait(&sem);
        contador++;
        printf("Hilo %ld incrementa contador: %d\n", (long)arg, contador);
        sem_post(&sem);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t hilos[3];
    sem_init(&sem, 0, 1); // Inicializar semáforo como mutex

    for (long i = 0; i < 3; i++) {
        pthread_create(&hilos[i], NULL, incrementar, (void *)i);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(hilos[i], NULL);
    }

    sem_destroy(&sem);
    printf("Contador final: %d\n", contador);
    return 0;
}
