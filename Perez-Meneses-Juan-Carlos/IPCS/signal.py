import signal
import os
import time

# Definir el manejador de señales
def handler(sig, frame):
    print("¡Señal recibida!")

# Asignar el manejador a la señal SIGUSR1
signal.signal(signal.SIGUSR1, handler)

print(f"PID del proceso: {os.getpid()}")
print("Esperando señal SIGUSR1...")

# Bucle infinito para mantener el programa corriendo
while True:
    time.sleep(1)

