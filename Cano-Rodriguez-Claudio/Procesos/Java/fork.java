import java.io.IOException;

public class ForkExample {
    public static void main(String[] args) {
        // Check if the program has the correct number of arguments
        if (args.length != 1) {
            System.err.println("ERR: no params");
            return;
        }

        int N = Integer.parseInt(args[0]); // Convert argument to integer

        // Loop to create N processes
        for (int i = 1; i <= N; i++) {
            try {
                Process process = new ProcessBuilder("java", "-version").start();
                System.out.println("Started Process PID: " + process.pid());
            } catch (IOException e) {
                System.err.println("ERROR: Failed to start process");
            }
        }
    }
}

