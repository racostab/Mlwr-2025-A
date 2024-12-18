#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define the structure for the message queue
struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key;
    int msgid;

    // Generate a unique key
    key = ftok("progfile", 65);

    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    message.msg_type = 1; // Set message type

    // Prompt user for input
    printf("Write data >> ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);

    // Send the message to the queue
    msgsnd(msgid, &message, sizeof(message), 0);

    // Print the sent message
    printf("Data sent is: %s\n", message.msg_text);

    return 0;
}
