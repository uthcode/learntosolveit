/**
 * Example 78 - Using continue to start a New Iteration (Not Recommended)
 */
public class UsingContinueStartIteration {

    static boolean substring1(String query, String target) {
        nextposition:
        for (int j = 0; j <= target.length() - query.length(); j++) {
            for (int k = 0; k < query.length(); k++)
                if (target.charAt(j + k) != query.charAt(k))
                    continue nextposition;
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(substring1("sub", "substring"));
        System.out.println(substring1("super", "substring"));
    }
}
