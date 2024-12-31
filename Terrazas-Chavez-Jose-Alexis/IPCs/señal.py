import signal
import os
import time

# Definir el manejador de la señal
def handler(signum, frame):     #signum- numero entero frame es el numero de la señal
    print("¡Señal recibida!")

# Asignar el manejador a una señal específica (por ejemplo, SIGUSR1)
signal.signal(signal.SIGUSR1, handler)

# Imprimir el PID del proceso para poder enviarle señales
print(f"PID del proceso: {os.getpid()}")

# Mantener el programa corriendo para esperar señales
while True:
    time.sleep(1)  # Pausar para no consumir demasiados recursos
