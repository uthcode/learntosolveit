/**
 *  Declaring a Checked Exception Class
 */

class WeekdayException extends Exception {
    public WeekdayException(String wday) {
        super("Illegal weekday: " + wday);
    }
}

public class DeclaringCheckedException {

    static final String[] wdays =
            {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};


    static int wdayno4(String wday) throws WeekdayException {
        for (int i = 0; i < wdays.length; i++)
            if (wday.equals(wdays[i]))
                return i + 1;
        throw new WeekdayException(wday);
    }

    public static void main(String[] args) throws WeekdayException {
        System.out.println(wdayno4("Monday"));
        System.out.println(wdayno4("Sommar"));
    }
}
