#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

pid_t pid;
int MAX = 10;
int k;

void hijo(); //Declaracion de la funcion hijo
void padre();// Declaracion de la funcion padre

int main(void){ 
	for(int i =1; i<=3; i++){ 
		pid = fork();
		switch(pid){ 
			case -1: 
				printf("Error\n");
				return 1;
			case 0:
				hijo();
				exit(1);
			default:
				padre();
				sleep(10);
				
		}
	}
	return 0;
}

void hijo()
{
	printf("Soy el hijo con PID = %d \n", getpid());
}

void padre(){ 
	printf("Soy el padre con PID = %d\n", getpid());
}
