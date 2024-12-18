public class ProcessCountdown {
    static final int MAX = 5; // Countdown limit

    public static void main(String[] args) {
        for (int i = 1; i <= 3; i++) {
            Thread child = new Thread(() -> {
                for (int k = MAX; k >= 1; k--) {
                    System.out.println("Child Thread [" + Thread.currentThread().getId() + "]: Countdown = " + k);
                    try {
                        Thread.sleep(500); // Sleep for 500ms
                    } catch (InterruptedException e) {
                        System.err.println("Error: Sleep interrupted");
                    }
                }
            });
            child.start();
        }
    }
}
