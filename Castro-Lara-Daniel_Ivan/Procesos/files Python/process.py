"""
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en Python que imprime el valor de args
"""

import sys

def main():
    argc = len(sys.argv) - 1  # Número de argumentos (sin contar el nombre del script)
    print(f"argc = {argc}")
    
    if argc == 0:
        return 0
    else:
        return argc

if __name__ == "__main__":
    result = main()
    sys.exit(result)

"""
    1.- python <archivo>.py
    No se necesita compilar porque es interpretado.
"""
