/**
 * Example 97 - Floating Point Factorial
 */
class FloatingPointFactorial {

    static double fact(int n) {
        double res = 0.0;
        for (int i = 1; i < n; i++)
            res += Math.log(i);
        return Math.exp(res);
    }

    public static void main(String[] args) {
        System.out.println(fact(10));
    }
}
