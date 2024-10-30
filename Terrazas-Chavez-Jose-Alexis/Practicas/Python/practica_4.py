'''
Programa que crea tres porcesos y realiza un cambio de contexto cada que uno termina,
el cambio de contexto lo determina el quantum.
Si se quiere detener proceso se tiene que colocar el comando ps -fea en otra terminar 
y una vez ubicado el PID matarlo con el el comando $kill <PID>
'''
import os
import time

def proceso(pid):
    i = 1
    while True:
        for t in range(pid + 1):
            print("\t", end="")  # Imprime una tabulación
        print(f"<{os.getpid()},{i}>")  # Imprime el PID actual y el valor de i
        i += 1
        #time.sleep(1)  # Espera un segundo antes de la siguiente iteración para simular el tiempo de ejecución y se muestre despacio

def main():
    N = 3  # N para crear más o menos procesos
    for i in range(1, N + 1):  # Bucle para crear N procesos
        pid = os.fork()  # Crea un nuevo proceso

        if pid == 0:  # Si es el proceso hijo
            proceso(i)  # Llama a la función "proceso" con el número del proceso
            os._exit(0)  # Sale del proceso hijo después de la ejecución
        else:
            continue  # El proceso padre continúa creando otros hijos

if __name__ == "__main__":
    main()
