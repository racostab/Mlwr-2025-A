Función rfork de Plan 9: La función rfork es fundamental en Plan 9 para crear procesos ligeros (similar a fork en UNIX). Su comportamiento depende de los flags que se pasen, permitiendo crear procesos con diferentes niveles de compartición (como espacio de memoria, archivos abiertos, etc.). Esto lo hace más flexible que fork.

Referencia científica:

Pike, R., Presotto, D., Thompson, K., Trickey, H. (1990). Plan 9 from Bell Labs. Communications of the ACM, 33(3), 28-43.

Función clone en Linux: clone es una llamada al sistema en Linux utilizada para crear procesos o hilos de usuario más eficientes. Es similar a fork pero permite compartir estructuras específicas como espacio de memoria o archivos. Es esencial para la implementación de hilos POSIX en Linux.

Referencia científica:

Love, R. (2010). Linux Kernel Development. Addison-Wesley Professional.

Estas implementaciones de manejo de procesos e hilos subrayan la evolución en la programación concurrente y destacan las diferencias arquitectónicas entre sistemas operativos.

Comparación: 
Ambas llamadas al sistema son potentes herramientas para crear procesos o hilos, pero rfork es exclusiva de Plan 9, mientras que clone es específica de Linux y su kernel.
