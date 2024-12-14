"""
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en Python 
"""

import os

def main():
    # Crear un pipe
    fd_read, fd_write = os.pipe()
    buf = b"a"  # El buffer debe ser de tipo bytes

    try:
        i = 1
        while True:
            os.write(fd_write, buf)  # Escribir un byte en el extremo de escritura del pipe
            print(i, end=' ', flush=True)
            i += 1
    except KeyboardInterrupt:
        print("\nEjecución interrumpida por el usuario")
    finally:
        # Cerrar los extremos del pipe
        os.close(fd_read)
        os.close(fd_write)

if __name__ == "__main__":
    main()

"""
    1.- python <archivo>.py
    No se necesita compilar porque es interpretado.
"""
