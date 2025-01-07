#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    sem_t *sem = sem_open("/sync_sem", O_CREAT, 0666, 0);

    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == 0) { // Proceso hijo
        printf("Hijo: Trabajando...\n");
        sleep(2);
        printf("Hijo: Trabajo terminado.\n");
        sem_post(sem); // Desbloquear al padre
        exit(0);
    } else { // Proceso padre
        printf("Padre: Esperando al hijo...\n");
        sem_wait(sem); // Esperar al hijo
        printf("Padre: Hijo ha terminado. Continuando...\n");
        sem_close(sem);
        sem_unlink("/sync_sem");
    }

    return 0;
}
