#Ejecución Python thread_1.py
import threading
import os
import time

# Función que ejecutará el hilo secundario
def thread():
    while True:
        print(f"\n\t P = {os.getpid()}")
        time.sleep(1)

# Función principal
def main():
    # Crear el hilo
    thread1 = threading.Thread(target=thread)
    
    # Iniciar el hilo
    thread1.start()

    while True:
        print(f"\t\t\t H = {os.getpid()}")
        time.sleep(1)

if __name__ == "__main__":
    main()
