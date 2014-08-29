/**
 * Example 51 - Conditional Expression
 */
public class ConditionalExpression {

    static double absolute(double x) {
        return (x >= 0 ? x : -x);
    }

    public static void main(String[] args) {
        Double x = 5.12;
        System.out.println(absolute(x));
    }

}
