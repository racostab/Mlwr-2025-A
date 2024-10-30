'''
Programa que crea un proceso y seguidamente crealiza una sincronización de PID con el proceso
subsecuente, gracias al comando "execl" a través de la libreria "os" , esto quiere decir que el
proceso del padre lo obtendra la efecución del comando ps -f (se coloa f y no fea para visualizar
rapidamente el PID) por lo que en ese momento se detendrá el código de ejecución y no imprime el 
print despues de la sincronización ya que se cambio el proceso.
'''
import os
import time


def main():

    print(f"Proceso padre con PID {os.getpid()}")

    # Realizar el fork

    #comando = "/bin/ps"  # Ruta absoluta al binario
    #argumentos = ["ps", "-fea"]

    # Ejecutar el comando con execl. ¡Reemplaza el proceso actual!
    os.execl("/bin/ps", "ps","-f")
    print("nunca me veran")
if __name__ == "__main__":
    main()
