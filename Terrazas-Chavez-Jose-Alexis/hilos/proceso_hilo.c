/*
Programa que crea un proceso e hilo con el mismo PID
*/
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void thread(void);

int main (int argc, char **argv)
{
        int pid;
        pthread_t tid;

                pid = pthread_create(&tid, NULL, (void *)&thread, NULL);
                if( pid < 0){
                        printf("error en la creación de hilo\n");
                        return 1;
        }
        while(1){
                printf("\tP=%d\n", getpid() );
                sleep(1);
        }

}

void thread(void)
{
        while(1){
                printf("\t\t\t H=%d\n", getpid());
                sleep(1);
        }
}
