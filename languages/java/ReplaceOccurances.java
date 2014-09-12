/**
 * Example 101 - Replace Occurrences of a Character by a String.
 */
class ReplaceOccurances{

    static String replaceCharString(String s, char c1, String s2) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < s.length(); i++)
            if (s.charAt(i) == c1)
                res.append(s2);
            else
                res.append(s.charAt(i));
        return res.toString();
    }
    public static void main(String[] args) {
        System.out.println(replaceCharString("1-650-516-X", 'X', "MATH"));
    }
}
