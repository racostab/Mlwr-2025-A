#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message; // Aquí se define correctamente la variable 'message'

int main() {
    key_t key;
    int msgid;

    // Generar una clave única
    key = ftok("progfile", 65); 
    // Crear una cola de mensajes y obtener su identificador
    msgid = msgget(key, 0666 | IPC_CREAT); 

    message.mesg_type = 1; // Asignar el tipo de mensaje

    printf("Write Data: ");
    // Leer el mensaje del usuario
    fgets(message.mesg_text, sizeof(message.mesg_text), stdin); 

    // Enviar el mensaje a la cola
    msgsnd(msgid, &message, sizeof(message), 0); 
    printf("Data sent is: %s\n", message.mesg_text);

    return 0;
}
