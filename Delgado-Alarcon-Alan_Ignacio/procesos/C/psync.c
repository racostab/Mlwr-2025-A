#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void proceso(unsigned pid);
int counter=0;

int main(int argc, char **argv) {
	int N;
	
	if (argc != 2) {
		printf("ERR: no params\n");
		exit(1); 
	}
	else { N = atoi(argv[1]); }		
	
	FILE *fileRead, *fileWrite;
	fileRead = fopen("contador.txt","r");
	fileWrite = fopen("contador.txt", "w");
	if(fileRead == NULL){ printf("ERR: no read file");}

	for (int i =0; i<N; i++){
		pid_t pid = fork();
		switch(pid){
			case 1:
				printf("ERROR");
				return 1;
			case 0:
				proceso(i);
			default:;		
		}
	}	
}

void proceso(unsigned pid) {
FILE *fileRead, *fileWrite;
	fileRead = fopen("contador.txt","r");
	fileWrite = fopen("contador.txt", "w");	
	while(1){
		for(int t=0; t<=pid-1; t++){
			printf("\t\t");		
		}
		fscanf(fileRead,"< %d ", &counter);
		printf("<Value R: %d , PID: %d>\n", counter, getpid());
		counter++;
		sleep(1);
		for(int t=0; t<=pid-1; t++){
			printf("\t\t");				
		}
		fprintf(fileWrite, "%d\n", counter);
		printf("<Value W: %d , PID: %d>\n", counter, getpid());
		//sleep(1);
	}
	fclose(fileRead);
	fclose(fileWrite);
}
