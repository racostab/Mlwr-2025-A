import os

# Este programa utiliza fork() para crear un proceso hijo y un bloque match-case para manejar diferentes casos.
# Imprime el PID del padre y del hijo en sus respectivas ramas.

def _process_manager():
    _pid = os.fork()  # Crear proceso hijo

    match _pid:  # Manejo del resultado del fork
        case -1:  # Error en la creación del proceso
            print("Error en fork.")
        case 0:  # Código ejecutado en el proceso hijo
            print("Proceso hijo: PID = %d, PPID = %d" % (os.getpid(), os.getppid()))
        case _:  # Código ejecutado en el proceso padre
            print("Proceso padre: PID = {}, PPID = {}".format(os.getpid(), os.getppid()))

if __name__ == "__main__":
    _process_manager()

