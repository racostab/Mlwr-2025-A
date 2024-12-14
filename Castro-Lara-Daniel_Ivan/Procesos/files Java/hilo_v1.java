/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en lenguaje Java
*/

public class hilo_v1 extends Thread
{
    public void run() {
        for (int i = 0; i < 3; i++) {
            printMsg();
        }
    }

    public void printMsg() {
        Thread h = Thread.currentThread();
        String name = h.getName();
        System.out.println("Metodo = " + name);
    }

    public static void main(String[] args) {
        hilo_v1 h = new hilo_v1();
        h.setName("Ejecutando hilo");
        System.out.println("Antes de iniciar, estado del hilo = " + h.isAlive());
        h.start();
        System.out.println("Despues de start(), estado del hilo = " + h.isAlive());

        for (int i = 0; 1 < 3; i++) {
            h.printMsg();
        }
        System.out.println("Terminando el programa, estado del hilo = " + h.isAlive());
    }
}

/* 
$ hilo_v1.java
*/
