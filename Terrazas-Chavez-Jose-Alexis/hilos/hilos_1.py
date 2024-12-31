'''
Programa que ejecuta hilo en 5 iteraciones, una vez terminada esa tarea se
termina el proceso del hilo
'''

import threading
import time

# Definimos una función que será ejecutada en un hilo
def tarea():
    for i in range(5):
        print(f"Hilo en ejecución: iteración {i + 1}")
        time.sleep(1)  # Pausa de 1 segundo

# Creamos un hilo que ejecuta la función `tarea`
hilo = threading.Thread(target=tarea)

# Iniciamos el hilo
hilo.start()

# Esperamos a que el hilo termine
hilo.join()

print("El hilo ha terminado.")



