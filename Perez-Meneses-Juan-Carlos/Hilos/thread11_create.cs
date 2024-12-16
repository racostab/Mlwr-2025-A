using System;
using System.Threading;

class HelloWorldThreads
{
    private const int NUM_THREADS = 5;

    static void PrintHello(object threadId)
    {
        Console.WriteLine($"Hello World! It's me, thread #{threadId}!");
    }

    static void Main(string[] args)
    {
        for (int t = 0; t < NUM_THREADS; t++)
        {
            Console.WriteLine($"In main: creating thread {t}");
            Thread thread = new Thread(PrintHello);
            thread.Start(t);
        }
    }
}
