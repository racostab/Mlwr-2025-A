#include <stdio.h>
#include <unistd.h>
#include <time.h>

pid_t pid;
int i;
int k;
int MAX = 10;
int main(void){ 
	for (i = 1; i<= 3; i++){ 
		pid = fork();
		switch(pid){
			case -1: //ERROR
				printf("Error\n");
				return(1);
			case 0: //HIJO
				for(k=MAX; k>=1; k--){ 
					printf("H=%d \n", getpid());
				}
				return 0;
	
				// Y si hay mas tipo de hijos?
				// Se requiere otra loggica!
			default: //PADRE
		}
	}
}
