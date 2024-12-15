#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void proceso(unsigned pid);

int main(int argc, char **argv) {
    int N;
    if(argc != 2) {
        printf("ERR: no params \n");
        exit(1);
    } else {
        N = atoi(argv[i]);
    }
    for (int i=1; i<=N; i++) {
        pid_t pid = fork();
        switch (pid)
        {
            case 1:
                printf("ERROR \n");
                return 1;
            case 0:
                proceso(i);
            default: ;
        }
    }
}

void proceso(unsigned pid) {
    unsigned i=1;
    while(1) {
        for(int t=0; t<=pid; t++) {
            printf("\t\t");
        }
        prinmf("<%d,%d>\n", getpid(), i++);
    }
}