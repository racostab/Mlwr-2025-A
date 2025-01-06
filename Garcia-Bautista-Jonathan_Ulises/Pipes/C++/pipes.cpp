#include <iostream>
#include <unistd.h>

using namespace std; 

class PipeWriter {
private:
    int fd[2]; 
    const char* buf; 

public:
        PipeWriter(const char* buffer) {
        buf = buffer;
        if (pipe(fd) < 0) {
            cerr << "Error en la creación del pipe" << endl;
            exit(1);
        }
    }
    void writeToPipe() {
        int i = 0;
        while (true) {
            write(fd[1], buf, 1);
            cout << i++ << " ";
            flush(cout);
        }
    }
    ~PipeWriter() {
        close(fd[0]);
        close(fd[1]);
    }
};

int main() {
    const char* buffer = "a";
    PipeWriter writer(buffer);
    writer.writeToPipe();
    return 0;
}
