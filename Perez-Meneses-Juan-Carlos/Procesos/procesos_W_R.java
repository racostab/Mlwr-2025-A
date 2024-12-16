import java.io.*;
import java.util.concurrent.locks.*;

public class ArchivoConcurrente {
    private static final String FILENAME = "contador.txt";
    private static final ReentrantLock lock = new ReentrantLock();

    public static void actualizarArchivo(String columna, int delay) {
        while (true) {
            lock.lock();
            try (RandomAccessFile file = new RandomAccessFile(FILENAME, "rw")) {
                // Leer el valor del archivo
                int contador = Integer.parseInt(file.readLine().trim());

                if (columna.equals("1")) {
                    System.out.printf("Columna 1 | Ri = %-5d%n", contador);
                } else {
                    System.out.printf("\t\tColumna 2 | Ri = %-5d%n", contador);
                }

                // Incrementar el valor leído
                contador++;
                file.seek(0);
                file.writeBytes(contador + "\n");

                if (columna.equals("1")) {
                    System.out.printf("Columna 1 | Wi = %-5d%n", contador);
                } else {
                    System.out.printf("\t\tColumna 2 | Wi = %-5d%n", contador);
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                lock.unlock();
            }
            try {
                Thread.sleep(delay * 1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) throws IOException {
        // Crear el archivo inicial con valor 0
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(FILENAME))) {
            writer.write("0\n");
        }

        // Crear hilos
        Thread thread1 = new Thread(() -> actualizarArchivo("1", 2));
        Thread thread2 = new Thread(() -> actualizarArchivo("2", 3));

        thread1.start();
        thread2.start();
    }
}
