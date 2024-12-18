import java.io.*;
import java.util.Scanner;

public class SignalR {
    public static void main(String[] args) {
        File file = new File("message.txt");

        try {
            // Simulate receiving the message
            Scanner reader = new Scanner(file);
            String message = reader.nextLine();
            System.out.println("Data received is: " + message);
            reader.close();

            // Simulate removing the queue (delete the file)
            if (file.delete()) {
                System.out.println("Message queue removed successfully.");
            } else {
                System.err.println("Error removing the message queue.");
            }
        } catch (IOException e) {
            System.err.println("Error reading message: " + e.getMessage());
        }
    }
}
