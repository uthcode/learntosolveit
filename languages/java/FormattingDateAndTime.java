import java.util.GregorianCalendar;

/**
 * Example 15 - Formatting Dates and Times As Strings
 */
public class FormattingDateAndTime {

    public static void main(String[] args) {
        GregorianCalendar date = new GregorianCalendar(2014, 8, 18, 14, 25, 40);
        System.out.format("%1$tF %1$tR%n", date);
    }
}
