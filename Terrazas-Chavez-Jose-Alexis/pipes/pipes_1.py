import os

def main():
    # Crear el pipe
    r_fd, w_fd = os.pipe()  # r_fd es el descriptor de lectura, w_fd es el de escritura
    buf = b"a"  # Byte a escribir en el pipe
    count = 0

    try:
        while True:
            # Escribir en el pipe
            os.write(w_fd, buf)
            count += 1
            print(f"Escrito: {count} bytes")
    except BrokenPipeError:
        print(f"Error: el pipe está lleno después de {count} bytes")
    except OSError as e:
        print(f"Error al escribir en el pipe: {e}. Bytes escritos: {count}")
    finally:
        # Cerrar los descriptores del pipe
        os.close(r_fd)
        os.close(w_fd)

if __name__ == "__main__":
    main()
