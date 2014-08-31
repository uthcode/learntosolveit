/**
 * Example 79 - Using break to Exit a Labeled Statement Block (Not Recommended)
 */
public class UsingBreakToExitLabeled {
    static boolean substring2(String query, String target) {
        for (int j = 0; j <= target.length() - query.length(); j++)
            thisposition: {
                for (int k = 0; k < query.length(); k++)
                    if (target.charAt(j+k) != query.charAt(k))
                        break thisposition;
                return true;
            }
        return false;
    }
    public static void main(String[] args) {
        System.out.println(substring2("sub", "substring"));
        System.out.println(substring2("super", "substring"));
    }
}
