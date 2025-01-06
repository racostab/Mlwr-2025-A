#include <iostream>
#include <unistd.h>
#include <sys/types.h>

/*
    g++ -o execl execl.cpp
*/
using namespace std;

class Process {
public:
    void showCurrentPidAndRunPs() {
        pid_t pid = getpid();
        cout << "El pid actual es: " << pid << endl << endl;
        execl("/usr/bin/ps", "ps", "-fea", (char *)NULL);
        cout << "Nunca me verán" << endl;
    }
};

int main() {
    Process process;
    process.showCurrentPidAndRunPs();
    return 0;
}
