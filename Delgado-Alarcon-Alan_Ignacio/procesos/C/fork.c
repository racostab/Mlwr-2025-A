#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int N;
	if (argc != 2) {
		printf("ERR: no params\n");
		exit(1); 
	}
	else { 
		N = atoi(argv[1]); 
	}

	for(int i=1; i<=N; i++){
		if(fork() == -1) {
			printf("ERROR");		
		}
	} printf("%d \n",getpid());
}
