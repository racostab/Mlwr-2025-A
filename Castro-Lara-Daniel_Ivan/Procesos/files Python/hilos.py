"""
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en Python 
"""

import threading
import os
import time

# Función para el hilo secundario
def thread():
    while True:
        print(f"\t\t\tH={os.getpid()}")
        time.sleep(0.5)  # Pausa para evitar un consumo excesivo de CPU

def main():
    try:
        # Crear el hilo
        thread_obj = threading.Thread(target=thread)
        thread_obj.start()
    except Exception as e:
        print("Error en la creación del hilo:", e)
        return

    # Bucle infinito en el hilo principal
    while True:
        print(f"\tP={os.getpid()}")
        time.sleep(0.5)  # Pausa para evitar un consumo excesivo de CPU

if __name__ == "__main__":
    main()

"""
    1.- python <archivo>.py
    No se necesita compilar porque es interpretado.
"""
