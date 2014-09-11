/**
 * Example 98 - Generating Gaussian Pseudo Random Numbers
 */
class GaussianPseudoRandom {
    static int N = 100; // 100 Random numbers

    public static void main(String[] args) {
        for (int i = 0; i < N; i+=2) {
            double x1 = Math.random(), x2 = Math.random();
            print(Math.sqrt(-2 * Math.log(x1)) * Math.cos(2 * Math.PI * x2));
            print(Math.sqrt(-2 * Math.log(x1)) * Math.sin(2 * Math.PI * x2));
        }
    }
    static void print(double d) {
        System.out.print(d + " ");
    }
}
