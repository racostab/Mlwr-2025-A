import os

# Este programa crea un pipe utilizando os.pipe() y escribe repetidamente un byte en su extremo de escritura.
# Muestra el número de iteraciones realizadas hasta que el usuario interrumpe la ejecución con Ctrl+C.

def _pipe_writer():
    _fd_read, _fd_write = os.pipe()  # Crear el pipe
    _buffer = b"a"  # Buffer de tipo bytes para escribir en el pipe

    try:
        _counter = 1
        while True:
            os.write(_fd_write, _buffer)  # Escribir un byte en el extremo de escritura del pipe
            print(_counter, end=" ", flush=True)
            _counter += 1
    except KeyboardInterrupt:
        print("\nEjecución detenida por el usuario.")
    finally:
        # Cerrar los extremos del pipe
        os.close(_fd_read)
        os.close(_fd_write)

if __name__ == "__main__":
    _pipe_writer()

