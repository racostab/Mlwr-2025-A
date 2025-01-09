import sys

# Este programa cuenta el número de argumentos pasados al ejecutarlo desde la línea de comandos (sin incluir el nombre del script).
# Devuelve 0 si no se pasa ningún argumento y, de lo contrario, retorna el número de argumentos.

def _argument_counter():
    _arg_total = len(sys.argv) - 1  # Calcular el número de argumentos
    print(f"Número de argumentos: {_arg_total}")
    
    return 0 if _arg_total == 0 else _arg_total

if __name__ == "__main__":
    _exit_code = _argument_counter()
    sys.exit(_exit_code)
