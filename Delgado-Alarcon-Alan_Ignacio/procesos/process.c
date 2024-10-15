#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

const int MAX = 5;

int main(){
    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 500000000;
    
    for(int i=1; i<=3; i++){
        pid_t pid = fork();
        switch(pid) {
            case 1:
                printf("ERROR\n");
                return 1;
            case 0:
                for(int k=MAX; k>=1; k--){
                    printf("H= %d \n", getpid());
                    nanosleep(&ts, NULL);
                }
                return 0;
            default: ;
        }
    }
}