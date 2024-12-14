"""
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en lenguaje Python sobre cambio de contexto de un proceso
"""

import os 

def main():
    N = 5  
    for i in range(1, N + 1):  
        proceso(i)  

def proceso(pid):
    t = 0
    while t < pid:
        for _ in range(pid):
            print("\t", end="")
        print(f"<{os.getpid()}, {t}>") 
        t += 1  

if __name__ == "__main__":
    main()

"""
    1.- python <archivo>.py
    No se necesita compilar porque es interpretado.
"""