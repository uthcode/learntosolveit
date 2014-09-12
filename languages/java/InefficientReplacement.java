/**
 * Example 102 - Inefficient Replacing Occurances of a Character by a String.
 */
class InefficientReplacement {
    static void replaceCharString(StringBuilder sb, char c1, String s2) {
        int i = 0;
        /** Inefficient */
        while (i < sb.length()) {
            if (sb.charAt(i) == c1) {
                sb.replace(i, i+1, s2);
                i += s2.length();
            } else
                i += 1;
        }
    }

    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        String s = "1-650-516-X";
        sb.append(s);
        replaceCharString(sb, 'X', "MATH");
        System.out.println(sb.toString());
    }
}
