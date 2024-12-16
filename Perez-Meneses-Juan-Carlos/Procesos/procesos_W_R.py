import os
import fcntl
import time

FILENAME = "contador.txt"

def actualizar_archivo(columna, delay):
    while True:
        try:
            with open(FILENAME, "r+") as file:
                # Bloquear el archivo para acceso exclusivo
                fcntl.flock(file, fcntl.LOCK_EX)

                # Leer el valor del archivo
                contador = int(file.read().strip())

                if columna == "1":
                    print(f"Columna 1 | Ri = {contador:<5}")
                else:
                    print(f"\t\tColumna 2 | Ri = {contador:<5}")

                # Incrementar el valor leído
                contador += 1

                # Rewind para sobrescribir desde el inicio
                file.seek(0)
                file.write(f"{contador}\n")
                file.truncate()

                if columna == "1":
                    print(f"Columna 1 | Wi = {contador:<5}")
                else:
                    print(f"\t\tColumna 2 | Wi = {contador:<5}")

                # Desbloquear el archivo automáticamente al cerrar el archivo
        except Exception as e:
            print(f"Error: {e}")
        time.sleep(delay)

if __name__ == "__main__":
    # Crear el archivo inicial con valor 0
    with open(FILENAME, "w") as file:
        file.write("0\n")

    pid1 = os.fork()
    if pid1 == 0:
        # Código para el primer proceso hijo
        actualizar_archivo("1", 2)
    else:
        pid2 = os.fork()
        if pid2 == 0:
            # Código para el segundo proceso hijo
            actualizar_archivo("2", 3)
        else:
            # Esperar a los procesos hijos (aunque este programa es infinito)
            os.wait()
            os.wait()
