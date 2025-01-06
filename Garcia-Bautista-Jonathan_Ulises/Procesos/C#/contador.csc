using System;
using System.IO;
using System.Threading;
using System.Diagnostics;

class Program
{
    // Mutex para sincronizar el acceso al archivo
    private static readonly Mutex mutex = new Mutex();

    // Método que ejecuta el proceso hijo
    static void Proceso(int id)
    {
        int i = 0;

        while (true)
        {
            try
            {
                // Adquirir el bloqueo
                mutex.WaitOne();

                // Abrir el archivo en modo lectura/escritura
                using (StreamReader reader = new StreamReader("contador.txt"))
                {
                    // Leer el valor actual del contador
                    string value = reader.ReadLine();
                    if (!int.TryParse(value, out i))
                    {
                        Console.WriteLine("Error al leer el valor del contador.");
                        break;
                    }
                }

                // Incrementar el contador
                i++;

                // Volver a escribir el valor incrementado en el archivo
                using (StreamWriter writer = new StreamWriter("contador.txt"))
                {
                    writer.WriteLine(i);
                }

                // Liberar el bloqueo
                mutex.ReleaseMutex();

                // Imprimir el valor actualizado del contador
                Console.WriteLine($"<PID: {Process.GetCurrentProcess().Id}, Valor del contador: {i}>");

                // Esperar 100 milisegundos (simulando el usleep)
                Thread.Sleep(100);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
                break;
            }
        }
    }

    static void Main(string[] args)
    {
        // Crear el archivo e inicializar el contador si no existe
        try
        {
            if (!File.Exists("contador.txt"))
            {
                using (StreamWriter writer = new StreamWriter("contador.txt"))
                {
                    writer.WriteLine(0); // Inicializar contador a 0
                }
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error al crear el archivo: " + ex.Message);
            return;
        }

        // Crear los procesos hijos
        for (int i = 0; i < 2; i++)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo
            {
                FileName = System.Reflection.Assembly.GetEntryAssembly().Location,
                Arguments = i.ToString(),
                UseShellExecute = false,
                CreateNoWindow = true
            };

            // Iniciar el proceso hijo
            Process p = Process.Start(startInfo);
            p.WaitForExit(); // Esperar que el proceso termine antes de continuar
        }

        // Mostrar mensaje de fin del proceso principal
        Console.WriteLine("Proceso principal terminado.");
    }
}
