#include <stdio.h>

int main(int argc, char **argv){
    printf("argc= %d \n", argc);
    if(argc == 1) {
        return 0;
    } else {
        return argc;
    }
}