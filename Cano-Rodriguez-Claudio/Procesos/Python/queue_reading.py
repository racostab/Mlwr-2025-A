import sysv_ipc

# Generate the key
key = sysv_ipc.ftok("progfile", 65)

# Create or get the message queue
mq = sysv_ipc.MessageQueue(key, sysv_ipc.IPC_CREAT)

# Receive the message
message, _ = mq.receive(type=1)
print(f"Data received is: {message.decode()}")

# Remove the message queue
mq.remove()
