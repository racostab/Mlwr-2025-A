/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en lenguaje Java
*/

public class SignalHandlerSimulation {
    
    // Método que simula un manejador de señales
    public static void handler() {
        System.out.println("¡Señal recibida!");
    }

    public static void main(String[] args) {
        // Crear un hilo que simule la espera de una señal
        Thread mainThread = new Thread(() -> {
            try {
                System.out.println("Esperando señal...");
                // El hilo principal espera de manera indefinida
                synchronized (Thread.currentThread()) {
                    Thread.currentThread().wait();
                }
            } catch (InterruptedException e) {
                // Simula la recepción de una señal
                handler();
            }
        });

        mainThread.start();

        // Simular el envío de una señal después de 3 segundos
        Thread signalThread = new Thread(() -> {
            try {
                Thread.sleep(3000); // Espera 3 segundos antes de enviar la señal
                System.out.println("Enviando señal...");
                mainThread.interrupt(); // Interrumpe el hilo principal para simular la señal
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        signalThread.start();
    }
}

/* 
$ hilo_v1.java
*/
