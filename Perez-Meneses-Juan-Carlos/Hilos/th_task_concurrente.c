#include <stdio.h>
#include <pthread.h>
#include <time.h>

void thread(void);

int main(int argc, char **argv)
{
	int pid;
	pthread_t tid;
	
	pid = pthread_create(&tid, NULL, (void*)&thread, NULL);
	if (pid<0){
		printf("Error en la creacion del threadd \n");
		return 1;
	}
	
	while(1){
		printf("\t P=%d\n", getpid());
		sleep(1);
	}
}


void thread(void){
	while(1){
		printf("\t\t\t H=%d\n", getpid());
		sleep(1);

	}	
}
