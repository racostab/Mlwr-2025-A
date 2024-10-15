#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>


int main(int argc, char **argv)
{ 
	printf("argc = %d \n", argc-1);
	if (argc == 1)
		return 0;
	else
		return argc;
}


