import java.io.*;
import java.nio.channels.*;
import java.util.concurrent.*;

public class Contador {

    public static void proceso(int pid) {
        int i = 0;
        RandomAccessFile file = null;
        FileChannel channel = null;
        
        try {
            while (true) {
                file = new RandomAccessFile("contador.txt", "rw");
                channel = file.getChannel();
                FileLock lock = channel.lock();
                file.seek(0);
                i = file.readInt();
                i++;
                file.seek(0);
                file.writeInt(i);
                lock.release();
                Thread.sleep(100);
                
                System.out.printf("<PID: %d, Valor del contador: %d>\n", pid, i);
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        } finally {
            try {
                if (channel != null) channel.close();
                if (file != null) file.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        try (RandomAccessFile file = new RandomAccessFile("contador.txt", "rw")) {
            file.writeInt(0);
        } catch (IOException e) {
            System.err.println("Error al crear el archivo");
            e.printStackTrace();
            return;
        }
        ExecutorService executor = Executors.newFixedThreadPool(2);

        for (int i = 0; i < 2; i++) {
            final int pid = i;
            executor.submit(() -> proceso(pid));
        }
        executor.shutdown();
        try {
            if (!executor.awaitTermination(1, TimeUnit.MINUTES)) {
                System.err.println("Los hilos no terminaron en el tiempo esperado.");
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
