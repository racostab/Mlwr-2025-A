#import <Foundation/Foundation.h>
#import <unistd.h>
#import <stdlib.h>

pid_t pid;
int MAX = 10;
int k;

void hijo();  // Declaración de la función hijo
void padre(); // Declaración de la función padre

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        for (int i = 1; i <= 3; i++) {
            pid = fork();
            switch (pid) {
                case -1:
                    NSLog(@"Error\n");
                    return 1;
                case 0:
                    hijo();  // Llamada a la función hijo
                    exit(1);
                default:
                    padre(); // Llamada a la función padre
                    sleep(10);
            }
        }
    }
    return 0;
}

void hijo() {
    NSLog(@"Soy el hijo con PID %d", getpid());
}

void padre() {
    NSLog(@"Soy el padre con PID %d", getpid());
}
