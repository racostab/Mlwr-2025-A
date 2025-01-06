using System;
using System.Diagnostics;

class Program
{
    static void Main()
    {
        int pid = Process.GetCurrentProcess().Id;
        Console.WriteLine("El pid actual es: " + pid);
        Process.Start("/usr/bin/ps", "-fea");
        Console.WriteLine("Nunca me verán");
    }
}
