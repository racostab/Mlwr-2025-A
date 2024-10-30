#include <iostream>
#include <unistd.h>  // Para execl() y getpid()

using namespace std;

int main() {
    cout << "Proceso padre con PID " << getpid() << endl;

    // Reemplaza el proceso actual con el comando 'ps -f'
    execl("/bin/ps", "ps", "-f", (char*)NULL);

    // Este mensaje nunca se mostrará
    cout << "Nunca me verán" << endl;

    return 0;
}
