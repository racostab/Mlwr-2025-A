import sys

# Este programa imprime "Hello Mundo", cuenta los argumentos recibidos en la línea de comandos y devuelve su cantidad.
# Si no se pasan argumentos, finaliza con un código de salida 0.

print("hola mundo")

def process_arguments():
    _arg_count = len(sys.argv) - 1  # Contar los argumentos, excluyendo el nombre del script
    print(f"Cantidad de argumentos: {_arg_count}")
    
    if _arg_count == 0:
        return 0  # Sin argumentos, retornar 0
    return _arg_count  # Retornar número de argumentos

if __name__ == "__main__":
    _exit_code = process_arguments()
    sys.exit(_exit_code)

