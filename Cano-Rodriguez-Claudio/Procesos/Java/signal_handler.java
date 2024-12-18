public class SignalHandler {
    public static void main(String[] args) {
        System.out.println("Esperando señales... (usa Ctrl+C para detener)");

        // Add a shutdown hook to simulate signal handling
        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            System.out.println("Señal recibida!");
        }));

        // Keep the program running
        while (true) {
            try {
                Thread.sleep(1000); // Sleep to reduce CPU usage
            } catch (InterruptedException e) {
                System.err.println("Error: " + e.getMessage());
            }
        }
    }
}
