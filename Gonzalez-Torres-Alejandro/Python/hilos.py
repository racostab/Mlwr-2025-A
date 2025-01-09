import threading
import os
import time

# Este programa utiliza un hilo secundario que imprime el PID del proceso en un bucle infinito,
# mientras el hilo principal realiza la misma acción de manera concurrente.

# Función para ejecutar en el hilo secundario
def _worker_thread():
    while True:
        print(f"\t\t\tHilo PID={os.getpid()}")
        time.sleep(0.5)  # Pausa para reducir el uso excesivo de CPU

def _main_thread():
    try:
        # Creación y inicio del hilo secundario
        _thread_instance = threading.Thread(target=_worker_thread)
        _thread_instance.start()
    except Exception as _error:
        print("Error al crear el hilo:", _error)
        return

    # Bucle infinito en el hilo principal
    while True:
        print(f"\tProceso principal PID={os.getpid()}")
        time.sleep(0.5)  # Pausa para evitar un consumo excesivo de CPU

if __name__ == "__main__":
    _main_thread()
