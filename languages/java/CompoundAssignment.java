/**
 * Example 50 - Compound Assignment Operators
 */
class CompoundAssignment {

    static double multiply(double[] xs) {
        double prod = 1.0;
        for (int i = 0; i < xs.length; i++) {
            prod *= xs[i];
        }
        return prod;
    }

    public static void main(String[] args) {
        double[] xs = {1.0, 2.0, 3.0};
        System.out.println(multiply(xs));
    }
}
