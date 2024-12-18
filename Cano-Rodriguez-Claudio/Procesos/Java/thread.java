public class ThreadExample {

    public static void main(String[] args) {
        // Child thread
        Thread childThread = new Thread(() -> {
            while (true) {
                System.out.println("\t\t\tH=" + ProcessHandle.current().pid());
            }
        });

        childThread.start(); // Start the child thread

        // Main thread
        while (true) {
            System.out.println("\tP=" + ProcessHandle.current().pid());
        }
    }
}
