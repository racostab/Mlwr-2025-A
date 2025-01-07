import java.io.*;

public class PipesExample {
    public static void main(String[] args) {
        try {
            // Crear los pipes
            PipedInputStream inputStream = new PipedInputStream();
            PipedOutputStream outputStream = new PipedOutputStream(inputStream);

            String buf = "abcde";
            int tam = buf.length();

            // Crear un proceso hijo usando Threads (simula fork)
            Thread childProcess = new Thread(() -> {
                try {
                    byte[] buffer = new byte[tam];
                    inputStream.read(buffer, 0, tam);
                    System.out.println("H= " + new String(buffer));
                } catch (IOException e) {
                    System.out.println("Error en el proceso hijo: " + e.getMessage());
                }
            });

            childProcess.start(); // Iniciar el proceso hijo

            // Proceso padre
            Thread.sleep(15000); // Simula sleep(15)
            outputStream.write(buf.getBytes(), 0, tam);
            System.out.println("P= " + buf);

            // Cerrar recursos
            outputStream.close();
            inputStream.close();
            childProcess.join(); // Esperar a que el hijo termine

        } catch (IOException | InterruptedException e) {
            System.out.println("Error general: " + e.getMessage());
        }
    }
}
