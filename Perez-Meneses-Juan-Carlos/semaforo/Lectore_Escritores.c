#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, write_sem;
int read_count = 0;

void *reader(void *arg) {
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1)
        sem_wait(&write_sem);
    sem_post(&mutex);

    printf("Lector está leyendo.\n");
    sleep(1);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0)
        sem_post(&write_sem);
    sem_post(&mutex);
    return NULL;
}

void *writer(void *arg) {
    sem_wait(&write_sem);
    printf("Escritor está escribiendo.\n");
    sleep(2);
    sem_post(&write_sem);
    return NULL;
}

int main() {
    pthread_t r[3], w[2];

    sem_init(&mutex, 0, 1);
    sem_init(&write_sem, 0, 1);

    for (int i = 0; i < 3; i++) pthread_create(&r[i], NULL, reader, NULL);
    for (int i = 0; i < 2; i++) pthread_create(&w[i], NULL, writer, NULL);

    for (int i = 0; i < 3; i++) pthread_join(r[i], NULL);
    for (int i = 0; i < 2; i++) pthread_join(w[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&write_sem);
    return 0;
}
