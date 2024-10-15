#import <Foundation/Foundation.h>
#import <unistd.h>
#import <stdlib.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSLog(@"argc = %d", argc - 1);
        
        if (argc == 1) {
            return 0;
        } else {
            return argc;
        }
    }
}
