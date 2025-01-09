import os

# Este programa reemplaza el proceso actual con otro proceso ejecutable, en este caso, "ls" con argumentos específicos.
# Es un equivalente al comportamiento de "execl" en sistemas basados en UNIX.

def execute_process():
    _exe_path = "/bin/ls"  # Ruta del ejecutable
    _exe_args = [_exe_path, "-l", "-a"]  # Argumentos para el ejecutable

    print("Antes de llamar a execl...")

    os.execl(_exe_path, *_exe_args)  # Reemplaza el proceso actual

    print("Esta línea no se imprimirá porque execl reemplaza el proceso actual.")

if __name__ == "__main__":
    execute_process()

