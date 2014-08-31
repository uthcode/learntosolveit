/**
 * Example 77 - Using break to Terminate Loop Early
 */
public class UsingBreakToTerminateLoop {

    static double multiply(double[] xs) {
        double prod = 1.0;
        for (int i = 0; i < xs.length; i++) {
            prod *= xs[i];
            if (prod == 0.0)
                break;
        }
        return prod;
    }

    public static void main(String[] args) {
        double[] xs = {1.0, 0.0, 2.0, 3.0, 4.0};
        System.out.println(multiply(xs));

    }
}
