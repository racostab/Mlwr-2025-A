#include <stdio.h>      // For printf
#include <sys/ipc.h>    // For IPC key generation
#include <sys/msg.h>    // For message queue operations
#include <string.h>     // For string operations
#include <stdlib.h>     // For exit()

// Structure for message queue
struct msg_buffer {
    long msg_type;         // Message type
    char msg_text[100];    // Message text
} message;

int main() {
    key_t key;
    int msgid;

    // Generate a unique key
    key = ftok("progfile", 65);
    if (key == -1) {
        perror("Error generating key");
        exit(1);
    }

    // Create or connect to the message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Error creating message queue");
        exit(1);
    }

    // Receive the message (type 1)
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) {
        perror("Error receiving message");
        exit(1);
    }

    // Print the received message
    printf("Data received is: %s\n", message.msg_text);

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("Error removing message queue");
        exit(1);
    }

    return 0;
}
