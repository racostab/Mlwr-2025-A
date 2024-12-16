using System;
using System.Threading;

class Program
{
    static void Proceso(int pid)
    {
        int i = 1;
        while (true)
        {
            Console.WriteLine(new string('\t', pid) + $"<{Thread.CurrentThread.ManagedThreadId},{i++}>");
            Thread.Sleep(500); // Espera 0.5 segundos para evitar saturación
        }
    }

    static void Main(string[] args)
    {
        int N = 5; // Cambia el valor de N según lo necesites
        for (int i = 1; i <= N; i++)
        {
            int pid = i;
            Thread thread = new Thread(() => Proceso(pid));
            thread.Start();
        }
    }
}
