import os

# Este programa itera a través de un número de procesos simulados, mostrando el PID del proceso actual y un contador.
# La cantidad de iteraciones y tabulaciones depende del identificador del proceso simulado.

def _execute_main():
    _num_processes = 5  # Número total de procesos simulados
    for _proc_id in range(1, _num_processes + 1):
        _simulate_process(_proc_id)

def _simulate_process(_pid):
    _counter = 0
    while _counter < _pid:
        for _ in range(_pid):
            print("\t", end="")  # Imprimir tabulaciones según el identificador del proceso
        print(f"<{os.getpid()}, {_counter}>")  # Mostrar PID real y contador
        _counter += 1

if __name__ == "__main__":
    _execute_main()
