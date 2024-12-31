import sysv_ipc

# Crear la clave para identificar la cola de mensajes
key = 1234  # La clave debe coincidir con la utilizada por el escritor

try:
    # Conectarse a la cola de mensajes existente
    message_queue = sysv_ipc.MessageQueue(key)
    print("Conexión a la cola de mensajes establecida.")

    # Leer el mensaje desde la cola
    message, msg_type = message_queue.receive(type=1)  # Leer mensajes del tipo 1
    print(f"Mensaje recibido (tipo {msg_type}): {message.decode()}")

    # Opcional: destruir la cola de mensajes una vez leída (si ya no se usará)
    message_queue.remove()
    print("Cola de mensajes eliminada.")

except sysv_ipc.ExistentialError:
    print("La cola de mensajes no existe. Asegúrate de que el escritor la haya creado primero.")

