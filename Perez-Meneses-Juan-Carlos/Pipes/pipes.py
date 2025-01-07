import os
import sys

class PipeWriter:
    def __init__(self, buffer):
        self.buf = buffer.encode('utf-8')  # Convertir el buffer a bytes
        self.fd_read, self.fd_write = os.pipe()  # Crear la tubería

    def write_to_pipe(self):
        i = 0
        try:
            while True:
                os.write(self.fd_write, self.buf)  # Escribir un byte en la tubería
                print(i, end=" ", flush=True)  # Mostrar el contador
                i += 1
        except KeyboardInterrupt:
            print("\nPrograma detenido manualmente.")

    def close_pipe(self):
        os.close(self.fd_read)
        os.close(self.fd_write)


if __name__ == "__main__":
    buffer = "a"
    writer = PipeWriter(buffer)
    try:
        writer.write_to_pipe()
    finally:
        writer.close_pipe()

