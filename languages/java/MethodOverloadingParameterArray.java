/**
 * Example 35 - Method Overloading and Parameter Array
 */
public class MethodOverloadingParameterArray {

    static int max(int x1, int... xr) {
        int res = x1;
        for(int x: xr) {
            res = max(res, x);
        }
        return res;
    }

    static int max(int x, int y) {
        return x > y ? x: y;
    }

    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50, 60, 70};
        int maximum = max(30, arr);
        System.out.println(maximum);

    }
}
