#import <Foundation/Foundation.h>
#import <unistd.h>
#import <sys/types.h>
#import <pthread.h>


void *thread(void *arg);

int main(int argc, const char * argv[]) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread, NULL);
    while (1) {
        @autoreleasepool {
            NSLog(@"\n\tP = %d", getpid());
        }
        sleep(1);
    }
    [pool release];

    return 0;
}
void *thread(void *arg) {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    while (1) {
        @autoreleasepool {
            NSLog(@"\t\t\t H = %d", getpid());
        }
        sleep(1);
    }
    [pool release];
    return NULL;
}
