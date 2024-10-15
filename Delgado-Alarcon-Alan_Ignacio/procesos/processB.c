#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void hijo(){
    sleep(2);
    printf("quien?... te pregunto");
}

void padre(){
    sleep(10);
    system("ps");
    printf("hijos de...");
}

int main(){
    for(int i=1; i<=3; i++){
        pid_t pid = fork();
        switch(pid) {
            case 1:
                printf("ERROR\n");
                return 1;
            case 0:
                hijo();
                exit(1);
            default:
                padre();
        }
    }
}