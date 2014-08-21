/**
 * Example 46 - Logical Operators
 */
public class LogicalOperators {

    static int[] days = {31,28,31,30,31,30,31,31,30,31,30,31};

    static boolean validmonth(int mth, int day) {
        return (mth >= 1) && (mth <= 12) && (day >= 1) && (day <= days[mth-1]);
    }

    static boolean leapyear(int y) {
        return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
    }

    public static void main(String[] args) {
        System.out.println(validmonth(2,30));
        System.out.println(leapyear(2004));
    }

}
