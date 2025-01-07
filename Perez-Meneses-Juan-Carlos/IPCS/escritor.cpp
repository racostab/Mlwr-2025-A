#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>

class MessageQueue {
private:
    key_t key;
    int msgid;
    struct mesg_buffer {
        long mesg_type;
        char mesg_text[100];
    } message;

public:
    MessageQueue(const std::string& filepath, int proj_id) {
        // Generamos la clave para la cola de mensajes
        key = ftok(filepath.c_str(), proj_id);
        if (key == -1) {
            std::cerr << "Error al generar la clave con ftok" << std::endl;
            exit(1);
        }

        // Creamos la cola de mensajes
        msgid = msgget(key, 0666 | IPC_CREAT);
        if (msgid == -1) {
            std::cerr << "Error al obtener la cola de mensajes" << std::endl;
            exit(1);
        }
    }

    void sendMessage() {
        // Establecemos el tipo de mensaje
        message.mesg_type = 1;
        
        // Pedimos al usuario que ingrese el mensaje
        std::cout << "Write Data: ";
        std::cin.getline(message.mesg_text, sizeof(message.mesg_text));

        // Enviamos el mensaje a la cola de mensajes
        if (msgsnd(msgid, &message, sizeof(message), 0) == -1) {
            std::cerr << "Error al enviar el mensaje" << std::endl;
            exit(1);
        }

        // Imprimimos el mensaje enviado
        std::cout << "Data sent: " << message.mesg_text << std::endl;
    }

    ~MessageQueue() {
        // Liberamos la cola de mensajes cuando ya no sea necesaria
        if (msgctl(msgid, IPC_RMID, NULL) == -1) {
            std::cerr << "Error al eliminar la cola de mensajes" << std::endl;
        }
    }
};

int main() {
    // Creamos un objeto MessageQueue y enviamos el mensaje
    MessageQueue mq("progfile", 65);
    mq.sendMessage();

    return 0;
}
