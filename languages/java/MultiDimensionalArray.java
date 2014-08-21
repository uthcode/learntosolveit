/**
 * Example 22 - Creating a Multidimentional Arrays
 */
class MultiDimensionalArray {

    public static void main(String[] args) {
        double[][] r1 = new double[3][2];
        double[][] r2 = new double[3][];

        for (int i = 0; i < 3; i++) {
            r2[i] = new double[2];
        }

        double[][] t1 = new double[3][];

        for (int i = 0; i < 3; i++) {
            t1[i] = new double[i+1];
        }

        double[][] t2 = { {0.0}, {0.0, 0.0}, {0.0, 0.0, 0.0}};
        double[][] t3 = new double[][]{ {0.0}, {0.0, 0.0}, {0.0, 0.0, 0.0}};

        System.out.println(t2[0][0]);
        System.out.println(t2[1].length);
        System.out.println(t3[2].length);
    }
}
