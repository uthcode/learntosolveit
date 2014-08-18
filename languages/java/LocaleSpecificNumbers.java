import java.util.Locale;

/**
 * Example 17 - Locale Specific formatting of Numbers
 */
public class LocaleSpecificNumbers {
    public static void main(String[] args) {
        double d = 1234567.9;
        System.out.format(Locale.US, "%,.2f%n", d); // en_US locale
        System.out.format(Locale.GERMANY, "%,.2f%n", d); // de_DE locale
        System.out.format(Locale.FRANCE, "%,.2f%n", d); // fr_FR locale
    }
}
