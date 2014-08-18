/**
 * Example 20 - Using an Initialized Array
 */
public class InitializedArray {
    static int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    static boolean checkdate(int mth, int day) {
        return (mth >= 1) && (mth <= 12) && (day >= 1) && (day <= days[mth-1]);
    }

    public static void main(String[] args) {
        System.out.println(checkdate(2, 30));
        System.out.println(checkdate(4, 40));
        System.out.println(checkdate(6,31));
        System.out.println(checkdate(7,31));
    }
}
