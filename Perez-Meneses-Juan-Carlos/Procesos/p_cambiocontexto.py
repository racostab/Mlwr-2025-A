import os
import time

def proceso(pid):
    i = 1
    while True:
        print("\t" * pid + f"<{os.getpid()},{i}>")
        i += 1
        time.sleep(0.5)  # Espera 0.5 segundos para evitar saturación

def main():
    N = 5  # Cambia el valor de N según lo necesites
    for i in range(1, N + 1):
        pid = os.fork()
        if pid == 0:  # Proceso hijo
            proceso(i)
            os._exit(0)  # Terminar el proceso hijo

if __name__ == "__main__":
    main()
