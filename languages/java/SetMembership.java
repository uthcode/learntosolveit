import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Example 122 - Set Membership Test Using HashSet or Binary Search
 */

class SetMembership {
    final static String[] keywordarray =
            {"abstract", "assert", "boolean", "break", "byte", "while"};
    final static Set<String> keywords = new HashSet<String>(Arrays.asList(keywordarray));
    static boolean isKeyword1(String id) { return keywords.contains(id);}
    static boolean isKeyword2(String id) { return Arrays.binarySearch(keywordarray, id) >= 0;}

    public static void main(String[] args) {
        System.out.println(isKeyword1("break"));
        System.out.println(isKeyword2("breakdance"));
    }

}
