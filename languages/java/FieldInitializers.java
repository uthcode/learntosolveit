/**
 * Example 38 - Field Initializers and Initializer Blocks
 */
public class FieldInitializers {

    static double[] ps = new double[6];
    static double[] ps2 = new double[6];

    static {
        double sum = 0;
        for (int i = 0; i < ps.length; i++) {
            ps[i] = sum += Math.random();
        }
        for (int i = 0; i < ps2.length; i++) {
            ps2[i] /= sum;

        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < ps.length; i++) {
            System.out.println(ps[i]);
        }
         for (int i = 0; i < ps2.length; i++) {
            System.out.println(ps2[i]);
        }
    }
}
