#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>

class MessageQueue {
public:
    // Estructura para el mensaje
    struct mesg_buffer {
        long mesg_type;
        char mesg_text[100];
    };

    // Constructor
    MessageQueue(const std::string& file_name, int proj_id) {
        // Creamos una clave única a partir de un archivo y un identificador de proyecto
        key = ftok(file_name.c_str(), proj_id);
        if (key == -1) {
            std::cerr << "Error creando clave." << std::endl;
            exit(1);
        }

        // Creamos la cola de mensajes
        msgid = msgget(key, 0666 | IPC_CREAT);
        if (msgid == -1) {
            std::cerr << "Error creando la cola de mensajes." << std::endl;
            exit(1);
        }
    }

    // Destructor
    ~MessageQueue() {
        // Eliminamos la cola de mensajes
        if (msgctl(msgid, IPC_RMID, NULL) == -1) {
            std::cerr << "Error eliminando la cola de mensajes." << std::endl;
        }
    }

    // Recibir un mensaje
    std::string receiveMessage() {
        mesg_buffer message;
        if (msgrcv(msgid, &message, sizeof(message), 1, 0) == -1) {
            std::cerr << "Error recibiendo el mensaje." << std::endl;
            exit(1);
        }
        return std::string(message.mesg_text);
    }

private:
    key_t key;   // Clave de la cola de mensajes
    int msgid;   // ID de la cola de mensajes
};

int main() {
    // Creamos una instancia de MessageQueue para interactuar con la cola de mensajes
    MessageQueue mq("progfile", 65);

    // Recibimos el mensaje de la cola de mensajes
    std::string received_message = mq.receiveMessage();
    
    // Mostramos el mensaje recibido
    std::cout << "Data Received is: " << received_message << std::endl;

    return 0;
}
