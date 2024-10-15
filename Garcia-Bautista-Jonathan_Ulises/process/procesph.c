#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int MAX = 10;

void hijo()
{
    sleep(1);
    printf("Adios mundo cruel \n");
/*    for(int k = MAX; k>=1; k--)
    {
        printf("H = %d\n", getpid());
        nanosleep(&ts, NULL);
    }
   return 0;
*/
}
void padre()
{
    sleep(5);
    system("ps");
    printf("Hijos de...\n");
}
int main()
{
    for(int i = 1; i <= 3; i++)
    {
        pid_t pid = fork();
        switch(pid)
        {
            case 1 :
                    printf("Error\n");
                    return 1;
            case 0 :
                    hijo();
                    exit(1);
            default:
                    padre();
        }
    }
    padre();
}
