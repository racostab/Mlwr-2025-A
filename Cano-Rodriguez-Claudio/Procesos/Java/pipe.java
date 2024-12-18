import java.io.*;

public class PipeMinimal {
    public static void main(String[] args) throws IOException {
        PipedInputStream in = new PipedInputStream();
        PipedOutputStream out = new PipedOutputStream(in);

        Thread child = new Thread(() -> {
            try {
                byte[] buffer = new byte[5];
                in.read(buffer);
                System.out.println("H: " + new String(buffer));
            } catch (IOException e) {
                e.printStackTrace();
            }
        });

        child.start();

        // Parent process (main thread)
        String msg = "abcde";
        out.write(msg.getBytes());
        System.out.println("P: " + msg);
    }
}
