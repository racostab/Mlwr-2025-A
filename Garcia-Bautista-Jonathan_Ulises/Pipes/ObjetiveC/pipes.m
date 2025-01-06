#import <Foundation/Foundation.h>
#import <unistd.h>
#import <sys/types.h>

int main(int argc, const char * argv[]) {
    
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];  
    
    pid_t pid = getpid();
    NSLog(@"El pid actual es: %d", pid);
    
    // Ejecuta el comando ps con los parámetros -fea
    execl("/usr/bin/ps", "ps", "-fea", (char *)NULL);
    
    // Esta línea nunca se verá
    NSLog(@"Nunca me verán");
    
    // Liberar el pool
    [pool release];
    return 0;
}
