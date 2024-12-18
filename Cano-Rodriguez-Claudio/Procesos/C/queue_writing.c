#include <stdio.h>      // For printf, fgets
#include <sys/ipc.h>    // For ftok
#include <sys/msg.h>    // For msgget, msgsnd
#include <string.h>     // For string handling

// Define the message structure
struct msg_buffer {
    long msg_type;          // Message type
    char msg_text[100];     // Message content
} message;

int main() {
    key_t key;       // Key to identify the message queue
    int msgid;       // Message queue ID

    // Generate a unique key using ftok
    key = ftok("progfile", 65);
    if (key == -1) {
        perror("Error generating key");
        return 1;
    }

    // Create the message queue or connect to it
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Error creating message queue");
        return 1;
    }

    // Set the message type
    message.msg_type = 1;

    // Prompt user for input and read the message
    printf("Write data >> ");
    if (fgets(message.msg_text, sizeof(message.msg_text), stdin) == NULL) {
        perror("Error reading input");
        return 1;
    }

    // Remove the newline character from input
    message.msg_text[strcspn(message.msg_text, "\n")] = '\0';

    // Send the message to the queue
    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("Error sending message");
        return 1;
    }

    // Print confirmation
    printf("Data sent is: %s\n", message.msg_text);

    return 0;
}
