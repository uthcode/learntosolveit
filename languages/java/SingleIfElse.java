/**
 * Example 63 - Single If-else statement
 */
public class SingleIfElse {

    static double absolute(double x) {
        if (x >= 0)
            return x;
        else
            return -x;
    }

    public static void main(String[] args) {
        System.out.println(absolute(-2.10));
        System.out.println(absolute(3.14));
    }
}
