/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C++
	$ gcc -o procesos_v0_param procesos_v0_param.cpp
*/

#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>    // Para strerror()
#include <cstdlib>    // Para exit()

// Estructura del mensaje
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    // Generar una clave única
    key = ftok("progfile", 65);
    if (key == -1) {
        std::cerr << "Error al generar la clave: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    // Obtener la cola de mensajes
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        std::cerr << "Error al obtener la cola de mensajes: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    // Recibir el mensaje
    if (msgrcv(msgid, &message, sizeof(message.mesg_text), 1, 0) == -1) {
        std::cerr << "Error al recibir el mensaje: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    // Mostrar el mensaje recibido
    std::cout << "Data Received is: " << message.mesg_text << std::endl;

    // Eliminar la cola de mensajes
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        std::cerr << "Error al eliminar la cola de mensajes: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}

