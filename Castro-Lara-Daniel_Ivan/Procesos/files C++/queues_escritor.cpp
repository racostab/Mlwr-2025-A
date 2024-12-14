/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en C++
	$ gcc -o procesos_v0_param procesos_v0_param.cpp
*/

#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <cstdlib>

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
        std::cerr << "Error al generar la clave" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Crear una cola de mensajes
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        std::cerr << "Error al crear la cola de mensajes" << std::endl;
        exit(EXIT_FAILURE);
    }

    message.mesg_type = 1;

    // Leer la entrada del usuario de forma segura
    std::cout << "Write Data: ";
    std::string input;
    std::getline(std::cin, input);

    // Copiar el contenido a mesg_text (asegurando no desbordar el búfer)
    strncpy(message.mesg_text, input.c_str(), sizeof(message.mesg_text) - 1);
    message.mesg_text[sizeof(message.mesg_text) - 1] = '\0'; // Asegurar la terminación nula

    // Enviar el mensaje a la cola
    if (msgsnd(msgid, &message, sizeof(message.mesg_text), 0) == -1) {
        std::cerr << "Error al enviar el mensaje" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Data sent is: " << message.mesg_text << std::endl;

    return 0;
}

