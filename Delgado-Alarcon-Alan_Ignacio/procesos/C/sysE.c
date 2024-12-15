#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	printf("%d \n", getpid());
	pid_t my_pid = getpid();
	char pid_str[10];
	sprintf(pid_str, "%d", my_pid);
	//execl("/bin/ps","ps","-fea",(char *)0);
	execl("/usr/bin/pstree","pstree","-s", pid_str,(char *)0);
	printf("Nunca me veran...");
}
