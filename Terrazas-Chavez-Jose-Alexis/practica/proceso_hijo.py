import os
import time

def main():
    max_time = 5  #Tiempo máximo mayor que 5

    print(f"Proceso principal con PID {os.getpid()}")

    # Realizar el fork
    pid = os.fork()

    if pid == 0:
        # Ejecuta en el proceso hijo
        print(f"Soy el proceso hijo con PID {os.getpid()}")
        for i in range(max_time):
            print(f"Proceso hijo esperando... {i + 1} segundos")
            time.sleep(1)
        print("El proceso hijo ha terminado")
    else:
        pass

if __name__ == "__main__":
    main()
