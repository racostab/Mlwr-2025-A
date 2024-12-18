import signal
import time

# Signal handler function
def handler(signum, frame):
    print("Señal recibida!")

# Assign the handler to SIGUSR1
signal.signal(signal.SIGUSR1, handler)
print("Esperando señales... (envía SIGUSR1 para probar)")

# Infinite loop to keep the program running
while True:
    time.sleep(1)  # Reduce CPU usage
