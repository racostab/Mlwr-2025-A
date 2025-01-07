#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid = getpid();
	printf("El pid actual es: %d\n\n",pid);
	execl("/usr/bin/ps", "ps","-fea" , (char *)NULL);
	{
		printf("Nunca me veran");
	}
	return 0;
}
