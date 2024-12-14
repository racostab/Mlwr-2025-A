/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en lenguaje Java
*/

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class PipeExample {
    public static void main(String[] args) {
        PipedOutputStream outputStream = new PipedOutputStream();
        PipedInputStream inputStream = new PipedInputStream();

        try {
            // Conectar el PipedInputStream al PipedOutputStream
            inputStream.connect(outputStream);

            // Crear un hilo que escriba en el pipe
            Thread writerThread = new Thread(() -> {
                int i = 1;
                String data = "a";
                try {
                    while (true) {
                        outputStream.write(data.getBytes());
                        System.out.print(i + " ");
                        System.out.flush();
                        i++;
                    }
                } catch (IOException e) {
                    System.out.println("\nError al escribir en el pipe: " + e.getMessage());
                }
            });

            // Iniciar el hilo de escritura
            writerThread.start();

        } catch (IOException e) {
            System.out.println("Error en la creación del pipe: " + e.getMessage());
        }
    }
}

/* 
$ pipes.java
*/
