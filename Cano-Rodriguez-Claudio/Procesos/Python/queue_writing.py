import sysv_ipc

# Generate a unique key
key = sysv_ipc.ftok("progfile", 65)

# Create a message queue
mq = sysv_ipc.MessageQueue(key, sysv_ipc.IPC_CREAT)

# Prompt user for input
message = input("Write data >> ")

# Send the message (message type = 1)
mq.send(message, type=1)

# Print the sent message
print(f"Data sent is: {message}")
