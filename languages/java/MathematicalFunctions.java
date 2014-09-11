/**
 * Example 99 - Mathematical Functions: Infinites, NaNs and Special Cases
 */
class MathematicalFunctions {

    public static void main(String[] args) {
        System.out.println("Illegal Arguments and NaN results");
        System.out.println(Math.sqrt(-1));
        System.out.println(Math.log(-1));
        System.out.println(Math.pow(-1, 2.5));
        System.out.println(Math.acos(1.1));

        System.out.println("Infinite Results");
        System.out.println(Math.log(0));
        System.out.println(Math.pow(0, -1));
        System.out.println(Math.exp(1000.0));

        System.out.println("Infinite arguments");

        double infinity = Double.POSITIVE_INFINITY;
        System.out.println(Math.sqrt(infinity));
        System.out.println(Math.log(infinity));
        System.out.println(Math.exp(-infinity));

        System.out.println("Nan arguments and special cases");

        double nan = Math.log(-1);
        System.out.println(Math.sqrt(nan));
        System.out.println(Math.pow(nan, 0));
        System.out.println(Math.round(nan));
        System.out.println(Math.round(1E50));

    }
}
