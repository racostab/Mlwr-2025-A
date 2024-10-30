/*
Programa que recibe argumentos y muestra cuantos son
*/
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    cout << "argc = " << argc << endl;

    if (argc == 1) {
        return 0;
    } else {
        return argc;
    }
}
