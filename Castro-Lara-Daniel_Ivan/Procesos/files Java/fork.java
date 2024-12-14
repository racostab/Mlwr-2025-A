/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en lenguaje Java
*/

public class ForkSimulation {
    public static void main(String[] args) {
        // Crear un nuevo hilo para simular el proceso hijo
        Thread childThread = new Thread(() -> {
            System.out.println("Código del hijo");
        });

        try {
            // Iniciar el hilo (simulando el fork del hijo)
            childThread.start();

            // Esperar a que el hilo hijo termine antes de continuar
            childThread.join();

            // Simulando el código del padre
            System.out.println("Código del padre");
        } catch (Exception e) {
            System.out.println("Error de creación: " + e.getMessage());
        }
    }
}

/* 
$ hilo_v1.java
*/
