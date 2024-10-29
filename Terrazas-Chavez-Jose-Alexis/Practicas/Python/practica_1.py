'''
Programa que crea un proceso padre y un proceso hijo, muestra ambos PID y 
pasado 5 segundos se elimina el proceso padre, por lo que detiene al proceso
hijo, indicando que el que manda es el proceso padre.
'''
import os
import time

def main():
    max_time = 5  
    print(f"Proceso principal con PID {os.getpid()}")

    # Realliza fork que crea un proceso
    pid = os.fork()

    if pid == 0:
        # Ejecuta en el proceso hijo
        print(f"Soy el proceso hijo con PID {os.getpid()}")
        for i in range(max_time):
            print(f"Proceso hijo esperando... {i + 1} segundos")
            time.sleep(1) #se duerme un minuto para que termine el proceso hijo al mismo tiempo que se detiene el proceso padre
        print("El proceso hijo ha terminado")
    else:
        pass

if __name__ == "__main__":
    main()

