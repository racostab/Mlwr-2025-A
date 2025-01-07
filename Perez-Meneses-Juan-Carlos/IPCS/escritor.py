import sysv_ipc

# Crear o conectar a una cola de mensajes
key = 0x65  # Clave equivalente a ftok("progfile", 65)

try:
    # Crear la cola de mensajes (0666 en octal = permisos de lectura/escritura para todos)
    mq = sysv_ipc.MessageQueue(key, sysv_ipc.IPC_CREAT, mode=0o666)
except sysv_ipc.ExistentialError:
    print("Error: No se pudo crear la cola de mensajes.")
    exit(1)

# Enviar un mensaje
message_type = 1  # Tipo de mensaje (equivalente a mesg_type)
message_text = input("Write Data: ")

# Enviar el mensaje
try:
    mq.send(message_text.encode('utf-8'), type=message_type)
    print(f"Data sent is: {message_text}")
except sysv_ipc.Error as e:
    print(f"Error al enviar el mensaje: {e}")

# Cerrar la cola de mensajes
mq.remove()
