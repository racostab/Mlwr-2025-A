'''
Programa que crea dos procesos en funciones, un proceso padre y un porceso hijo 
creado por el padre, ambos muestran su PID y una vez que terminen los procesos
ejecutara el comando ps
'''


import os
import time

def proceso_hijo(max_time):
    """Función que ejecuta el código del proceso hijo."""
    print(f"Soy el proceso hijo con PID {os.getpid()}")
    for i in range(max_time):
        print(f"Proceso hijo esperando {i + 1} segundos con un PID de {os.getpid()}")
        time.sleep(2)  # Se dormira dos segundo en cada iteración para que se mantenga 10 segundos
    print("Adios mundo cruel...")

def proceso_padre(pid_hijo):
    """Función que ejecuta el código del proceso padre."""
    print(f"He creado un proceso hijo con PID {pid_hijo}")
    time.sleep(10) #espera el doble de tiempo para que se ejecute el proceso padre
    print("El proceso padre ha terminado")
    os.system("ps") #ejecución del comando ps

def main():
    max_time = 5  # Variable que define el tiempo máximo mayor que 5

    print(f"Proceso principal con PID {os.getpid()}")

    # Realizar el fork para 
    pid = os.fork()
  
    if pid == 0:
        # Ejecutar la función del proceso hijo
        proceso_hijo(max_time)
    else:
        # Ejecutar la función del proceso padre
        proceso_padre(pid)

if __name__ == "__main__":
    main()

  
