/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en lenguaje Java
*/

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class MessageQueueReceiver {
    // Crear una cola de mensajes con capacidad para 10 mensajes
    private static final BlockingQueue<String> messageQueue = new ArrayBlockingQueue<>(10);

    public static void main(String[] args) {
        // Simulación de recepción del mensaje
        Thread receiverThread = new Thread(() -> {
            try {
                System.out.println("Waiting for message...");
                String receivedMessage = messageQueue.take();  // Bloquea hasta recibir un mensaje
                System.out.println("Data Received is: " + receivedMessage);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.out.println("Receiver interrupted: " + e.getMessage());
            }
        });

        receiverThread.start();

        // Simulamos que se envía un mensaje a la cola
        Thread senderThread = new Thread(() -> {
            try {
                Thread.sleep(2000);  // Espera 2 segundos antes de enviar el mensaje
                messageQueue.put("Hello from sender!");
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.out.println("Sender interrupted: " + e.getMessage());
            }
        });

        senderThread.start();

        try {
            // Esperar a que ambos hilos terminen
            senderThread.join();
            receiverThread.join();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            System.out.println("Main thread interrupted: " + e.getMessage());
        }
    }
}
