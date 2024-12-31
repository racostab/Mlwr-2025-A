'''
Porgrama que implementa comunicación inter-procesos usando un pipe en Python,
con el propósito de demostrar cómo los procesos pueden intercambiar información 
mediante un canal de comunicación unidireccional.
'''
import os
import time

def writer(pipe_write):
    """Proceso escritor: escribe datos periódicamente en el pipe."""
    for i in range(1, 6):  # Escribe 5 veces
        message = f"Mensaje {i}\n".encode()
        os.write(pipe_write, message)
        print(f"Escritor: escribió '{message.decode().strip()}'")
        time.sleep(2)  # Espera 2 segundos entre escrituras
    os.close(pipe_write)  # Cierra el extremo de escritura del pipe

def reader(pipe_read):
    """Proceso lector: lee datos del pipe. Se bloquea si el pipe está vacío."""
    while True:
        try:
            # Lee del pipe
            data = os.read(pipe_read, 1024)  # Intenta leer hasta 1024 bytes
            if not data:  # Si no hay más datos, rompe el bucle
                break
            print(f"Lector: leyó '{data.decode().strip()}'")
        except OSError:
            print("Error al leer del pipe.")
            break
    os.close(pipe_read)  # Cierra el extremo de lectura del pipe


def main():
    # Crear el pipe
    r_fd, w_fd = os.pipe()

    # Crear procesos para lectura y escritura
    pid = os.fork()  # Dividir en dos procesos

    if pid == 0:  # Proceso hijo: lector
        os.close(w_fd)  # Cerrar extremo de escritura en el lector
        reader(r_fd)
    else:  # Proceso padre: escritor
        os.close(r_fd)  # Cerrar extremo de lectura en el escritor
        writer(w_fd)
        os.wait()  # Esperar a que el hijo termine

if __name__ == "__main__":
    main()
