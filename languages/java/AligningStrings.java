/**
 * Example 13 - Aligning Strings Using String.format Method
 */
public class AligningStrings {
    public static void main(String[] args) {
        String res = String.format("|%1$s|%1$15s|%1$-15s|", "Uthcode");
        System.out.println(res);
    }
}
