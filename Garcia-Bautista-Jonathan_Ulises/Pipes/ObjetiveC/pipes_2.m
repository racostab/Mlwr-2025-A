#import <Foundation/Foundation.h>
#include <unistd.h>
#include <stdlib.h>

/*
    gcc `gnustep-config --objc-flags` -o pipes_2 pipes_2.m `gnustep-config --base-libs` -L/path/to/gnustep/libs
*/

int main(int argc, const char * argv[]) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

    int error, fd[2], pid, tam = 5;
    char *buf = "abcde";

    error = pipe(fd);
    if (error < 0) {
        NSLog(@"Error en la creación del pipe");
        [pool release];
        return 1;
    }

    pid = fork();
    switch(pid) {
        case -1:
            NSLog(@"Error de creación");
            exit(1);
            break;

        case 0:
            // Proceso hijo
            read(fd[0], buf, tam);
            NSLog(@"H= %s", buf);
            break;

        default:
            // Proceso padre
            sleep(15);
            write(fd[1], buf, tam);
            NSLog(@"P= %s", buf);
            break;
    }

    [pool release];
    return 0;
}
