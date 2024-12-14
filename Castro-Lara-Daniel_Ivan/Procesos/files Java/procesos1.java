/*
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en lenguaje Java
*/

import java.util.concurrent.TimeUnit;

public class ForkSimulation {
    private static final int MAX = 5;

    public static void main(String[] args) {
        final long SLEEP_TIME_MS = 500; // 500 milisegundos

        for (int i = 1; i <= 3; i++) {
            Thread thread = new Thread(() -> {
                for (int k = MAX; k >= 1; k--) {
                    System.out.println("H= " + Thread.currentThread().getId());
                    try {
                        TimeUnit.MILLISECONDS.sleep(SLEEP_TIME_MS);
                    } catch (InterruptedException e) {
                        System.err.println("Sleep interrupted: " + e.getMessage());
                    }
                }
            });

            thread.start();
        }
    }
}

/* 
$ hilo_v1.java
*/
