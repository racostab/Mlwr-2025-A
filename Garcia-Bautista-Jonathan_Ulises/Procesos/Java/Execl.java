import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Execl {
    public static void main(String[] args) {
        // Obtener el PID actual
        String pid = ProcessHandle.current().pid() + "";
        System.out.println("El pid actual es: " + pid);

        try {
            // Ejecutar el comando 'ps -fea'
            Process process = new ProcessBuilder("/usr/bin/ps", "-fea").start();

            // Capturar la salida del proceso
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;

            // Leer la salida línea por línea e imprimirla
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }

            // Esperar a que el proceso termine y obtener el código de salida
            int exitCode = process.waitFor();

            // Verificar si el comando falló
            if (exitCode != 0) {
                System.out.println("El comando falló con el código de salida: " + exitCode);
                System.out.println("Nunca me verán");
            }

        } catch (IOException | InterruptedException e) {
            // Capturar excepciones y mostrar mensaje
            System.out.println("Error al ejecutar el comando.");
            System.out.println("Nunca me verán");
            e.printStackTrace();
        }
    }
}
