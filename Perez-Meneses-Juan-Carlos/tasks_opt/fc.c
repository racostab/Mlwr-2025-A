#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_FILOSOFOS 5

// Semáforos para los tenedores y el mutex
sem_t tenedores[NUM_FILOSOFOS];
sem_t mutex; // Controla el acceso para evitar deadlocks

void *filosofo(void *num) {
    int id = *(int *)num;

    while (1) {
        printf("Filósofo %d está pensando 🤔\n", id);
        sleep(rand() % 3 + 1); // Tiempo para pensar

        // Intentar tomar tenedores
        sem_wait(&mutex); // Controlar que solo 4 filósofos intenten comer a la vez
        sem_wait(&tenedores[id]); // Tomar el tenedor izquierdo
        sem_wait(&tenedores[(id + 1) % NUM_FILOSOFOS]); // Tomar el tenedor derecho

        printf("Filósofo %d está comiendo 🍝\n", id);
        sleep(rand() % 3 + 1); // Tiempo para comer

        // Soltar tenedores
        sem_post(&tenedores[id]); // Soltar el tenedor izquierdo
        sem_post(&tenedores[(id + 1) % NUM_FILOSOFOS]); // Soltar el tenedor derecho
        sem_post(&mutex); // Permitir que otro filósofo intente comer

        printf("Filósofo %d ha terminado de comer y está pensando nuevamente 🤔\n", id);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t hilos[NUM_FILOSOFOS];
    int id[NUM_FILOSOFOS];

    // Inicializar semáforos
    sem_init(&mutex, 0, NUM_FILOSOFOS - 1); // Solo 4 filósofos pueden comer simultáneamente
    for (int i = 0; i < NUM_FILOSOFOS; i++) {
        sem_init(&tenedores[i], 0, 1); // Inicializar cada tenedor como disponible
    }

    // Crear hilos para cada filósofo
    for (int i = 0; i < NUM_FILOSOFOS; i++) {
        id[i] = i;
        pthread_create(&hilos[i], NULL, filosofo, (void *)&id[i]);
    }

    // Esperar a que terminen los hilos (en este caso, nunca terminarán)
    for (int i = 0; i < NUM_FILOSOFOS; i++) {
        pthread_join(hilos[i], NULL);
    }

    // Destruir semáforos (nunca se llega aquí en este ejemplo)
    for (int i = 0; i < NUM_FILOSOFOS; i++) {
        sem_destroy(&tenedores[i]);
    }
    sem_destroy(&mutex);

    return 0;
}
