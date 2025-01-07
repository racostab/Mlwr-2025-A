#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h> 

using namespace std;

class PipeHandler {
private:
    int fd[2];
    const char* buf;
    int tam;

public:
    PipeHandler(const char* buffer, int size) {
        buf = buffer;
        tam = size;
        if (pipe(fd) < 0) {
            cerr << "Error en la creación del pipe" << endl;
            exit(1);
        }
    }
    void handleChildProcess() {
        pid_t pid = fork();
        switch(pid) {
            case -1:
                cerr << "Error de creación del proceso hijo" << endl;
                exit(1);
            case 0:
                read(fd[0], const_cast<char*>(buf), tam);
                cout << "H= " << buf << endl;
                break;
            default:
                sleep(15);
                write(fd[1], buf, tam);
                cout << "P= " << buf << endl;
                wait(nullptr);
                break;
        }
    }
    ~PipeHandler() {
        close(fd[0]);
        close(fd[1]);
    }
};

int main() {
    const char* buffer = "abcde";
    int tam = 5;

    PipeHandler handler(buffer, tam);
    handler.handleChildProcess();
    return 0;
}
