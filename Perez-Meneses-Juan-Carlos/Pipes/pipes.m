#import <Foundation/Foundation.h>
#include <unistd.h>
#include <stdio.h>

@interface PipeWriter : NSObject {
    int fd[2]; // Descriptores de archivo para la tubería
    const char *buf;
}

- (instancetype)initWithBuffer:(const char *)buffer;
- (void)writeToPipe;
- (void)closePipe;

@end

@implementation PipeWriter

- (instancetype)initWithBuffer:(const char *)buffer {
    self = [super init];
    if (self) {
        buf = buffer;
        if (pipe(fd) < 0) {
            NSLog(@"Error en la creación del pipe");
            exit(1);
        }
    }
    return self;
}

- (void)writeToPipe {
    int i = 0;
    while (1) {
        write(fd[1], buf, 1); // Escribe un byte en la tubería
        printf("%d ", i++);
        fflush(stdout); // Asegura que el buffer de salida se imprima
    }
}

- (void)closePipe {
    close(fd[0]);
    close(fd[1]);
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        const char *buffer = "a";
        PipeWriter *writer = [[PipeWriter alloc] initWithBuffer:buffer];
        [writer writeToPipe];
        [writer closePipe];
    }
    return 0;
}

