/**
 * Example 47 - Bitwise Operators and Shift Operators
 */
public class BitwiseOperators {

    static void println4(int n) {
        for (int i = 3; i >=0 ; i--) {
            System.out.println(n>>i & 1);
        }
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        int a = 0x3;
        int b = 0x5;
        println4(a);
        println4(b);
        println4(~a);
        println4(~b);
        println4(a & b);
        println4(a ^ b);
        println4(a | b);
    }
}
