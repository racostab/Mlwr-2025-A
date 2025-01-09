
import signal
import time

# Este programa configura un manejador para capturar señales SIGUSR1 y realiza una acción específica al recibir dicha señal.
# Mantiene el proceso en ejecución mediante un bucle infinito en espera de señales.

def __handle_signal(__sig, __frm):
    print("[ALERT] Señal recibida correctamente.")

def __event_loop():
    # Configuración del manejador para SIGUSR1
    signal.signal(signal.SIGUSR1, __handle_signal)
    print("[INFO] En espera de señales... (use SIGUSR1 para probar la interacción)")

    # Mantener el programa activo en un bucle continuo
    while True:
        time.sleep(1)  # Pausa para evitar uso excesivo de CPU

if __name__ == "__main__":
    __event_loop()

