'''
Programa que implementa un sistema de comunicación entre procesos utilizando colas (Queue) 
de la librería multiprocessing en Python. Se basa en el modelo productor-consumidor, donde:

      Un proceso (productor) genera datos y los coloca en una cola.
      Otro proceso (consumidor) toma esos datos de la cola y los procesa.
'''

from multiprocessing import Process, Queue

def productor(queue):
    for i in range(5):
        print(f"Productor envía: {i}")
        queue.put(i)  # Enviar mensaje a la cola

def consumidor(queue):
    while True:
        mensaje = queue.get()  # Leer mensaje de la cola
        print(f"Consumidor recibe: {mensaje}")
        if mensaje == "FIN":
            break

if __name__ == "__main__":
    queue = Queue()  # Crear una cola de mensajes

    # Crear procesos
    p1 = Process(target=productor, args=(queue,))
    p2 = Process(target=consumidor, args=(queue,))

    # Iniciar procesos
    p1.start()
    p2.start()

    # Esperar que termine el productor
    p1.join()

    # Enviar mensaje de finalización
    queue.put("FIN")
