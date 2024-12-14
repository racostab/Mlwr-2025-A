/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en lenguaje Java
*/

import java.util.Scanner;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class MessageQueueSimulation {
    // Crear una cola de mensajes con capacidad para 10 mensajes
    private static final BlockingQueue<String> messageQueue = new ArrayBlockingQueue<>(10);

    public static void main(String[] args) {
        // Hilo para enviar mensajes
        Thread senderThread = new Thread(() -> {
            try (Scanner scanner = new Scanner(System.in)) {
                System.out.print("Write Data: ");
                String message = scanner.nextLine();
                messageQueue.put(message);  // Enviar el mensaje a la cola
                System.out.println("Data sent is: " + message);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.out.println("Sender interrupted: " + e.getMessage());
            }
        });

        // Hilo para recibir mensajes
        Thread receiverThread = new Thread(() -> {
            try {
                String receivedMessage = messageQueue.take();  // Recibir el mensaje de la cola
                System.out.println("Received Message: " + receivedMessage);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.out.println("Receiver interrupted: " + e.getMessage());
            }
        });

        // Iniciar los hilos
        senderThread.start();
        receiverThread.start();

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
