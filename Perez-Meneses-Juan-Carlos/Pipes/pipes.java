import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

class PipeWriter {
    private PipedInputStream inputStream;
    private PipedOutputStream outputStream;
    private String buffer;

    public PipeWriter(String buffer) {
        this.buffer = buffer;
        try {
            this.inputStream = new PipedInputStream();
            this.outputStream = new PipedOutputStream(inputStream);
        } catch (IOException e) {
            System.err.println("Error al crear la tubería: " + e.getMessage());
            System.exit(1);
        }
    }

    public void writeToPipe() {
        int i = 0;
        try {
            while (true) {
                outputStream.write(buffer.getBytes());
                System.out.print(i++ + " ");
                System.out.flush();
            }
        } catch (IOException e) {
            System.err.println("Error al escribir en la tubería: " + e.getMessage());
        }
    }

    public void closePipe() {
        try {
            inputStream.close();
            outputStream.close();
        } catch (IOException e) {
            System.err.println("Error al cerrar la tubería: " + e.getMessage());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        String buffer = "a";
        PipeWriter writer = new PipeWriter(buffer);
        try {
            writer.writeToPipe();
        } finally {
            writer.closePipe();
        }
    }
}

