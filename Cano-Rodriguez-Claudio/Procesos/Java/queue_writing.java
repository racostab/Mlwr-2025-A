import java.io.*;
import java.util.Scanner;

public class SignalW {
    public static void main(String[] args) {
        File file = new File("message.txt");

        try (PrintWriter writer = new PrintWriter(new FileWriter(file))) {
            // Prompt user for input
            System.out.print("Write data >> ");
            Scanner scanner = new Scanner(System.in);
            String message = scanner.nextLine();

            // Write message to file
            writer.println(message);
            System.out.println("Data sent is: " + message);
        } catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }
    }
}
