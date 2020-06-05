class thaphanoi {
    public static void main(String[] args) {
        String a = "A", b = "B", c = "C";
        int n = 5;
        Tower(n, a, b, c);
    }

    public static void Tower(int n, String a, String b, String c) {
        if (n == 1) {
            System.out.println(a + "----->" + c);
            return;
        }
        Tower(n - 1, a, c, b);
        Tower(1, a, b, c);
        Tower(n - 1, b, a, c);
    }
}