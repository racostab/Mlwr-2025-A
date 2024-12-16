public class ContextSwitch {
    public static void main(String[] args) {
        int N = 5; // Cambia el valor de N según lo necesites
        for (int i = 1; i <= N; i++) {
            int pid = i;
            new Thread(() -> proceso(pid)).start();
        }
    }

    public static void proceso(int pid) {
        int i = 1;
        while (true) {
            StringBuilder tabs = new StringBuilder();
            for (int t = 0; t <= pid; t++) {
                tabs.append("\t");
            }
            System.out.println(tabs + "<" + Thread.currentThread().getId() + "," + i++ + ">");
            try {
                Thread.sleep(500); // Espera 0.5 segundos para evitar saturación
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                break;
            }
        }
    }
}
