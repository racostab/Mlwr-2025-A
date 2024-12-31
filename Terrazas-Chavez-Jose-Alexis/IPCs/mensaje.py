import sysv_ipc
key = 1234
mq = sysv_ipc.MessageQueue(key, sysv_ipc.IPC_CREAT)
mq.send("¡Hola desde el escritor!".encode(), type=1)
print("Mensaje enviado.")
