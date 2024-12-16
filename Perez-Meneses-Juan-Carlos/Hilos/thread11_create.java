public class HelloWorldThreads {
    private static final int NUM_THREADS = 5;

    public static void main(String[] args) {
        for (int t = 0; t < NUM_THREADS; t++) {
            final int threadId = t;
            System.out.println("In main: creating thread " + threadId);
            new Thread(() -> {
                System.out.println("Hello World! It's me, thread #" + threadId + "!");
            }).start();
        }
    }
}
