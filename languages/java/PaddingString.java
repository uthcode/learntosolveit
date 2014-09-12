/**
 * Example 103 - Padding a String to a Given Width
 */
class PaddingString {
    static String padLeft(String s, int width) {
        StringBuilder res = new StringBuilder();
        for (int i = width - s.length(); i > 0; i--)
            res.append(' ');
        return res.append(s).toString();
    }

    public static void main(String[] args) {
        System.out.println("Signed-Off");
        System.out.println(padLeft("Signed-Off",20));
    }
}
