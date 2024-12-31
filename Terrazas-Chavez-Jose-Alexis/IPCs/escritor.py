import sysv_ipc

# Crear la clave para identificar la cola de mensajes
key = 1234  # La clave debe coincidir con la utilizada por el lector

try:
    # Crear o conectarse a la cola de mensajes existente
    message_queue = sysv_ipc.MessageQueue(key, sysv_ipc.IPC_CREAT)
    print("Cola de mensajes creada o conectada con éxito.")

    # Enviar un mensaje
    message = "¡Hola desde el escritor! ESCRITOR".encode()  # Convertir el mensaje a bytes
    message_queue.send(message, type=1)  # Tipo de mensaje: 1
    print(f"Mensaje enviado: {message.decode()}")

except sysv_ipc.ExistentialError:
    print("Error: No se pudo crear o conectar a la cola de mensajes.")

