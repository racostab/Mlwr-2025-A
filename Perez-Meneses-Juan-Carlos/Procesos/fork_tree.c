#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int p = 0;
	if (argc != 2)
	{  
        printf("Uso: %s <número de procesos a crear>\n", argv[0]);
        return 1; 
	}

	int num_procesos = atoi(argv[1]);

	if (num_procesos <= 0)
	{
        printf("Por favor ingresa un número positivo de procesos.\n");
        return 1;
	}
	printf("argc = %d\n",num_procesos);
	for(int i = 1 ; i <= num_procesos ; i++)
	{
		p++;
		if( fork() == -1)
		{
			printf("Error");
			return 0;
		}
	printf("Proceso %d: %d\n",p,getpid());
	}
	return 0;
}
