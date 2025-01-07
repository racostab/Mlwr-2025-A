#include <stdio.h>
#include <unistd.h>


int main ()
{
int MAX = 1,pid = 0;

	for(int i=0; i<=3; i++)
	{
		pid = fork();
		switch(pid){
			case -1 ://Error
				printf("Error \n");
				return(1);
			case 0  ://Hijo
				for(int k=MAX; k>=1; k--){
					printf("H= %d \n", getpid());
				}
				//
				//
				//
			default ://Padre
					
		}
	}
return 0;

}
