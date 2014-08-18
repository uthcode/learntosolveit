/**
 * Example 21 - Creating a String from Character Array
 */
public class StringFromCharArray {

    static String replaceCharChar(String s, char c1, char c2) {
        char[] res = new char[s.length()];
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == c1)
                res[i] = c2;
            else
                res[i] = s.charAt(i);
        }
        return new String(res);
    }

    public static void main(String[] args) {

        String s = "fun";
        char c1 = 'f';
        char c2 = 'p';
        System.out.println(replaceCharChar(s, c1, c2));

    }
}
