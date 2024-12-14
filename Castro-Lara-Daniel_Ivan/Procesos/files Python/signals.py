"""
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en Python 
"""

import signal
import time

# Manejador de la señal
def handler(signum, frame):
    print("¡Señal recibida!")

def main():
    # Configurar el manejador para la señal SIGUSR1
    signal.signal(signal.SIGUSR1, handler)
    print("Esperando señales... (envía SIGUSR1 para probar)")

    # Bucle infinito para mantener el programa en ejecución
    while True:
        time.sleep(1)  # Dormir para evitar el uso excesivo de CPU

if __name__ == "__main__":
    main()


"""
    1.- python <archivo>.py
    No se necesita compilar porque es interpretado.
"""
