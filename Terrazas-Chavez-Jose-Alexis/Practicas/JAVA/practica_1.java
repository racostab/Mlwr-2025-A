public class Main {
    public static void main(String[] args) {
        int argc = args.length + 1; // Incluye el nombre del programa

        System.out.println("argc = " + argc);

        if (argc == 1) {
            System.exit(0);
        } else {
            System.exit(argc);
        }
    }
}

