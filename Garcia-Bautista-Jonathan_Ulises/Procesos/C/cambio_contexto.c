/*
	gcc -o cambio_contexto cambio_contexto.c	
*/
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>

void proceso(unsigned pid)
{
	unsigned i = 1;
		while(1)
			{
				for(int t = 0 ; t <= pid ; t++)
				{
					printf("\t\t");
				}
				printf("<%d,%d>\n", getpid(), i++);
				usleep(10000);
			}
}

int main (int argc, char **argv)
{
    if (argc != 2) {
        printf("Uso: %s <numero de procesos>\n", argv[0]);
        return 1;
    }

    int num_procesos = atoi(argv[1]);  // Convertimos el argumento a entero

    if (num_procesos <= 0) {
        printf("El número de procesos debe ser un número entero positivo.\n");
        return 1;
    }

	pid_t pid = 0;
	for(int i=0; i< num_procesos; i++)
	{
		pid = fork();
		sleep(1);
		switch(pid){
			case -1 ://Error
				printf("Error \n");
				return(1);
			case 0  ://Proceso
				proceso(i);
			default ://Padre
		}
	}
}
