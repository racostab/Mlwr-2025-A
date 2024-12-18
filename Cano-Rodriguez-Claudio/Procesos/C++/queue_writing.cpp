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
        return 1;
    }

    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        std::cerr << "Error creating message queue!" << std::endl;
        return 1;
    }

    // Set message type and get input
    message.msg_type = 1;
    std::cout << "Write data >> ";
    std::cin.getline(message.msg_text, sizeof(message.msg_text));

    // Send the message
    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        std::cerr << "Error sending message!" << std::endl;
        return 1;
    }

    std::cout << "Data sent is: " << message.msg_text << std::endl;
    return 0;
}
