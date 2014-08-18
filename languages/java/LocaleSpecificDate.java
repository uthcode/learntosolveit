import java.util.Date;
import java.util.Locale;

/**
 * Example 16 - Locale Specific Formatting of Dates and Times
 */

public class LocaleSpecificDate {
    public static void main(String[] args) {
        Date now = new Date();
        System.out.format("%tc%n", now); // default locale
        System.out.format(Locale.US, "%tc%n", now); // en_US locale
        System.out.format(Locale.GERMANY, "%tc%n", now); // en_DE locale
    }
}
