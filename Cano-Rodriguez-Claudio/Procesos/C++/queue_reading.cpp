#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <cstdlib>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    // Generate a unique key
    key = ftok("progfile", 65);
    if (key == -1) {
        std::cerr << "Error generating key!" << std::endl;
        return EXIT_FAILURE;
    }

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        std::cerr << "Error creating message queue!" << std::endl;
        return EXIT_FAILURE;
    }

    // Receive message
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    std::cout << "Data received is: " << message.msg_text << std::endl;

    // Remove message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
