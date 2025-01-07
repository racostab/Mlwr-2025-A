import signal
import time

# Definir el manejador de señales
def handler(sig, frame):
    print("¡Señal recibida!")

# Asignar el manejador a la señal SIGUSR1
signal.signal(signal.SIGUSR1, handler)

print("Esperando señal SIGUSR1... (Ctrl+C para salir)")

# Bucle infinito para mantener el programa corriendo
while True:
    time.sleep(1)
