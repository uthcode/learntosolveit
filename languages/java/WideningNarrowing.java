/**
 * Example 48 - Widening, Narrowing and Truncation in Assignments
 */
class WideningNarrowing {
    public static void main(String[] args) {
        double d;
        d = 12;
        byte b1 = 123; // Narrowing conversion from int to byte
        byte b2;
        b2 = 123 + 1;
        b2 = (byte) (b1 + 1);
        int x = 0;
        x += 1.5;
    }

}
