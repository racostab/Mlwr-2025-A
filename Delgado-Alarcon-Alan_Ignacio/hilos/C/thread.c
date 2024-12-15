#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void thread(void);

int main(int argc, char **argv) {
	int pid;
	pthread_t tid;

	pid = pthread_create(&tid, NULL, (void *)&thread, NULL);
	if(pid < 0){
		printf("ERR: no se creo el hilo");
		return 1;
	}

	while(1){
		printf("\tP=%d\n", getpid());
	}
}


void thread(void){
	while(1){
		printf("\t\t\t H=%d\n", getpid());	
	}
}
