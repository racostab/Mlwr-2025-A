/*
 * Compilación      javac thread_1.java
 * Ejecución        java thread_1
 */
import java.lang.management.ManagementFactory;

public class thread_1 {

    // Método que será ejecutado por el hilo secundario
    public static void thread() {
        while (true) {
            System.out.println("\t\t\t H = " + getPid());
            try {
                Thread.sleep(1000);  // Sleep por 1 segundo
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    // Método que obtiene el PID del proceso actual
    public static String getPid() {
        String processName = ManagementFactory.getRuntimeMXBean().getName();
        return processName.split("@")[0]; // Obtener solo el PID (antes de la '@')
    }

    public static void main(String[] args) {
        // Crear y ejecutar el hilo
        Thread thread1 = new Thread(() -> thread());
        thread1.start();

        // El hilo principal ejecuta el siguiente código
        while (true) {
            System.out.println("\n\tP = " + getPid());
            try {
                Thread.sleep(1000);  // Sleep por 1 segundo
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
