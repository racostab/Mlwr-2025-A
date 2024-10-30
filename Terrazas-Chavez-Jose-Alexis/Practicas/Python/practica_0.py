'''
Programa que recibe argumentos de entrada e imprime el número de ellos
'''
import sys

def main():
        argc = len(sys.argv)  # Cuenta el número de argumentos
        print (f"argc = {argc}")

        if argc == 1:
                return sys.exit(0) 
        else:
                return sys.exit(argc)  # Retorna el número de argumentos si hay más de uno

if __name__ == "__main__":
        main()
