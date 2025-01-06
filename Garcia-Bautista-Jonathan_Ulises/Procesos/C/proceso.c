/*
	Description
	  
	Compile
	  gcc -o procesos_v0_param procesos_v0_param.c
*/
#include <stdio.h>

int main (int argc, char **argv)
{
	printf("argc= %d \n",argc-1);
	if(argc==1)
		return 0;
	else
		return argc;
}
